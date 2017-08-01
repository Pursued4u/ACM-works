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

ll dp[20][1<<11][11];
int a[20];
int update(int x,int now){
    for(int i=x;i<10;i++){
        if(now&(1<<i)) return now^(1<<i)|(1<<x);
    }
    return now|1<<x;
}
int getk(int x){
    int cnt = 0;
    while(x){
        x = x&(x-1);
        cnt++;
    }
    return cnt;

}
int k;
ll l,r;
ll dfs(int pos,int st,int z,int limit){
    if(pos<0) return getk(st)==k;
    if(!limit&&dp[pos][st][k]!=-1) return dp[pos][st][k];
    int up = limit?a[pos]:9;
    ll res = 0;
    for(int i=0;i<=up;i++){
        int nz = z||i;
        int nst = nz?update(i,st):0;
        res += dfs(pos-1,nst,nz,limit&&i==up);
    }
    if(!limit) dp[pos][st][k] = res;
    return res;
}
ll getsum(ll x){
    int pos = 0;
    while(x){
        a[pos++] = x%10;
        x/=10;
    }
    return dfs(pos-1,0,0,1);
}
int main(){
    int t = Read();
    MEM(dp,-1);
    int ca = 1;
    while(t--){

        scanf("%I64d %I64d %d",&l,&r,&k);
        printf("Case #%d: ",ca++);
        cout << getsum(r)- getsum(l-1) <<endl;
    }
}


