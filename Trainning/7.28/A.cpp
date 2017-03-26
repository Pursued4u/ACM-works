#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
#define CLR(a,x) memset(a,x,sizeof(a));
using namespace std;
#define N 100010
#define mod 1000000007
char s[N * 10], p[N];
int nextval[N];
int lens, lenp;
int a[N];
int dp[N];
int vis[N];
int op=0;
#define ll long long
void init()
{
    CLR(vis,0);
}
void getnext()
{
    int i = 0, j = -1;
    nextval[0] = -1;
    while(i != lenp)
    {
        if(j == -1 || s[i] == s[j])
            nextval[++i] = ++j;
        else
            j = nextval[j];
    }
}

void KMP()
{

    int i = 0, j = 0, cnt = 0;
    while(i != lens && j != lenp)
    {
        if(s[i] == p[j] || j == -1)
            ++i, ++j;
        else
            {
                j = nextval[j];
            }
        if(j == lenp)
        {
            j = nextval[j];
            vis[i]=1;


        }

    }

}

int main()
{
    int ncase;
    int len;
    int ans;
    scanf("%d", &ncase);
    int ca=1;
    while(ncase--)
    {

        op=0;
        init();
        scanf("%s%s", s, p);
        lens = strlen(s);
        lenp = strlen(p);
        getnext();
        KMP();
        ll ans=0;
        int i;
        for(i=1;i<=lens;i++)
            cout << vis[i] << " " ;
        cout << endl;
        for(i=1;i<=lenp;i++)
        {
            dp[i]=vis[i];
        }
        for(;i<=lens;i++)
        {
            if(vis[i])

            dp[i]=(dp[i-1]+dp[i-lenp]+1)%mod;
            else
            dp[i]=dp[i-1];
        }
        printf("Case #%d: ", ca++);
        cout <<dp[lens]+1<< endl;


    }
    return 0;
}
