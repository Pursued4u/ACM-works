#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include<vector>
#include<stack>
#include<climits>
#include<ctime>
#include<queue>
#define FILEIN freopen("in.txt", "r", stdin)
#define FILEOUT freopen("out.txt", "w", stdout)
#define CLOSEIO ios::sync_with_stdio(false)
#define PI acos(-1)
#define CLR(a) memset(a,0,sizeof(a))
#define MEM(a,x) memset(a,x,sizoef(a))
#define eps 1e-8
#define sf(x) scanf("%d",&x)
#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)
#define lowbit(x) x&(-x)
#define fi first
#define se second
#define rep(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define drep(a,b,c) for(int (a)=(b);(a)>(c);--(a))
#define dbg(x) cout << #x << "=" << x << endl
using namespace std;
const int maxn = 1e5+5;
typedef long long ll;
typedef double db;
const int inf = INT_MAX;
const ll INF = LLONG_MAX;
const ll mod = 1e9 + 7;
ll mul(ll x,ll y){return x*y%mod;}
ll q_mul(ll a, ll b){ ll ans = 0;while(b){if(b & 1){ans=(ans+a)%mod;} b>>=1;a=(a+a) % mod;}return ans;}
ll q_pow(ll x , ll y){ll res=1;while(y){if(y&1) res=q_mul(res,x) ; y>>=1 ; x=q_mul(x,x);} return res;}
ll inv(ll x) { return q_pow(x, mod-2); }
int Read() {
    int x = 0, F = 1; char C = getchar();
    while (C < '0' || C > '9') { if (C == '-') F = -F; C = getchar(); }
    while (C >= '0' && C <= '9') { x = x * 10 - '0' + C, C = getchar(); }
    return x * F;
}

struct pos{
    ll u, c, top;
};
ll tt;
vector<pos> v;

bool Add(ll x) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i].u == x) return false;
    }
    pos tmp; tmp.u = x, tmp.top = 0, tmp.c = 0;
    v.PB(tmp);
    return true;
}

void pop(ll x) {
    for (int i = x; i < v.size()-1; i++)
        v[i] = v[i+1];
    v.pop_back();
}

bool Close(ll x) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i].u==x){
            printf("close %lld with %lld.\n", x, v[i].c);
            if (x == tt) tt = 0;
            pop(i);
            return true;
        }
    }
    return false;
}

bool Chat(ll x) {
    if (v.size() == 0) return false;
    if (tt) {
        for (int i = 0; i < v.size(); i++) {
            if (v[i].u == tt) {
                v[i].c += x;
                return true;
            }
        }
    }
    else {
        v[0].c += x;
        return true;
    }
}

void pp(ll s) {
    //cout << s << endl;
    pos tmp = v[s-1];
    for (int i = s-1; i >=1; i--) {
        v[i] = v[i-1];
    }
    v[0] = tmp;
}

bool Rotate(ll x) {
    if (x < 1 || x > v.size()) return false;
    pp(x); return true;
}

bool Prior() {
    if (v.size() == 0) return false;
    ll maxx = 0, k;
    for (int i = 0; i < v.size(); i++) {
        if (v[i].u > maxx) {
            maxx = v[i].u;
            k = i;
        }
    }
    pp(k+1); return true;
}

bool Choose(ll x) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i].u == x) {
            pp(i+1);
            return true;
        }
    }
    return false;
}

bool Top(ll x) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i].u == x) {
            tt = x;
            v[i].top = 1;
            return true;
        }
    }
    return false;
}

bool Untop() {
    if (tt) {
        for (int i = 0; i < v.size(); i++) {
            if (v[i].u == tt) {
                tt = 0;
                v[i].top = 0;
                return true;
            }
        }
    }
    return false;
}

void solve() {
    v.clear(); tt = 0; int cas = 1;
    int n; cin >> n;
    getchar();
    while (n--) {
        char op[10];
        printf("Operation #%d: ", cas++);
        scanf("%s", op);
        if (op[0] == 'U' || op[0] == 'P') {
            if (op[0] == 'U') {
                if (Untop()) puts("success.");
                else puts("no such person.");
            }
            else {
                if (Prior()) puts("success.");
                else puts("empty.");
            }
        }
        else {
            ll x; scanf("%lld", &x);
            if (!strcmp(op, "Add")) {
                if (Add(x)) puts("success.");
                else puts("same priority.");
            }
            else if (!strcmp(op, "Close")) {
                if (Close(x));
                else puts("invalid priority.");
            }
            else if (!strcmp(op, "Chat")) {
                if (Chat(x)) puts("success.");
                else puts("empty.");
            }
            else if (!strcmp(op, "Rotate")) {
                if (Rotate(x)) puts("success.");
                else puts("out of range.");
            }
            else if (!strcmp(op, "Choose")) {
                if (Choose(x)) puts("success.");
                else puts("invalid priority.");
            }
            else if (!strcmp(op, "Top")) {
                if (Top(x)) puts("success.");
                else puts("invalid priority.");
            }
        }
     //   for (int i = 0; i < v.size(); i++)
           // cout << i << ' ' << v[i].u << ' ' << v[i].c << ' ' << v[i].top << endl;
    }
    if (tt) {
        for (int i = 0; i < v.size(); i++) {
            if (tt == v[i].u) {
                if (v[i].c) printf("Bye %lld: %lld\n", tt, v[i].c);
                break;
            }
        }
    }
    for (int i = 0; i < v.size(); i++) {
        if (tt == v[i].u) continue;
        if (v[i].c) printf("Bye %lld: %lld\n", v[i].u, v[i].c);
    }
}

int main()
{
    //FILEIN;
    int t; cin >> t;
    while (t--) solve();
}
