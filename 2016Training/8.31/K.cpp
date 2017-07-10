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

ll ss(ll x) {
    return x*x;
}
ll l_b[maxn], l_w[maxn], r_b[maxn], r_w[maxn];

void solve() {
    char a[maxn]; cin >> a; //memset(l_b, 0, sizeof(l_b));
  //  memset(r, 0, sizeof(r)); memset(r_b, 0, sizeof(r_b)); memset(l_w, 0, sizeof(l_w));
    int len = strlen(a);
    int w = 0, b = 0;
    ll sum = 0;
    for (int i = 0; i < len; i++) {
        l_b[i] = b, l_w[i] = w;
        if (a[i] == '0') w++, b = 0;
        else b++, w = 0;
    }
    w = b = 0;
    for (int i = len-1; i >= 0; i--) {
        r_b[i] = b, r_w[i] = w;
        if (a[i] == '0') w++, b = 0;
        else b++, w = 0;
    }
   // cout << len << endl;
    ll lens = 0, flag = -1;
    for (int i = 0; i < len; i++) {
        if (a[i] == '0'+flag) lens++;
        else {
            sum += lens*lens;
            lens = 1;
        }
       // cout << i << ' ' << lens << endl;
        flag = a[i] - '0';
    }
    sum += lens*lens;
    ll ans = sum;
    for (int i = 0; i < len; i++) {
        //cout << i << ' ' << l_b[i] << ' ' << r_b[i] << endl;
        ll tmp;
        if (a[i] == '0') {
            tmp = sum - ss(l_w[i] + r_w[i] + 1);
            if (l_w[i]+r_w[i] > l_b[i]+r_b[i]) {
                continue;
            }
            else {
                ll hh = ss(l_w[i]+r_w[i]) + ss(l_b[i] + r_b[i]+1) - ss(l_b[i]) - ss(r_b[i]);
                ans = max(ans, hh+tmp);
            }
        }
        else {
            tmp = sum - ss(l_b[i] + r_b[i] + 1);
            if (l_b[i]+r_b[i] > l_w[i]+r_w[i]) {
                continue;
            }
            else {
                ll hh = ss(l_b[i]+r_b[i]) + ss(l_w[i] + r_w[i]+1) - ss(l_w[i]) - ss(r_w[i]);
                ans = max(ans, hh+tmp);
            }
        }
     //   cout << i << ' ' << ans << ' ' << tmp << endl;
    }
    cout << ans << endl;
}

int main()
{
    int t, cas = 1; cin >> t;
    while (t--) {
        printf("Case #%d: ", cas++);
        solve();
    }
}
