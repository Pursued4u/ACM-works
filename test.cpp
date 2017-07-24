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
#define LOCAL
const int maxn = 5e5+5;
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
//int a[maxn],b[maxn];
int a[40];
ll dp[20][2000][20];
ll dfs(int cnt,ll tot,int mid,int limit){
    if(cnt<0) return !tot;
    if(tot<0) return 0;
    if(!limit&&dp[cnt][tot][mid]!=-1) return dp[cnt][tot][mid];
    ll ans = 0;
    int up = limit?a[cnt]:9;
    for(int i=0;i<=up;i++){
        ll ntot = tot + (cnt-mid)*i;
        ans += dfs(cnt-1,ntot,mid,limit&&i==up);
    }
    if(!limit) dp[cnt][tot][mid] = ans;
    return ans;

}
ll getsum(ll x){
    int cnt = 0;
    while(x){
        a[cnt++] = x%10;
        x/=10;
    }
    ll res = 0;
    int pos = cnt;
    for(int i = 0; i < cnt; i++){
        res += dfs(pos-1,0,i,1);
    }
    return res-(pos-1);

}
int main(){
    #ifdef ONLINE_JUDGE
    #else
      //FILEIN;
    #endif
    int n;
    MEM(dp,-1);
    ll l, r;
    int t =Read();while(t--){
    scanf("%I64d %I64d",&l,&r);
    cout <<getsum(r) - getsum(l-1) << endl;
    }


}
