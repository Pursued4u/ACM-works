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
const int maxn = 2e6 + 5;
const int mod = 1e9 + 7;
const db eps = 1e-9;
int cas = 1;

void solve() {
    char op[maxn];

    cin >> op;
    int len = strlen(op);
    int is = -1;
    for (int i = len; i < 2*len; i++) {
        op[i] = op[i-len];
        if (op[i] == 'c' && is == -1) is = i-len;
    }
    int ans;
   // cout << is << endl;
    if (is != -1) {
        ans = 0; int num = 0;
        for (int i = is; i < is + len; i++) {
            if (op[i] != 'c' && op[i] != 'f') {
                ans = -1; break;
            }
            if (op[i] == 'c' && op[i+1] == 'c') {
                ans = -1;
                break;
            }
            if (op[i] == 'c' && op[i+2] == 'c') {
                ans = -1;
                break;
            }
            if (op[i] == 'c') ans++;
        }
    }
    else {
        ans = len / 2 + len%2;
    }
    printf("Case #%d: %d\n", cas++, ans);
}

int main(){
    //cin.sync_with_stdio(false);
    //freopen("tt.txt", "r", stdin);
    //freopen("isharp.out", "w", stdout);
    int t;

    cin >> t;
    while (t--) solve();

    return 0;
}
