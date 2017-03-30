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

int ans;

void LIS(int a[], int op)
{
    vector<int> v;
    for (int i = 0; i < op; i++)
    {
        int si = v.size();
        int p1 = upper_bound(v.begin(), v.end(), a[i]) - v.begin();
        if (p1 == si) v.push_back(a[i]);
        else v[p1] = a[i];
        ans = max(ans, p1+1);
    }
}

void solve() {
    int n, a[maxn], b[maxn];

    cin >> n;

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    ans = 0; int flag1 = 0, flag2 = 0;
    LIS(a, n);
    if (ans >= n-1) flag1 = 1;
    //cout << ans << endl;
    ans = 0;
    for (int i = 0; i < n; i++)
        b[i] = a[n-i-1];
    LIS(b, n);
    if (ans >= n-1) flag2 = 1;
    if (flag1 || flag2) cout << "YES\n";
    else cout << "NO\n";
}


int main(){
    //cin.sync_with_stdio(false);
    //freopen("tt.txt", "r", stdin);
    //freopen("isharp.out", "w", stdout);
    int s1 = 1, s2 = 5;
    cout << (s1 ^ s2) << endl;
    int t; cin >> t;
    while (t--) solve();

    return 0;
}
