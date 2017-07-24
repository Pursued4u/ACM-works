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
ll LCM =2520;
int dig[20];
ll dp[20][2555][50];
int ind[5000];
ll gcd(ll a ,ll b){
    return !b?a:gcd(b,a%b);
}
ll lcm(ll a,ll b){
    return a/gcd(a,b)*b;
}
ll dfs(int pos,int prezero,int presum,int prelcm,bool limit){
    if(pos==-1) return presum%prelcm==0;
    if(!limit&&dp[pos][presum][ind[prelcm]]!=-1) return dp[pos][presum][ind[prelcm]];
    ll res = 0;
    int up = limit?dig[pos]:9;
    for(int i=0;i<=up;i++){
        int nowsum = (presum*10+i)%LCM;
        int nowlcm = prelcm;
        if(i)nowlcm = lcm(nowlcm,i);
        res+=dfs(pos-1,prezero&&!i,nowsum,nowlcm,(limit&&i==up));
    }
    if(!limit) dp[pos][presum][ind[prelcm]] = res;
    return res;
}
ll get(ll x){
    int pos = 0;
    while(x){
        dig[pos++] = x%10;
        x/=10;
    }
    return dfs(pos-1,1,0,1,1);
}
void init(){
    int num =0;
    for(int i=1;i<=2520;i++){
        if(!(LCM%i)) ind[i] = num++;
    }
    cout << num <<endl;
}
int main(){
    int t;cin >> t;
    init();
    MEM(dp,-1);
    while(t--){
        ll l,r;
        cin >> l >> r;
        cout << get(r) - get(l-1) << endl;
    }

}
