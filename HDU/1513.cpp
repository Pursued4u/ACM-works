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
#define maxn 100005
#define ll long long
#define inf 2147483647
#define INF 9223372036854775807
int dp[2][5005];
char a[5005],b[5005];
int n,i,j,x,y;;
void lcs()
{
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            x=i%2;
            y=1-x;
            if(a[i-1]==b[j-1])
                dp[x][j]=dp[y][j-1]+1;
            else
                dp[x][j]=max(dp[y][j],dp[x][j-1]);
        }
    }
}
int main()
{

    while(scanf("%d",&n)!=EOF)
    {
    memset(a,0,sizeof(a));
    memset(dp,0,sizeof(dp));
    scanf("%s",a);
    for(i=0;i<n;i++)
    {
        b[i]=a[n-i-1];
    }
    b[i]='\0';

    lcs();
    printf("%d\n",n-dp[n%2][n]);
    }
}
