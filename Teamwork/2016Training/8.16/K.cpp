#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#include<climits>
#define FILEIN freopen("tt.txt", "r", stdin)
#define FILEOUT freopen("output.txt", "w", stdout)
#define CLOSEIO ios::sync_with_stdio(false)
#define PI acos(-1)
#define CLR(a) memset(a,0,sizeof(a))
#define MEM(a,x) memset(a,x,sizoef(a))
#define eps 1e-8
#define scf(x) scanf("%d",&x)
#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)
#define lowbit(x) x&(-x)
#define db double
#define rep(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define drep(a,b,c) for(int (a)=(b);(a)>(c);--(a))
#define dbg(x) cout << #x << "=" << x << endl


using namespace std;
const int maxn = 2e2+5;
typedef long long ll;
const int inf = ((1ll<<29)-10);
const ll mod = 1000000007;
int mul(int x,int y){return 1LL*x*y%mod;}
int qpow(int x , int y){int res=1;while(y){if(y&1) res=mul(res,x) ; y>>=1 ; x=mul(x,x);} return res;}
int Read() {
    int x = 0, F = 1; char C = getchar();
    while (C < '0' || C > '9') { if (C == '-') F = -F; C = getchar(); }
    while (C >= '0' && C <= '9') { x = x * 10 - '0' + C, C = getchar(); }
    return x * F;
}

struct sho{
    ll in, tot, tim;
} q[maxn];

vector<int> G[maxn];

bool cmp(const sho &a, const sho &b) {
    if (a.tim == b.tim) return a.tot > b.tot;
    return a.tim < b.tim;
}
int vis[201];

void solve() {
    ll n, m, need, l[maxn], t[maxn];
    memset(vis, 0, sizeof(vis));
    memset(q, 0, sizeof(q));
    cin >> n >> m >> need;
    for(int i=0; i<=n; i++)G[i].clear();
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> t[i];
    }
    for (int i = 1; i <= m; i++) {
        int num;
        cin >> q[i].in >> num;
        ll sum = 0, maxx = -1;
        while (num--) {
            int x; cin >> x;
            G[i].push_back(x);
            sum += l[x];
            maxx = max(maxx, t[x]);
        }
        q[i].tot = q[i].in - sum;
        q[i].tim = maxx;
    }
    sort(q+1, q+1+m, cmp);
    q[m+1].tim = -2;
    ll to = 0, ans;
    for (int i = 1; i <= m; i++) {
        int tt = 0;
        for(int j=0; j<G[i].size(); j++)
            if(vis[G[i][j]]) tt += l[G[i][j]];
        cout << tt << endl;
        if(q[i].tot+tt>0)
        {
            for(int j=0; j<G[i].size(); j++)
                vis[G[i][j]]++;
            //to+=tt;
            to += q[i].tot+tt;
        }
        else continue;
        ans = q[i].tim;
        //if (q[i].tot <= 0) continue;
        //to += q[i].tot;

        if (q[i+1].tim != q[i].tim) {
            if (to >= need) {
                break;
            }
        }
    }
   // cout << to << endl;
    if (to < need) cout << "impossible\n";
    else cout << ans << ' ' << to << endl;
}

int main()
{
    FILEIN;
    int t, cas = 1;

    cin >> t;
    while (t--) {
        printf("Case #%d: ", cas++);
        solve();
    }

}
