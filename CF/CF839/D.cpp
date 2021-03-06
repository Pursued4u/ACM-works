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
const int maxn = 1e6+10;
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
ll a[maxn];
ll b[maxn];
ll p[maxn];

int main() {
    int n;
    cin >> n;
    for (int i=1;i<=n;i++){
    	int x = Read();
    	a[x]++;
	}
	ll ans=0;
	ll x=1;
	for (int i=0;i<=1000000;i++){
		b[i]=x;
		x = (x*2)%mod;
	}
	for (int i=2;i<=1000000;i++) p[i] = i;
	for (int i=2;i<=1000000;i++){
		for (int j=i+i;j<=1000000;j+=i) p[j]-= p[i];
	}
	for (ll i=2;i<=1000000;i++){
		ll cnt=0;
		for (int j=i;j<=1000000;j+=i) cnt+=a[j];
		if (!cnt) continue;
		ans+= (cnt * p[i]) % mod * b[cnt-1] % mod;
		ans %= mod;
	}
	cout << (ans+mod)%mod << endl;
    return 0;
}
