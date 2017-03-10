#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <complex>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>
using namespace std;
#define maxn 150000
#define ll long long
#define inf 2147483647
#define INF 9223372036854775807
int i,m,n,ans,sum;
int dp[maxn][2];
int a[maxn];
int main()

{
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        dp[0][0]=0;
        dp[0][1]=0;
        for(i=1;i<=n;i++)
        {
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]-a[i]);
            dp[i][1]=max(dp[i-1][1],dp[i-1][0]+a[i]);
        }
        for(i=1;i<=n;i++)
        {
            for(int j = 0;j<=1;j++)
                printf("%d ",dp[i][j]);
            printf("\n");
        }
        printf("%d\n",max(dp[n][1],dp[n][0]));
    }
}
