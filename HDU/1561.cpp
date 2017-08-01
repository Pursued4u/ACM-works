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
int val[205];
int dp[205][205]; //dp[i][j]代表以i为根节点 取j个能得到的最大值
vector<int>G[205];
void init(int x){
    CLR(dp);
    for(int i=0;i<=x;i++)G[i].clear();
}

void dfs(int x,int num){
    int sz = G[x].size();
    dp[x][1] = val[x];
    for(int i=0;i<sz;i++){
        if(num<=1) break;
        int v = G[x][i];
        dfs(v,num-1);
        for(int j=num;j>=1;j--){
            for(int k=1;k<=j;k++){
                dp[x][j+1] = max(dp[x][j+1],dp[x][j+1-k]+dp[v][k]);
            }
        }
    }
}
int main(){
    #ifdef ONLINE_JUDGE
    #else
        FILEIN;
    #endif
    int n,m;
    while(scanf("%d %d",&n,&m)&&n+m){
        init(n);
        for(int i=1;i<=n;i++){
            int a = Read();
            val[i] = Read();
            G[a].PB(i);
        }
        dfs(0,m+1);
        cout << dp[0][m+1] << endl;
    }
}
