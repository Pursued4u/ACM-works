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
char a[30][30];
struct point{
	char x;
	int tm;
}b[50],c[5];

bool cmp(point a,point b){
	if(a.tm==b.tm){
		return a.x<b.x;
	}
	return a.tm>b.tm;
}
int main(){

	int n,m;
 b[0].x = 'A';
 b[1].x = 'E';
 b[2].x = 'G';
 b[3].x = 'D';
 b[4].x = 'C';
 while(scanf("%d %d",&m,&n)!=EOF){
	if(n+m==0) break;

 for(int i=0;i<m;i++){
	scanf("%s",a[i]);
 }
 for(int i=0;i<5;i++){
	b[i].tm = 0;
 }
 for(int i=0;i<m;i++){
	for(int j=0;j<n;j++){
		for(int k=0;k<5;k++){
			if(a[i][j]==b[k].x)
				b[k].tm++;
		}
	}
}
	sort(b,b+5,cmp);
	int k = 0;
	for(int i=0;i<5;i++){
	if(b[i].tm){
		c[k].x = b[i].x;
		c[k++].tm = b[i].tm;
	}

}
for(int i=0;i<k;i++){
	printf("%c %d",c[i].x,c[i].tm);
	if(i!=k-1)printf(" ");
	else cout << "\n";
}

 }
