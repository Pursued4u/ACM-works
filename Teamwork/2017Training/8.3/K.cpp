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
string num[10];
void init() {
	rep(i, 0, 10)
	num[i] = "";
	num[0] = "6990996";
	num[1] = "0880880";
	num[2] = "6886116";
	num[3] = "6886886";
	num[4] = "0996880";
	num[5] = "6116886";
	num[6] = "6116996";
	num[7] = "6880880";
	num[8] = "6996996";
	num[9] = "6996886";
}
char in[7][24];
int main()
{
	int t; scanf("%d", &t);
	init();
	while(t--) {
		for(int i=0;i<7;i++) scanf("%s",in[i]);
		string a[4];
		for(int i=0;i<7;i++){
			int t = 0;
			for(int j=3;j>=0;j--){
				if(in[i][j]=='X'){
					t+=1<<(j);
				}
			}
			a[0]+=(t+'0');
		}
		for(int i=0;i<7;i++){
			int t = 0;
			for(int j=3;j>=0;j--){
				if(in[i][j+5]=='X'){
					t+=1<<(j);
				}
			}
			a[1]+=(t+'0');
		}
		for(int i=0;i<7;i++){
			int t = 0;
			for(int j=3;j>=0;j--){
				if(in[i][j+12]=='X'){
					t+=1<<(j);
				}
			}
			a[2]+=(t+'0');
		}
		for(int i=0;i<7;i++){
			int t = 0;
			for(int j=3;j>=0;j--){
				if(in[i][j+17]=='X'){
					t+=1<<(j);
				}
			}
			a[3]+=(t+'0');
		}
	for(int i=0;i<4;i++){
		if(i==2) cout << ":";

		for(int j=0;j<10;j++){
			if(a[i]==num[j])
				cout <<j;
		}

	}
	cout << endl;
	}
	return 0;
}
