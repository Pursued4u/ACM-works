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

void solve() {
    ll n, m;

    while (scanf("%I64d%I64d", &n, &m)) {
        if (!n && !m) break;
        ll son = m*n - n;
        m *= m;
        ll gd = __gcd(son, m);
        son /= gd, m /= gd;
        printf("%I64d/%I64d\n", son, m);
    }
}

int main(){
    //cin.sync_with_stdio(false);
    //freopen("tt.txt", "r", stdin);
    //freopen("isharp.out", "w", stdout);
    solve();

    return 0;
}
