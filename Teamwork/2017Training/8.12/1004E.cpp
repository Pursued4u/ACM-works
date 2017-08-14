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

int ch(int *a){
	int ans = 0;
	for(int i = 4;i > -1;--i) ans = ans*10+a[i];
	return ans;
}

int dis[1000000+7][3][4];
queue<int>Q;
void BFS(){
	memset(dis,0x7f,sizeof(dis));
	dis[12345][0][0] = 0;Q.push(12345*100);
	int a[10];
	while(!Q.empty()){
		int u = Q.front();Q.pop();
		//printf("%d \n",u/100);
		int st = u%100;
		for(int  i = 0,t= u/100;i < 5;++i){
			a[i] = t%10;t/= 10;
		}
		for(int i = 0,x;i < 4;++i){

				if(a[i] == a[i+1]) continue;
				swap(a[i],a[i+1]);
				x = ch(a);
				if(dis[x][st/10][st%10] > dis[u/100][st/10][st%10]+1){
					Q.push(x*100+st);
					dis[x][st/10][st%10] = dis[u/100][st/10][st%10]+1;
				}
				swap(a[i],a[i+1]);

		}
		// op multi 2
		if(st/10<2) for(int i =  0,t,x;i < 5;++i){
			if(a[i] == 0)  continue;
            t = a[i]; a[i] = a[i]*2%10;
            x = ch(a);
            if(dis[x][st/10+1][st%10] > dis[u/100][st/10][st%10]+1){
					Q.push(x*100+st+10);
					dis[x][st/10+1][st%10] = dis[u/100][st/10][st%10]+1;
			}
			a[i] = t;
		}
		// op add
		if(st%10<3)for(int i = 0,x;i < 5;++i){
			a[i] = (a[i]+1)%10;
			x = ch(a);
            if(dis[x][st/10][st%10+1] > dis[u/100][st/10][st%10]+1){
					Q.push(x*100+st+1);
					dis[x][st/10][st%10+1] = dis[u/100][st/10][st%10]+1;
			}
			a[i] = (a[i]+9)%10;
		}
	}
}

int main(){
	int x,ans; BFS();
	while(~scanf("%d",&x)){
        ans = 0x7f;
		for(int i = 0;i < 3;++i){
			for(int j = 0;j < 4;++j){
                ans = min(ans,dis[x][i][j]);
			}
		}
		printf("%d\n",ans== 0x7f ? -1 : ans);
	}
	return 0;

}
