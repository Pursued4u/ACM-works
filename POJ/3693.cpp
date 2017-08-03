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
using namespace std;
const int maxn = 1e5+1e3;
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
int t1[maxn];
int t2[maxn];
int c[maxn];
int Rank[maxn];
int height[maxn];
int sa[maxn];
int RMQ[maxn];
int mm[maxn];
int dp[maxn][20];

bool cmp(int *r,int a,int b,int l){
    return r[a]==r[b]&&r[a+l] == r[b+l];
}
void da(int str[],int sa[],int Rank[],int height[],int n,int m){
    n++;
    int i,j,p,*x=t1,*y=t2;
    for(int i=0;i<m;i++) c[i] = 0;
    for(int i = 0;i <n;i++) c[x[i] = str[i]]++;
    for(int i = 1;i < m; i++) c[i]+=c[i-1];
    for(int i=n-1;i>=0;i--) sa[--c[x[i]]] = i;
    for(int j=1;j<=n;j<<=1){
        p = 0;
        for(int i = n-j;i<n;i++) y[p++] = i;
        for(int i=0;i<n;i++) if(sa[i]>=j) y[p++] = sa[i] - j;
        for(int i=0;i<m;i++) c[i] = 0;
        for(int i=0;i<n;i++) c[x[y[i]]]++;
        for(int i=1;i<m;i++) c[i]+=c[i-1];
        for(int i=n-1;i>=0;i--) sa[--c[x[y[i]]]] = y[i];
        swap(x,y);
        p = 1; x[sa[0]] = 0;
        for(int i=1;i<n;i++){
            x[sa[i]] = cmp(y,sa[i-1],sa[i],j)?p-1:p++;
        }
        if(p>=n) break;
        m = p;
    }
    int k = 0;
    n--;
    for(int i=0;i<=n;i++) Rank[sa[i]] = i;
    for(int i=0;i<n;i++){
        if(k)k--;
        j = sa[Rank[i]-1];
        while(str[i+k]==str[j+k])k++;
        height[Rank[i]] = k;
    }
}
void init_RMQ(int n){
	int m = floor(log(n+0.0)/log(2.0));
	for(int i=1;i<=n;i++) dp[i][0] = height[i];
	for(int i=1;i<=m;i++){
		for(int j=n;j;j--){
			dp[j][i] = dp[j][i-1];
			if(j+(1<<(i-1))<=n)
				dp[j][i] = min(dp[j][i],dp[j+(1<<(i-1))][i-1]);
		}
	}
}
int query_RMQ(int l,int r){
	int a = Rank[l];
	int b = Rank[r];
	if(a>b) swap(a,b);
	a++;
	int m = floor(log(b-a+1.0)/log(2.0));
	return min(dp[a][m],dp[b-(1<<m)+1][m]);
}

char str[maxn];
int s[maxn];
int ans[maxn];
int main(){
    #ifndef ONLINE_JUDGE
        FILEIN;
    #endif
	int ca = 1;
	while(scanf("%s",str)!=EOF){
		if(str[0]=='#') break;
		int len = strlen(str);
		for(int i=0;i<len;i++) s[i] = str[i];
		da(s,sa,Rank,height,len+1,128);
		int maxx = 0;
		int tm = 0;
		init_RMQ(len);
		int cnt = 0;
		for(int l=1;l<len;l++){
			for(int i=0;i<len;i+=l){
				int nl = query_RMQ(i,i+l);
				int tm = nl/l+1;
				int ns = i-(l-(nl%l));
				if(ns>=0&&nl%l){
					if(query_RMQ(ns,ns+l)>=nl)
						tm++;
				}
				if(tm>maxx){
					maxx = tm;
					cnt = 0;
					ans[cnt++] = l;
				}
				else if(tm==maxx){
					ans[cnt++] = l;
				}
			}
		}
		int nlen = -1;
		int st;
		int flag=0;
		for(int i=1;i<=len&&!flag;i++){
			for(int j=0;j<cnt;j++){
				int l = ans[j];
				if(query_RMQ(sa[i],sa[i]+l)>=(maxx-1)*l)
				{
					nlen = l;
					st = sa[i];
					flag = 1;
					break;
				}
			}
		}
		printf("Case %d: ",ca++);
		for(int i=st,j=0;j<nlen*maxx;j++,i++){
			printf("%c",str[i]);
		}
		puts("");
	}
}
