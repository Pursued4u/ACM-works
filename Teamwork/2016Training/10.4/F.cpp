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
const int maxn = 1e4+5;
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
int cas = 1;

void solve() {
    int n, k; cin >> n >> k;
    if (n == 3) {
        cout << "1 2 3\n"; return;
    }
    if (n == 2) {
        cout << "1 2\n"; return;
    }
    bool vis[maxn] = {0};
    int hh = k-1; hh *= 2; if (hh >= 4) hh += 2;
    vector<int> ans;
    for (int i = hh; i >= 2; i -= 2) {
        if (i == 4) continue;
        ans.push_back(i);
        vis[i] = 1;
    }
    ans.push_back(4); ans.push_back(1); ans.push_back(3);
    vis[3] = vis[4] = 1;
    for (int i = 2; i <= n; i++) {
        if (vis[i]) continue;
        ans.push_back(i);
    }
    printf("Case #%d: ", cas++);
    for (int i = 0; i < ans.size(); i++)
        printf("%d%c", ans[i], i == ans.size()-1? '\n' : ' ');
}

int main()
{
    int t; cin >> t;
    while (t--) solve();
}
