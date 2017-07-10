#include<cstdio>
#include<iostream>
using namespace std;
#define maxn 5005
int dp[maxn][maxn];
int w[maxn];
int v[maxn];
int main()
{
    int m ,n;
    cin >> m >> n;
    for(int i=0;i<n;i++)
    {
        cin >> w[i] >> v[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(j<w[i])
            dp[i+1][j]=dp[i][j];
            else
            {
                dp[i+1][j]=max(dp[i][j],dp[i][j-w[i]]+v[i]);
            }
        }

    }
    cout << dp[n][m]<< endl;

}
