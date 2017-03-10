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

void solve() {
    int a1, a2, b1, b2, a3, a4, b3, b4;
    while (cin >> a1 >> b1 >> a2 >> b2) {
        cin >> a3 >> b3 >> a4 >> b4;
        int vis[maxn]; memset(vis, 0, sizeof(vis));
        for (int i = a3; i <= b3; i++) {
            for (int j = a4; j <= b4; j++) {
                vis[i+j]++;
            }
        }
        int ans = 0, ansr = 0;
        for (int i = a1; i <= b1; i++) {
            for (int j = a2; j <= b2; j++) {
                int tmp = i+j, cnt = 0;
                for (int k = tmp-1; k >= 1; k--) {
                    ans += vis[k];
                }
                for (int k = tmp+1; k <= 205; k++) {
                    ansr += vis[k];
                }
               // cout << i << ' ' << j << ' ' << ans <<endl;
            }
        }
        //cout << ans <<endl;
        ll hh = (b1-a1+1)*(b2-a2+1)*(1+b3-a3)*(1+b4-a4);
        //cout << hh << endl;
        if (ans > ansr) cout << "Gunnar";
        else if (ans == ansr) cout << "Tie";
        else cout << "Emma";
        cout << endl;
    }
}

int main()
{
    solve();
}
