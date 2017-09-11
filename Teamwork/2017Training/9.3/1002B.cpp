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
const int maxn = 1e5+6e4;
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

struct SegTree{
    int minv[maxn*4], n;
    int al, ar;
    int pos, x;
    void build(int n) {
        this->n = n;
        MEM(minv,0x3f);
    }
    void update(int id, int l, int r) {
        if(l==r) {
            minv[id]=x;
            return;
        }
        int mid=l+r>>1;
        if(pos<=mid) update(id<<1, l, mid);
        else update(id<<1|1, mid+1, r);
        minv[id] = min(minv[id<<1], minv[id<<1|1]);
    }
    void update(int pos, int x) {
        this->pos = pos;
        this->x = x;
        update(1, 1, n);
    }
    int query(int id, int l, int r) {
        if(al<=l&&r<=ar) {
            return minv[id];
        }
        int mid=l+r>>1;
        int ans=0x3f3f3f3f;
        if(al<=mid&&ar>=l) ans = query(id<<1, l, mid);
        if(al<=r&&ar>mid) ans = min(ans, query(id<<1|1, mid+1, r));
        return ans;
    }
    int query(int l, int r) {
        al=l, ar=r;
        return query(1, 1, n);
    }
}tree[51];
int que[maxn][4], sz;
int b[maxn], tot;
void solve() {
    tot=0;
    for(int i=0; i<sz; ++i) {
        b[tot++] = que[i][2];
        if(que[i][0]==2)
            b[tot++] = que[i][3];
    }
    sort(b, b+tot);
    tot = unique(b, b+tot)-b;

}
int main() {
    while (true) {
        int x;
        scanf("%d", &x);
        if(x==0||x==3) {
            solve();
            if(x==3) break;
            else sz=0;
        }
        else {
            que[sz][0]=x;
            for(int i=1; i<4; ++i) {
                scanf("%d", que[sz]+i);
            }
            ++sz;
        }
    }
    return 0;
}
