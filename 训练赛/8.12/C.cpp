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
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
const db eps = 1e-9;

struct P
{
    int pos, n;
}a[maxn];
int cmp(const P&a, const P&b)
{
    return a.n > b.n;
}
int n;

void solve()
{
    scanf("%d", &n);
    map<int, int>mp;
    for(int i=1; i<=n-1; i++)
    {
        scanf("%d", &a[i].n);
        a[i].pos = i;
        mp[a[i].n] = i;
    }
    sort(a+1, a+n, cmp);
    ll ans = 0;
    int jl = 0;
    n--;
    int nn = n;
    for(int i=1; i<=nn; i++) {
        if(!n) break;
        if(i==1)
        {
            if(a[i].pos <= n)
            {
                ans += a[i].n;
                n-=a[i].pos;
                jl = a[i].pos;
            }
            else
            {
                ans += mp[n];
                n = 0;
            }
        }
        else
        {
            if(a[i].pos-1 <= n)
            {
                ans += a[i].n;
                n -= a[i].pos-1;
            }
            else
            {
                ans += mp[n+1];
                n = 0;
                ans += a[i].pos-1-n;
            }
        }
        cout << ans << endl;
    }
    cout << ans << endl;
}

int main(){
    //cin.sync_with_stdio(false);
    //freopen("tt.txt", "r", stdin);
    //freopen("isharp.out", "w", stdout);

    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
