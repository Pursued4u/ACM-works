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
int ord, dep[maxn], de;
map<string, int> mp;
vector<int> v, G[maxn];
string yi[maxn], ans;

int dfs(int x, int fa) {
    for (int i = x; i < v.size(); i++) {
       // cout << i << endl;
        if (v[i] == 1) {
            //cout << i << "++++"<< endl;
            return i;
        }
        if (v[i] == 3) {
            G[fa].push_back(v[i-1]);
            //cout << yi[fa] << endl;
            if (v[i+1] == 0) {
                int tmp = dfs(i+1, v[i-1]);
                i = tmp;
            }
            else {
                G[v[i-1]].push_back(v[i+1]);
            }
        }
    }
}

void pri(int x, int fl) {
    if (G[x].size() == 0) return;
    if (fl) ans += ':';
    if (G[x].size() >= 2) ans += '{';
    for (int i = 0; i < G[x].size(); i++) {
        int u = G[x][i];
        if (i >= 1) ans += ',';
        ans += yi[u];
        pri(u, 1);
    }
    if (G[x].size() >= 2) ans += '}';
}

void Find(int x, int dd) {
    if (dd == de) {
     //   cout << G[x].size() << "++++\n";
       // for (int i = 0; i < G[x].size(); i++)
        pri(x, 0);
        return;
    }
    for (int i = 0; i < G[x].size(); i++) {
        int u = G[x][i];
        if (u == dep[dd]) {
            Find(u, dd+1);
            return;
        }
    }
}

void solve() {
    mp.clear();
    v.clear(); string a;
    yi[0] = "{", yi[1] = "}";
    yi[2] = ",", yi[3] = ":";
    ord = 4; int flag = 0;
    for (int i = 0; i < maxn; i++)
        yi[i] = "";
    cin >> a;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] == '{') v.push_back(0);
        if (a[i] == '}') v.push_back(1);
        if (a[i] == ',') v.push_back(2);
        if (a[i] == ':') v.push_back(3);
        if (a[i] == '"') flag++;
        if (flag) {
            yi[ord] += a[i];
        }
        if (flag >= 2) {
            mp[yi[ord]] = ord;
            v.push_back(ord);
            ord++;
            flag = 0;
        }
    }
    for (int i = 0; i < ord+4; i++)
        G[i].clear();
    dfs(0, 0);
    int q;
    cin >> q;
    while (q--) {
        de = 0;
        string b; cin >> b;
        string tmp; ans = "";
        for (int i = 0; i < b.length(); i++) {
            if (b[i] != '.') {
                tmp += b[i];
            }
            else {
                dep[de++] = mp[tmp];
                tmp = "";
            }
        }
        dep[de++] = mp[tmp];
        Find(0, 0);
        if (ans == "") ans = "Error!";
        cout << ans << endl;
    }
}

int main()
{
    int t;
     cin >> t;
     while (t--) solve();
}
