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
int i,m,n,x,y;
int a[maxn];
pair<int,int>pr[maxn];
map<int,int>mp;
pair<int,int>cn=make_pair(0,0);

int main()
{

    while(~scanf("%d",&n))
    {

        x=y=0;
        int ans=0;
        cn=make_pair(0,0);
        for(i=0; i<n; i++)
        {
            cin >> x;
            mp[x]++;
        }
        cin >> n;
        for(i=0; i<n; i++) cin >> pr[i].first;
        for(i=0; i<n; i++) cin >> pr[i].second;
        for(i=0; i<n; i++)
        {
            x=pr[i].first;
            y=pr[i].second;
            if(mp[x]>cn.first)
            {
                cn=make_pair(mp[x],mp[y]);
                ans=i;
            }
            else if(mp[x]==cn.first)
            {
                if(mp[y]>cn.second)
                {
                    cn=make_pair(mp[x],mp[y]);
                    ans=i;
                }

            }
        }
        cout << ans+1 << endl;
    }

}
