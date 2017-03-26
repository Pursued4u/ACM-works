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
char a[maxn];
char b[maxn];
char c[maxn];
int n,vis[201],maxx;
int main()
{

    string ans;
    while (cin >> n)
        {
        scanf("%s", a);
        scanf("%s", b);
        scanf("%s", c);
        ans = "";

        memset(vis, 0, sizeof(vis));
        for (int i = 0 ; i < n; i++)
            {
            vis[a[i]]++;
            vis[b[i]]++;
            vis[c[i]]++;
            maxx = vis[a[i]];
            char k = a[i];
            if (vis[b[i]] > maxx)
            {
                maxx = vis[b[i]];
                k = b[i];
            }
            if (vis[c[i]] > maxx)
            {
                maxx = vis[c[i]];
                k = c[i];
            }
            ans += k;
            vis[a[i]] = 0;
            vis[b[i]] = 0;
            vis[c[i]] = 0;
        }
        cout << ans << endl;
    }
}
