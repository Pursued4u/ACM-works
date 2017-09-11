#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<set>
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
#define endl '\n'
using namespace std;
const int maxn = 3e5+5;
typedef long long ll;
typedef double db;
const int inf = INT_MAX;
const ll INF = LLONG_MAX;
const ll mod = 1e9 + 7;
ll mul(ll x,ll y){return x*y%mod;}
ll q_mul(ll a, ll b){ ll ans = 0;while(b){if(b & 1){ans=(ans+a)%mod;} b>>=1;a=(a+a) % mod;}return ans;}
ll q_pow(ll x , ll y){ll res=1;while(y){if(y&1) res=q_mul(res,x) ; y>>=1 ; x=q_mul(x,x);} return res;}
ll inv(ll x) { return q_pow(x, mod-2); }
inline ll Read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
std::vector<pair<ll,ll> > v;
ll a[maxn];
int ca = 1;

int n,k;
inline bool check(int sz){
    v.clear();
    for(int i=0;i<sz;i++){
        v.PB(MP(0ll,0ll));
    }
    if(!sz) return true;
    for(int i=0;i<n;){
        for(int j=0;j<sz;j++){
            while(a[i]<2*v[j].fi&&i<n){
                i++;
            }
            if(i>=n) break;
            v[j].fi = a[i];
            v[j].se++;
            i++;
        }
    }
    for(int i=0;i<sz;i++){
        if(v[i].se<k) return false;
    }
    return true;

}
void solve(){

    n = Read();
    k = Read();
    for(int i=0;i<n;i++){
        a[i] = Read();
    }
    sort(a,a+n);
    int l = 0,r =n/k;
    ll ans;
    while(l<=r){
        int mid = l+r>>1;
        if(check(mid)) ans=mid,l =mid+1;
        else r = mid-1;
    }
    printf("Case #%d: %d\n",ca++,ans);
}
int main(){
    int t = Read();
    while(t--) solve();
    return 0;
}
