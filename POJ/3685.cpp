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
ll cal(ll x,ll y){
    return x*x+y*y+x*y+100000*(x-y);
}
ll  m,n;
bool check(ll x){
    ll ans = 0;
    for(ll i=1;i<=m;i++){
        ll l = 1,r = m;
        while(l<r){
            ll mid = (l+r)/2;
            if(cal(mid,i)>x) r = mid-1;
            else l = mid+1;
        }
        //dbg(r);
        ans+=l-1;
       // cout << i << " " << r << endl;
    }
    return ans>=n;
}
int main(){
    #ifdef ONLINE_JUDGE
    #else 
        FILEIN;
    #endif
    int t =Read();
    while(t--){
        scanf("%lld %lld",&m,&n);
        ll l = -1e12;
        ll r =  1e12;
        while(l<=r){
            ll mid = (l+r)/2;
            if(check(mid)) r = mid-1;
            else l = mid+1;
        }
        cout << l << endl;

    }
}