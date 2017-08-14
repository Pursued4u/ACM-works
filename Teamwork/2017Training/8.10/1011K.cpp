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

int test2(int a, int b, int c, int ab, int bc, int ac, int abc) {
	int onA = a-ab-ac+abc,onB = b-ab-bc+abc,onC = c-ac-bc+abc,
		onAB = ab-abc,onAC = ac-abc,onBC = bc-abc,onABC= abc;
	if(onA < 0 || onB < 0 ||onC < 0|| onAB < 0||onAC < 0||onBC < 0||onABC < 0 ) return 0;
	return onA+onB+onC+onAB+onBC+onAC+onABC;
}
int mycal() {
	int a, b, c, ab, bc, ac, abc;
	sf("%d%d%d%d%d%d%d", &a, &b, &c, &ab, &bc, &ac, &abc);

	return test2(a,b,c,ab,bc,ac, abc);

//	return a+b+c-ab-bc-ac+abc;
}

int main(){
    int t; sf("%d", &t);
    while(t--) {
		int n;
		sf("%d", &n);
		int ans=0, tmp;
		while(n--) {
			tmp=mycal();
			ans = max(ans, tmp);
		}
		printf("%d\n", ans);

    }
    return 0;
}
