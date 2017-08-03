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
const int maxn = 4e5+5;
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
int r[maxn];
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
char s1[maxn];
char s2[maxn];
int s[maxn];
int main(){

    #ifndef ONLINE_JUDGE
        FILEIN;
    #endif
    scanf("%s",s1);
    scanf("%s",s2);
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    for(int i=0;i<len1;i++) s[i] = s1[i];
    s[len1] = 127;
    for(int i=0;i<len2;i++) s[i+len1+1] = s2[i];
    da(s,sa,Rank,height,len1+len2+2,128);
    int len = len2+len1+2;
    int maxx = 0;
    for(int i=2;i<=len;i++){
		if(height[i]>maxx){
			if(sa[i]<len1&&sa[i-1]>len1){
				maxx = height[i];
			}
			if(sa[i-1]<len1&&sa[i]>len1)
				maxx = height[i];
		}
    }
    cout << maxx <<endl;

}
