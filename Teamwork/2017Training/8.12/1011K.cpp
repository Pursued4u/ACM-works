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
#define sf(x) scanf("%d",&x)
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
ll a[] = {1,
199981,
199982,
199983,
199984,
199985,
199986,
199987,
199988,
199989,
199990,
200000,
200001,
1599981,
1599982,
1599983,
1599984,
1599985,
1599986,
1599987,
1599988,
1599989,
1599990,
2600000,
2600001,
13199998,
35000000,
35000001,
35199981,
35199982,
35199983,
35199984,
35199985,
35199986,
35199987,
35199988,
35199989,
35199990,
35200000,
35200001,
117463825,
500000000,
500000001,
500199981,
500199982,
500199983,
500199984,
500199985,
500199986,
500199987,
500199988,
500199989,
500199990,
500200000,
500200001,
501599981,
501599982,
501599983,
501599984,
501599985,
501599986,
501599987,
501599988,
501599989,
501599990,
502600000,
502600001,
513199998,
535000000,
535000001,
535199981,
535199982,
535199983,
535199984,
535199985,
535199986,
535199987,
535199988,
535199989,
535199990,
535200000,
535200001,
1111111110};
int main(){
	string s;

	while(cin >> s){
	if(s.length()>12){
		cout << 83 << " " << 1111111110 <<  endl;
	}
	else{
		ll tmp = 0;
		for(int i=0;i<s.length();i++){
			tmp*=10;
			tmp+=s[i]-'0';
		}
		int x =upper_bound(a,a+83,tmp)-a;
		cout << x << " " << a[x-1] << endl;
	}
	}
}
