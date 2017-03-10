#include<bits/stdc++.h>
using namespace std;
#define maxn 505
int a[maxn][maxn];
int dp[maxn][maxn];
const int inf = 1e6+5;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {

        int m,n;
        cin >> m >> n;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        for(int i=1;i<=m+1;i++)
        {
            for(int j=1;j<=n+1;j++)
            {
                dp[i][j]=inf;
            }
        }
        dp[m+1][n]=1;
        for(int i=m;i>=1;i--)
        {
            for(int j=n;j>=1;j--)
            {
                dp[i][j]=max(min(dp[i][j+1],dp[i+1][j])-a[i][j],0);
            }
        }
        cout << dp[1][1] << endl;
    }
}
