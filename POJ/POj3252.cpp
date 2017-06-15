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
#define LOCAL
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
int dp[40][100];
int a[40];
int dfs(int pos,int tot,int limit,int z){
    if(pos==-1) return tot>=38&&z;
    if(!limit&&~dp[pos][tot]&&z) return dp[pos][tot];
    int up = limit?a[pos]:1;
    int res = 0;
    for(int i=0;i<=up;i++){
        int ntot = z?(tot+(i?-1:1)):tot-i;
        res+=dfs(pos-1,ntot,limit&&i==up,z||i);
    }
    if(!limit&&z) dp[pos][tot] = res;
    return res;
}
int solve(int x){
    int pos = 0;
    while(x){
        a[pos++] = x&1;
        x>>=1;
    }
    return dfs(pos-1,38,1,0);
}

int main(){
    #ifdef LOCAL 
     FILEIN;
    #endif  
    int m,n;
    MEM(dp,-1);
    cin >> m >> n;
    //cout << solve(12) << endl;
    cout << solve(n)-solve(m-1) << endl;
}