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
const int maxn = 3e5 + 5;
const ll mod = 530600414;
const db eps = 1e-9;
int cas = 1;
ll dl[maxn], dr[maxn], cnt[maxn], ans[maxn], len[maxn];

void init() {
    dl[3] = 0, dr[3] = 2, dl[4] = 2, dr[4] = 2, ans[4] = 0, len[3] = 3, len[4] = 5, cnt[3] = cnt[4] = 1;

    for (int i = 5; i <= maxn; i++) {
        ans[i] = dr[i-2]*cnt[i-1] % mod + cnt[i-2] * dl[i-1] % mod + cnt[i-1]*cnt[i-2] % mod + ans[i-1] + ans[i-2];
        //cout << ans[i-1] << endl;
        ans[i] %= mod;
        dr[i] = dr[i-1] + dr[i-2] + cnt[i-2] * len[i-1] % mod;
        dr[i] %= mod;
        dl[i] = dl[i-1] + dl[i-2] + cnt[i-1] * len[i-2] % mod;;
        dl[i] %= mod;
        len[i] = len[i-1] + len[i-2];
        len[i] %= mod;
        cnt[i] = cnt[i-1] + cnt[i-2];
        cnt[i] %= mod;
    }
    //cout << dr[5] << ' ' << dl[5] <<' ' << len[5] << ' ' << cnt[5] <<  endl;
   // cout << dr[6] << ' ' << dl[6] <<' ' << len[6] << ' ' << cnt[6] <<  endl;
}

void solve() {
    ll n, ansr; cin >> n;

    if (n <= 4) ansr = 0;
    else {
        ansr = ans[n];
    }
    printf("Case #%d: %I64d\n", cas++, ansr);
}

int main(){
    //cin.sync_with_stdio(false);
    //freopen("tt.txt", "r", stdin);
    //freopen("isharp.out", "w", stdout);
    init();
    int t; cin >> t;
    while (t--)
        solve();

    return 0;
}
