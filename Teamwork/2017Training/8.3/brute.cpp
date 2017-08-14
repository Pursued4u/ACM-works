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
int m, len;
char s[maxn];
int main()
{
	int t; scanf("%d", &t);
	while(t--) {
		scanf("%d", &m);
		scanf("%s", s);
		len = strlen(s);
		int ret=0;
		for(int i=0; i<len; ++i)
		for(int j=i+1; j<len; ++j) {
			int k=0, cur=0;
			while(i+k<j-k&&cur+abs(s[i+k]-s[j-k])<=m) {
				cur += abs(s[i+k]-s[j-k]);
				++k;
			}
			ret = max(ret, k);
		}
		printf("%d\n", ret);
	}
	return 0;
}
