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
#define MEM(a,x) memset(a,x,sizeof(a))
#define eps 1e-8
#define sf scanf
#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)
#define lowbit(x) x&(-x)
#define fi first
#define se second
#define rep(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define drep(a,b,c) for(int (a)=(b);(a)>(c);--(a))
#define dbg(x) cout << #x << "=" << x << endl
#define _ixvii0iv
using namespace std;
const int maxn = 1e5+5;
const int MAXN = 1e5+1e3;
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
int deg[MAXN];
bool vis[MAXN];
int n, k;
vector<int> G[MAXN];
queue<int> q;
bool solve() {
    CLR(vis);
    while(!q.empty()) q.pop();
    rep(i, 1, n+1)
        if(deg[i]==1) q.push(i);
	dbg(q.size());
    while(!q.empty()) {
        int u=q.front();q.pop();
        int m=G[u].size();
        int fa;
        for(int i=0; i<m; ++i)
            if(!vis[G[u][i]]) {
                    fa=G[u][i];
                    break;
            }
		cout << u << " " << dbg(fa);
        vis[u]=vis[fa]=true;
        m=G[fa].size();
        for(int i=0; i<m; ++i) {
            int v=G[fa][i];
            if(vis[v]) continue;
            --deg[v];
			cout << v << " " << deg[v] << endl;
			if(deg[v]==0) return true;
            if(deg[v]==1) {
                q.push(v);
            }
        }
    }
    return false;
}
int main(){
	FILEIN;
	FILEOUT;
    int t; sf("%d", &t);
    while(t--) {
        sf("%d%d", &n, &k);
        CLR(deg);
        if(n==1) {cout << "Alice\n"; continue;}
        rep(i, 1, n+1)
            G[i].clear();
        rep(i, 2, n+1) {
            int v;sf("%d", &v);
            ++deg[v], ++deg[i];
            G[i].push_back(v);
            G[v].push_back(i);
        }
        puts(solve()?"Alice":"Bob");
    }
    return 0;
}
