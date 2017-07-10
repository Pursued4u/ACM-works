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
#define maxn 400010
#define ll long long
#define inf 2147483647
#define INF 9223372036854775807

map<ll,ll> mp;

ll n,s,a[maxn],b[maxn],ans,i,m;
int main()
{
    while (~scanf("%I64d %I64d",&n,&m))
    {
        ans=0;
        mp.clear();
        for (i=1;i<=n;i++)
        scanf("%I64d", &a[i]);
        b[0] = 0;
        for (i=1; i<=n;i++)
            b[i]=b[i-1]+a[i];
        for(i=1;i<=n;i++)
        {
            printf("%I64d ",b[i]);
        }
        printf("\n");
        for (int i=1;i<=n;i++)
        {
            ans+=mp[b[i]-m];
            if (b[i]==m)ans++;
            mp[b[i]]++;
        }
        printf("%I64d\n",ans);
    }
}
