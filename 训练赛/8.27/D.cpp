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
const int maxn = 5e4+5;
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

ll pow_mod(ll a, ll b, ll p) {
    ll ret = 1;
    while(b) {
        if(b & 1) ret = (ret * a) % p;
        a = (a * a) % p;
        b >>= 1;
    }
    return ret;
}

ll inv(ll x) {
    return pow_mod(x, mod-2, mod);
}

void solve() {
    ll n, m; cin >> n >> m;
        ll tmp = m, len = 0;
        while (tmp) {
            len++; tmp /= 10;
        }
        ll ans = 0, hh = 1, xx = 1;
        for (int i = 1; i <= len; i++) xx *= 10;
        xx--;
       // xx %= mod;
        while (m) {
            tmp = m % 10; tmp *= hh; hh *= 10;
            //hh %= mod;
            m /= 10;
            ll tt = pow_mod(10, n*len, mod) - 1;
            ans += (((((tmp%mod)*tt%mod))%mod)*inv(xx))%mod;
            ans %= mod;
        }
        cout << ans << endl;
}

int main()
{
    int t; cin >> t;
    while (t--) solve();
}


