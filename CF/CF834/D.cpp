#pragma comment(linker, "/STACK:1024000000,1024000000")
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
int a[maxn];
int n;
int q;
int last[maxn];
int dp[maxn];
int pre[maxn];
struct node{
    int l,r;
    ll maxx,lazy;
    void update(ll x){
        maxx+=x;
        lazy+=x;
    }
}tree[maxn*4];

void push_up(int x){
    tree[x].maxx = max(tree[x<<1].maxx,tree[x<<1|1].maxx);
}
void push_down(int x){
    int lazyval = tree[x].lazy;
    if(lazyval){
        tree[x<<1].update(lazyval);
        tree[x<<1|1].update(lazyval);
        tree[x].lazy = 0;
    }
}
void build(int x,int l,int r){
    tree[x].l = l, tree[x].r =r;
    tree[x].maxx = tree[x].lazy = 0;
    if(l==r){
        tree[x].maxx = dp[l];
    }
    else{
        int mid = l+r>>1;
        build(x<<1,l,mid);
        build(x<<1|1,mid+1,r);
        push_up(x);
    }
}
void update(int x,int l,int r,ll v){
    int L = tree[x].l;
    int R = tree[x].r;
    if(l<=L&&R<=r){
        tree[x].update(v);
    }
    else{
        push_down(x);
        int mid = L+R>>1;
        if(mid>=l) update(x<<1,l,r,v);
        if(r>mid) update(x<<1|1,l,r,v);
        push_up(x);
    }
}
ll query(int x,int l,int r){
    int L = tree[x].l;
    int R = tree[x].r;
    if(l<=L&&R<=r){
    return tree[x].maxx;
    }
    else{
        push_down(x);
        ll ans1 = -inf;
        ll ans2 = -inf;
        int mid = L+R>>1;
        if(mid>=l) ans1=query(x<<1,l,r);
        if(r>mid) ans2=query(x<<1|1,l,r);
        push_up(x);
        return max(ans1,ans2);
    }
}
int main(){
    n = Read();
    int k = Read();
    for(int i=1;i<=n;i++) last[i] = -1;
    for(int i=0;i<n;i++){
        a[i] = Read();
        pre[i] = last[a[i]];
        last[a[i]] = i;
    }
    for(int i=0;i<=n;i++) dp[i] =0;
    for(int i=0;i<k;i++){
        build(1,0,n);
        dp[0] = 0;
        for(int j=1;j<=n;j++){
            update(1,pre[j-1]+1,j-1,1);
            dp[j] = query(1,0,j-1);
        }
    }
    cout << dp[n] << endl;
}
