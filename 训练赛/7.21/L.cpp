#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<cstring>
#include<queue>
#include<set>
#include<string>
#include<map>
#define inf 9223372036854775807
#define INF 9e7+5
#define PI acos(-1)
using namespace std;
typedef long long ll;
typedef double db;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
const db eps = 1e-9;
string s;
char a[maxn];
char b[5005];
int main(){
    //cin.sync_with_stdio(false);
    //freopen("tt.txt", "r", stdin);
    //freopen("isharp.out", "w", stdout);
    int vis[maxn];

    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        int m,n;
        scanf("%d %d",&m,&n);
        scanf("%s",a);
        scanf("%s",b);
        int sum=0;
        //cout << strlen(a) << " " <<strlen(b) << endl;
        for(int i=0;i<m;i++)
        {
            int cnt = i;
            for(int j=0;j<n;)
            {
                if(a[cnt]==b[j])
                {
                    cnt++;
                    j++;

                }
                else
                {
                    if(a[cnt]==b[j+1]&&a[cnt+1]==b[j])
                    {
                        cnt+=2;
                        j+=2;
                    }
                    else
                    break;
                }
                if(j==n)
                {
                    vis[i]=1;
                    sum++;

                }
            }
        }
        for(int i=0;i<m;i++)
        cout << vis[i];
        cout << endl;

    }
    return 0;
}
