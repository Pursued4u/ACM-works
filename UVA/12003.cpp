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
#define _ixvii0iv
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
const int sz = 2048;
ll a[maxn];
ll blk[maxn/sz+1][sz];

ll n,m,u;
int k;
int j;
inline int findd(int np,ll x){
    int l = 0;
    int r = np==k?j:sz;
    r--;
    while(l<=r){
        int mid = l+r>>1;
        if(blk[np][mid]<x) l = mid+1;
        else r = mid-1;
    }
    return l;
}
void init(){
    n = Read();
    m = Read();
    u = Read();
    k = 0;
    j = 0;
    for(int i=0;i<n;i++) {
        a[i] = Read();
        blk[k][j++] = a[i];
        if(j==sz){ k++; j=0;}
    }
    for(int i=0;i<k;i++)sort(blk[i],blk[i]+sz);
    if(j) sort(blk[k],blk[k]+j);
}
inline ll query(int l, int r,int v){
    int bl = (l)/sz;
    int br = (r)/sz;
    ll k = 0;
    if(bl==br){
        for(int i = l;i<= r;i++) if(a[i]<v) k++;
    }
    else{
        for(int i=l;i<(bl+1)*sz;i++) if(a[i]<v) k++;
        for(int i=br*sz;i<=r;i++) if(a[i]<v) k++;
        for(int i =bl+1;i<br;i++){
            int pos = findd(i,v);
            k+=pos;
        }
    }
    return k;
}

inline void change(int pos, ll x){
    if(a[pos]==x) return;
    ll old = a[pos]; int np = 0; int nblk = pos/sz;
    a[pos] = x;
    //int nsz = nblk==k?j:sz;
    np = findd(nblk,old);
    blk[nblk][np]  =  x;
    while(np<sz-1&&blk[nblk][np]>blk[nblk][np+1]){
        swap(blk[nblk][np],blk[nblk][np+1]);
        np++;
    }
    while(np>0&&blk[nblk][np]<blk[nblk][np-1]){
        swap(blk[nblk][np],blk[nblk][np-1]);
        np--;
    }
}
void solve(){
    init();
    for(int i=0;i<m;i++){
        int l,r,pos;ll v;
        l =Read();
        r = Read();
        v = Read();
        pos = Read();
        l--,r--,pos--;
        ll k = query(l,r,v);
        change(pos,u*k/(r-l+1));
    }
    for(int i=0;i<n;i++){
        printf("%lld\n",a[i]);
    }
}
int main(){
    int t = 1;
    int ca = 1;
    while(t--) solve();
    return 0;
}
