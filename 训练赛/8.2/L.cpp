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
const int maxn = 1e3 + 10;
const ll mod = 1e9 + 7;
const db eps = 1e-9;
ll dp[maxn][maxn];
int a[maxn];
int b[maxn];
int m,n;
int main()
{
   // freopen("tt.txt", "r", stdin);
    while(cin >> m >> n)
    {
        for(int i=0; i<m; i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=0; i<n; i++)
        {
            scanf("%d",&b[i]);
        }
        //cout << a << " " << b <<endl;
    memset(dp,0,sizeof(dp));
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            dp[i][j]=((dp[i - 1][j] + dp[i][j - 1])%mod - dp[i - 1][j - 1] + mod) % mod+ (a[i-1] == b[j-1] ? dp[i - 1][j - 1]+1 : 0);
            dp[i][j] %= mod;
        }
    }
        cout <<dp[m][n] << endl;
    }
}
