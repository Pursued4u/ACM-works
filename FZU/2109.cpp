#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include<vector>
#include<stack>
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
ll dp[20][20][2][2];
int a[20];
ll dfs(int pos,int pre,int odd,int fg, int limit){
    if(pos<0) return 1;
    if(dp[pos][pre][fg][odd]!=-1&&!limit) return dp[pos][pre][fg][odd];
    ll res = 0;
    int up = limit?a[pos]:9;
    for(int i=0;i<=up;i++){
        if(i>=pre&&odd) res+=dfs(pos-1,i,0,fg&&!i,limit&&(i==up));
        else if(i<=pre&&!odd) res += dfs(pos-1,i,1,fg&&!i,limit&&(i==up));
    }
    if(!limit) dp[pos][pre][fg][odd] = res;
    return res;
}
ll getsum(ll x){
    int pos = 0;
    while(x){
        a[pos++] = x%10;
        x/=10;
    }
    pos = pos-1;
    return dfs(pos,9,0,1,1);
}
int main(){
    int t;
    MEM(dp,-1);
    cin >> t;
    while(t--){
        ll l,r;
        cin >> l>> r;
        cout << getsum(r)- getsum(l-1) << endl;
    }
}