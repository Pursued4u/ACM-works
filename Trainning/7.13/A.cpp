#include<bits/stdc++.h>
using namespace std;
#define maxn 20
const int inf = 9e7+2;
int s[maxn];
int a[maxn];
int b[maxn];
int c[maxn];
int d[maxn];
int e[maxn];
int op[maxn];
int main()
{
    int n,m;
    cin >> m >> n;
    for(int i=1; i<=m; i++)
    {
        scanf("%d",&s[i]);
        d[i]=s[i];
        e[i]=s[i];
    }
    for(int i=1; i<=n; i++)
        cin >> op[i];
    int cnt=1;
    int ans1=0;
    int ans2=0;
    int p=0;
    int opi=1;
    for(int i=1; i<=m; i++)
    {
        c[i]=cnt;
        p++;
        if(p>=op[opi])
        {
            p=0;
            opi++;
            if(cnt)
                cnt=0;
            else
                cnt=1;
        }
    }
    /*for(int i=1;i<=m;i++)
    {
        cout << c[i] << endl;
    }*/

    for(int i=1; i<=m; i++)
    {
        if(d[i]!=c[i])
        {
            int flag=0;
            for(int j=i; j<=m; j++)
            {
                if(d[j]==c[i])
                {
                    flag=1;
                    ans1+=j-i;
                    swap(d[i],d[j]);
                    break;
                }
            }
            if(!flag)
             ans1=inf;
        }
    }

    cnt=0;
    p=0;
    opi=1;
    for(int i=1; i<=m; i++)
    {
        c[i]=cnt;
        p++;
        if(p>=op[opi])
        {
            p=0;
            opi++;
            if(cnt)
                cnt=0;
            else
                cnt=1;
        }
    }
    for(int i=1; i<=m; i++)
    {
        if(e[i]!=c[i])
        {
            int flag=0;
            for(int j=i; j<=m; j++)
            {
                if(e[j]==c[i])
                {
                    flag=1;
                    ans2+=j-i;
                    swap(e[i],e[j]);
                    break;
                }
            }
            if(!flag)
                ans2=inf;
        }

    }
    //cout << ans1 << ans2 <<endl;
    cout << min(ans1,ans2) <<endl;


}
