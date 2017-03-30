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
const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;
const db eps = 1e-9;
    ll n, a[maxn], sum[maxn];

void solve() {

    while (cin >> n) {
        sum[0] = 0;
        for (ll i = 1; i <= n; i++) {
            scanf("%I64d", &a[i]);
            sum[i] = sum[i-1] + a[i];
        }
        ll ans = 0, ff = 0;
        for (ll i = n; i >= 1; i--) {
            if (a[i] < 0) {
                for (ll j = i-1; j >= 0; j--) {
                    if (sum[j] <= sum[i]) {
                        ans += i - j;
                       // cout << j << endl;
                        ff ++;
                        i = j+1;
                        break;
                    }
                }
            }
        }
        cout << ff + n - ans << endl;
    }
}

int main(){
    //cin.sync_with_stdio(false);
    //freopen("tt.txt", "r", stdin);
    //freopen("isharp.out", "w", stdout);
    solve();

    return 0;
}
