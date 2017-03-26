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
ll mul(ll x,ll y){return x*y%mod;}ll q_mul(ll a, ll b){ ll ans = 0;while(b){if(b & 1){ans=(ans+a)%mod;} b>>=1;a=(a+a) % mod;}return ans;}
ll q_pow(ll x , ll y){ll res=1;while(y){if(y&1) res=q_mul(res,x) ; y>>=1 ; x=q_mul(x,x);} return res;}
ll inv(ll x) { return q_pow(x, mod-2); }
int Read() {
    int x = 0, F = 1; char C = getchar();
    while (C < '0' || C > '9') { if (C == '-') F = -F; C = getchar(); }
    while (C >= '0' && C <= '9') { x = x * 10 - '0' + C, C = getchar(); }
    return x * F;
}
int ans[maxn], cnt[10];

void init() {
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= 5; i++) {
        cnt[i]++; ans[i] = i;
    }
    ans[6] = 2, ans[7] = 3; cnt[2]++, cnt[3]++;
    int hh = 6, cir = 2, sum = 7, num = 12;
    for (int i = 8; i < maxn; i++) {
        int vis[10]; memset(vis, 0, sizeof(vis));
        int tmp = i - sum;
        if (tmp == 1) {
            vis[ans[i-hh]] = 1;
        }
        else if (tmp%cir == 0) {
            if (i == 9) hh++;
            vis[ans[i-hh]] = 1;
        }
        else {
            hh++;
            vis[ans[i-hh]] = 1;
            vis[ans[i-hh+1]] = 1;
        }
        if (tmp == num) {
            vis[ans[i-num+1]] = 1;
        }
        vis[ans[i-1]] = 1; int k, minn = inf;
        for (int j = 1; j <= 5; j++) {
            if (vis[j]) continue;
            if (i == 24)  cout << " h:" << hh << ' ' <<  j << endl;
            if (cnt[j] < minn) {
                k = j;
                minn = cnt[j];
            }
        }
        ans[i] = k; cnt[k]++;
        if (tmp >= num) {
            sum += num;
            num += 6;
            cir++;
        }
       // hh++;
    }
    for (int i = 1; i <= 100; i++)
        cout << i << ' ' << ans[i] << endl;
}

void solve() {
    int n;  cin >> n;
    cout << ans[n] << endl;
}

int main()
{
    init();
    int t; cin >> t;
    while (t--) solve();
}
