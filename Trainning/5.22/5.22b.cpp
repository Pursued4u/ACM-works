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
using namespace std;
typedef long long ll;
typedef double db;
const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;
map<string, ll> mp;
map<string, ll>::iterator it;

int main()
{

    ll n;
    int vis[205];
    string b;
    char a[maxn];

    while (~scanf("%I64d",&n))
        {
        mp.clear();
        while (n--)
        {
            scanf("%s", a);
            int len = strlen(a);
            memset(vis, 0, sizeof(vis));
            b = "";
            char p = 'a';
            for (int i = 0; i < len; i++)
            {
    
                if (!vis[a[i]])
                {
                    vis[a[i]] = p;
                    p++;
                }
                b += vis[a[i]];
            }

            mp[b]++;
        }
        ll ans = 0;
        for (it = mp.begin(); it != mp.end(); it++) {
            ll tmp = it -> second;
            ans += (tmp)*(tmp-1)/2;
        }
        printf("%I64d\n",ans);
    }
}
