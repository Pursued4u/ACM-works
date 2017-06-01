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
ll dp[25][20][2];
int a[25];
ll getsum(int po,int pre,int fg, int limit){
   if(po<0) return 1; 
   if(!limit && dp[po][pre][fg]!=-1) return dp[po][pre][fg];
   int up = limit?a[po]:9;
   ll res = 0;
   for(int i=0;i<=up;i++){
       if(fg==0||abs(pre-i)>=2){
           res+=getsum(po-1,i,fg||i,limit&&(i==up));
       }
   }
   if(!limit) return dp[po][pre][fg] = res; 
   return res;
}
ll get(ll x){
    int po = 0;
    while(x){
        a[po++] = x%10;
        x/=10;
    }
    return getsum(po-1,0,0,1);
}
int main(){
    ll l,r;
    cin >> l >> r;
    MEM(dp,-1);
    cout << get(r) - get(l-1) << endl;
}