#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include<vector>
#include<set>
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
#define dbg(x)
using namespace std;
const int maxn = 1<<20;
typedef long long ll;
typedef double db;
const int inf = INT_MAX;
const ll INF = LLONG_MAX;
const ll mod = 998244353ll;
ll mul(ll x,ll y){return x*y%mod;}
ll q_mul(ll a, ll b){ ll ans = 0;while(b){if(b & 1){ans=(ans+a)%mod;} b>>=1;a=(a+a) % mod;}return ans;}
ll q_pow(ll x , ll y){ll res=1;while(y){if(y&1) res=mul(res,x) ; y>>=1 ; x=mul(x,x);} return res;}
ll inv(ll x) { return q_pow(x, mod-2); }
bool vis[maxn];
int p[maxn], sz;
void init() {
	for(int i=2; i<1024; ++i) {
		if(vis[i]) continue;
		for(int j=i*i; j<maxn; j+=i)
			vis[j] = true;
	}
	for(int i=2; i<1e6; ++i)
		if(!vis[i]) p[sz++] = i;
}
ll ans[maxn], rr[maxn];
ll mycal(ll& N, ll a)  {
	ll ret=0;
	while(N%a==0) {
		++ret;
		N/=a;
	}
	return ret;
}
int main()
{
	init();
	int t; scanf("%d", &t);
	while(t--) {
		long long l, r, kk;
		scanf("%I64d%I64d%I64d", &l, &r, &kk);
		rep(i, 0, r-l+1) {
			ans[i] = 1;
			rr[i] = l+i;
		}
		for(int i=0; i<sz&&p[i]<r+1; ++i) {
			ll k=(l+p[i]-1)/p[i];
			dbg(p[i]);
			for(ll j=k*p[i]; j<r+1; j+=p[i]) {
				ll e=mycal(rr[j-l],p[i]);
				dbg(j);
				dbg(e);
				dbg(kk);
				ans[j-l]= ans[j-l]*(kk*e%mod+1)%mod;
				dbg(ans[j-l]);
			}
		}
		ll res = 0;
		for(int i=0; i<r-l+1; ++i) {

			if(rr[i]>1) ans[i] = ans[i]*(kk+1)%mod;
			res = (res+ans[i])%mod;
			dbg(ans[i]);
		}
		printf("%I64d\n", res);
	}
	return 0;
}
