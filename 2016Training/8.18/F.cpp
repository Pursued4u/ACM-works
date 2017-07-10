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
#define FILEIN freopen("in.txt", "r", stdin)
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
const int maxn = 1e5+5;
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
map<ll, int> mp;
ll a[4*maxn], c[maxn*4], n;

struct pos {
    ll x1, x2, y1, y2, fom, ord;
} q[maxn];

struct lin {
    int l, r, y;
} linn[maxn];

void updata(int x, int p) {
    while (x < 4*maxn) {
        c[x] += p;
        x += lowbit(x);
    }
}

ll getsum(ll x) {
    ll ans = 0;
    while (x) {
        ans += c[x];
        x -= lowbit(x);
    }
    return ans;
}

vector<int> ad[maxn*4], de[maxn*4];
void init() {
    memset(c, 0, sizeof(c));
    mp.clear();
    for (int i = 0; i < maxn*4; i++) {
        ad[i].clear(); de[i].clear();
    }
}

bool cmp(const lin &a, const lin &b) {
    return a.y < b.y;
}


void solve() {
    cin >> n;
    int p = 1, li = 1;
    init();
    for (int i = 1; i <= n; i++) {
        scanf("%I64d%I64d%I64d%I64d", &q[i].x1, &q[i].y1, &q[i].x2, &q[i].y2);
        if (q[i].x1 == q[i].x2) q[i].fom = 1;
        if (q[i].y1 == q[i].y2) {
            q[i].fom = 2;
            lin tmp; tmp.l = min(q[i].x1, q[i].x2), tmp.r = max(q[i].x1, q[i].x2), tmp.y = q[i].y1;
            linn[li++] = tmp;
        }
        a[p++] = q[i].x1;
        a[p++] = q[i].y1;
        a[p++] = q[i].x2;
        a[p++] = q[i].y2;
    }
    sort(a+1, a+p);
    int hh = 1; a[0] = -mod;
    for (int i = 1; i < p; i++) {
        if (a[i] != a[i-1]) {
            mp[a[i]] = hh++;
        }
    }
    for (int i = 1; i <= n; i++) {
        q[i].x1 = mp[q[i].x1];
        q[i].x2 = mp[q[i].x2];
        q[i].y1 = mp[q[i].y1];
        q[i].y2 = mp[q[i].y2];
    }
    for (int i = 1; i < li; i++) {
        linn[i].l = mp[linn[i].l];
        linn[i].r = mp[linn[i].r];
        linn[i].y = mp[linn[i].y];
    }
    for (int i = 1; i <= n; i++) {
        if (q[i].fom == 1) {
            int d = q[i].y1, to = q[i].y2;
            if (d > to) swap(d, to);
            ad[d].push_back(q[i].x1), de[to+1].push_back(q[i].x1);
        }
    }
    sort(linn+1, linn+li, cmp);
    ll ans = 0, dd = 0;
    for (int i = 1; i < li; i++) {
        while (dd <= linn[i].y) {
            for (int k = 0; k < ad[dd].size(); k++) {
                updata(ad[dd][k], 1);
            }
            for (int k = 0; k < de[dd].size(); k++) {
                updata(de[dd][k], -1);
            }
            dd++;
        }
        ans += getsum(linn[i].r) - getsum(linn[i].l - 1);
      //  cout <<ans <<endl;
    }
    cout << ans << endl;
}

int main()
{
    FILEIN;
    int t; cin >> t;
    while (t--) solve();

}
