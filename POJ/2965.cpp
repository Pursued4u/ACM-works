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
#define eps 1e-8
#define sf(x) scanf("%d",&x)
#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)
#define lowbit(x) x&(-x)
#define fi first
#define se second
#define endl '\n'
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

template <class T>
inline void rd(T &x) {
    char c = getchar(); x = 0;while(!isdigit(c)) c = getchar();
    while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar();  }
}
char s[10][10];
int a[10][10];
void get(int x,int y){
	for(int i=0;i<4;i++){
		a[x][i]++;
		a[i][y]++;
	}
	a[x][y]++;
}
int main(){
	for(int i=0;i<4;i++)
	scanf("%s",s[i]);
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(s[i][j]=='+')
				get(i,j);
		}
	}
	int ans = 0;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			ans+=a[i][j]&1;
		}
	}
	cout << ans << endl;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(a[i][j]&1){
				cout << i+1 << " " << j+1 << endl;
			}
		}
	}

}
