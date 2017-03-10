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
#define ll long long
#define LL unsigned long long
using namespace std;
int num[10010], px[10010], py[10010];
int n, m;
int dp[10010][111];
int getans (int k, int b)
{
    int ans =0;
    double fp = px[k] +1.0 * b / (10.1 + b) * py[k];
    return fp * 0.01 *num[k] + 0.5;
}
int biaoji[10010][111];
int ans[10010];

int main()
{
    int case1 = 0;
    while (~scanf("%d%d", &m, &n) && n + m)
    {
        memset(dp, 0, sizeof(dp));
        memset(biaoji, 0, sizeof(biaoji));
        for (int i = 1; i <= n ; i ++)
            scanf("%d%d%d", &num[i], &px[i], &py[i]);
        for (int i = n; i > 0; i --)
            for (int j = m; j >= 0; j --)
                for (int k = 0; k + j <= m; k ++)
                {
                    int temp = getans(i, k);
                    if (dp[i - 1][k + j] <= dp[i][j] + temp)
                    {
                        dp[i - 1][k + j] = dp[i][j] + temp;
                        biaoji[i - 1][k + j] = j;
                    }
                }
        int pos = m;
        for (int i = 0; i < n; i ++)
        {
            ans[i] = -biaoji[i][pos] + pos;
            pos = biaoji[i][pos];
        }
        printf("Case %d: %d\n", ++case1, dp[0][m]);
        for (int i = 0; i < n; i ++)
        {
            if (i != n - 1)
                printf("%d:%d ", i, ans[i]);
            else
                printf("%d:%d\n",i,ans[i]);
        }
    }
}
