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

int a[20];
int dp[12][5000][2];
int sum;
int cal(int x){
    int cnt = 0;
    int cur = 0;
    while(x){
        cnt+=(x%10)*(1<<cur++);
        x/=10;
    }
    return cnt; 
}
int dfs(int pos,int summ,int limit){
    if(pos<0) return summ>=0;
    if(summ<0) return 0;
    if(!limit&&dp[pos][summ][limit]!=-1) return dp[pos][summ][limit];
    int up = limit?a[pos]:9;
    int res = 0;
    for(int i=0;i<=up;i++){
        res+=dfs(pos-1,summ-i*(1<<pos),limit&&i==up);
    }
    if(!limit) dp[pos][summ][limit] = res;
    return res;
}
int solve(int y,int x){
    int pos = 0;
    while(x){
        a[pos++] = x%10;
        x/=10;
    }
    sum = cal(y);
    return dfs(pos-1,sum,1);
}
int main(){
    int ca = 1;
    int t; cin >> t;
    MEM(dp,-1);
    while(t--){
        int a,b;
        cin >> a >> b;
        printf("Case #%d: ",ca++);
        cout << solve(a,b) << endl;
    }
}