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

template <class T>
inline void rd(T &x) {
    char c = getchar(); x = 0;while(!isdigit(c)) c = getchar();
    while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar();  }
}
int dx[] = {0,0,1,0,-1};
int dy[] = {1,-1,0,0,0};
char s[6][6];
int a[6][6];
int tmp[6][6];
void change(int x,int y){
	for(int i=0;i<4;i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		tmp[nx][ny] ^=1;
	}
}

int ans;
void get(int x){
	for(int i=0;i<(1<<4);i++){
		int cur = 0;int flag = 0;
		memcpy(tmp,a,sizeof(a));
		for(int k=0;k<4;k++) if(i&(1<<k)) change(1,k+1),cur++;
		for(int j=1;j<=3;j++){
			for(int k=1;k<=4;k++){
				if(tmp[j][k]!=x){
					change(j+1,k);
					cur++;
				}
			}
		}
		for(int j=1;j<=4;j++){
			if(tmp[4][j]!=x){
				flag=1;break;
			}
		}
		if(!flag) ans = min(ans,cur);
	}
}
int main(){
	ans = inf;
	for(int i=1;i<=4;i++) scanf("%s",s[i]+1);
	for(int i=1;i<=4;i++)
		for(int j=1;j<=4;j++)
		a[i][j] = s[i][j]=='b';
		get(0);
		get(1);

	if(ans==inf){
		cout << "Impossible" << endl;
	}
	else
	cout << ans <<endl;
}
