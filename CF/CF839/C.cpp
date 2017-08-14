
#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cstring>
#include <queue>
#include <set>
#include <string>
#include <map>
#include <climits>
#define PI acos(-1)
using namespace std;
typedef long long ll;
typedef double db;
const int maxn = 1e2 + 5;
const int mod = 1e9 + 7;
const int INF = 1e8 + 5;
const ll inf = 1e15 + 5;
const db eps = 1e-5;
int a[maxn];

void solve() {
    int n, k;

    while (cin >> n >> k) {
        int four = n, two = 2 * n;
        for (int i = 1; i <= k; i++) {
            scanf("%d", a + i);
            while (a[i] > 4 && four) {
                four--;
                a[i] -= 4;
            }
        }
        if (four) {
            for (int i = 1; i <= k; i++) {
                if (a[i] == 3 && four) {
                    four--;
                    a[i] = 0;
                }
            }
            if (four) {
                int one = four;
                two += four;
                for (int i = 1; i <= k; i++) {
                    if (a[i] == 1 && one) {
                        a[i] = 0;
                        one--;
                    }
                }
                if (one) {
                    for (int i = 1; i <= k; i++) {
                        while (a[i] && one) {
                            one--;
                            a[i]--;
                        }
                    }
                    for (int i = 1; i <= k; i++) {
                        if (a[i] && two) {
                            two--;
                            a[i] = 0;
                        }
                    }
                }
                else {
                    for (int i = 1; i <= k; i++) {
                        if (a[i] && two) {
                            a[i] = 0;
                            two--;
                        }
                    }
                }
            }
            else {
                for (int i = 1; i <= k; i++) {
                    if (a[i]) {
                        while (a[i] && two) {
                            two--;
                            a[i] -= 2;
                            if (a[i] < 0) a[i] = 0;
                        }
                    }
                }
            }
        }
        else {
            for (int i = 1; i <= k; i++) {
                if (a[i]) {
                    while (a[i] && two) {
                        two--;
                        a[i] -= 2;
                        if (a[i] < 0) a[i] = 0;
                    }
                }
            }
        }
        int flag = 1;
        for (int i = 1; i <= k; i++)
            if (a[i]) flag = 0;
        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main() {
    int t = 1, cas = 1;
   // freopen("in.txt", "r", stdin);
   // freopen("in.txt", "w", stdout);
   // init();
    //scanf("%d", &t);
    while(t--) {
       // printf("Case %d: ", cas++);
        solve();
    }
    return 0;
}
