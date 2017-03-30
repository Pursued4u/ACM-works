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
#define maxn 200005
#define ll long long
#define inf 2147483647
#define INF 9223372036854775807
int n,i;
pair<int,int>a,b;
int main()
{

    while(~scanf("%d",&n))
    {
        b.first=b.second=0;
        int ans=0;
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&a.first,&a.second);
            if(a.first>=b.first)
                b=a;
            ans=max(ans,b.second);
        }
        printf("%d\n",ans);
    }
}
