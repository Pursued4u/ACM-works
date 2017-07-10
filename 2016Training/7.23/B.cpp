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
const int maxn = 1e4 + 5;
const int mod = 1e9 + 7;
const db eps = 1e-9;
int  n, m, l, r, t, b;
char op[1005];

stack<int> st[maxn];
void chan_t() {
    for (int i = 0; i < m; i++) {
        while (!st[t*m+i].empty()) {
            st[(t+1)*m+i].push(-st[t*m+i].top());
            st[t*m+i].pop();
        }
    }
}

void chan_b() {
    for (int i = 0; i < m; i++) {
        while (!st[b*m+i].empty()) {
            st[(b-1)*m+i].push(-st[b*m+i].top());
            st[b*m+i].pop();
        }
    }
}

void chan_l() {
    for (int i = 0; i < n; i++) {
        while (!st[i*m+l].empty()) {
            st[i*m+l+1].push(-st[i*m+l].top());
            st[i*m+l].pop();
            //cout << st[i*m+l+1].top() << endl;
        }
    }
}
void chan_r() {
    for (int i = 0; i < n; i++) {
        while (!st[i*m+r].empty()) {
            st[i*m+r-1].push(-st[i*m+r].top());
            st[i*m+r].pop();
        }
    }
}


int main(){
    //cin.sync_with_stdio(false);
    //freopen("tt.txt", "r", stdin);
    //freopen("isharp.out", "w", stdout);
    int cas = 1;

    while (cin >> n >> m) {
        if (!n && !m) break;
        l = 0, r = m-1, t = 0, b = n-1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x; cin >> x;
                st[i*m+j].push(x);
            }
        }
        getchar();
        gets(op); int len = strlen(op);
        for (int i = 0; i < len; i++) {
            if (op[i] == 'T') {
                chan_t();
                t++;
            }
            if (op[i] == 'B') {
                chan_b(); b--;
            }
            if (op[i] == 'L') {
                chan_l(); l++;
            }
            if (op[i] == 'R') {
                chan_r(); r--;
            }
           // cout << i << ' ' << l << ' ' << t <<  endl;
        }
        printf("Case %d:", cas++);
        int p = 0, ans[maxn];
        while (!st[t*m+l].empty()) {
            if (st[t*m+l].top() > 0)
            ans[p++] = st[t*m+l].top();
            st[t*m+l].pop();
        }
        for (int i = p-1; i >= 0; i--) {
            cout << ' ';
            printf("%d", ans[i]);
        }
        cout << endl;
    }
    return 0;
}
