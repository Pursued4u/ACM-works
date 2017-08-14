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
#define FILEOUT freopen("bigout.txt", "w", stdout)
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
#define _ixvii0iv
using namespace std;
const int maxn = 1e6+1e3;
const int maxq = 1e4+1e3;
const int maxp = 1024;
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
bool vis[maxp];
int p[maxp], psz;
vector<int> myfact[maxn];
int r[maxn];
void init() {
    rep(i, 2, maxn)
        r[i] = i;
    rep(i, 2, 32) {
        if(vis[i]) continue;
        for(int j=i*i; j<maxp; j+=i)
            vis[j]=true;
    }
    psz=0;
    rep(i, 2, maxp)
        if(!vis[i]) p[psz++] = i;
    rep(i, 0, psz) {
        for(int j=p[i]; j<maxn; j+=p[i]) {
            myfact[j].push_back(p[i]);
            while(r[j]%p[i]==0)
                r[j]/=p[i];
        }
    }
    rep(i, 2, maxn)
        if(r[i]>1) myfact[i].push_back(r[i]);
}
int phi(int a, int x) {
    int ret=0, m=myfact[x].size();
    for(int st=0; st<(1<<m); ++st) {
        int tmp=1, selsz=0;
        for(int j=0; j<m; ++j)
            if(st>>j&1) {
                tmp*=myfact[x][j];
                ++selsz;
            }
        if(selsz&1) ret -= a/tmp;
        else ret  += a/tmp;
    }
    return ret;
}
ll ans[maxn];
int ask[maxn];
int myceil(int a, int b) {
    int ret=a/b;
    if(a%b) ++ret;
    return ret;
}
ll cal(int x) {
    int m=int(sqrt(x+0.5));
    ll ret=phi(x-1, x);
    for(int i=1; i<m; ++i) {
        ret +=phi(myceil(x,i)-1,x);
    }
    ret -= m*phi(myceil(x,m)-1,x);
    m=myceil(x,m)-1;
    for(int i=1; i<=m; ++i)
        if(__gcd(i,x)==1) ret += myceil(x,i);
    return ret;
}
int main(){
    //FILEOUT;
    int maxask=0, sz=0;
    while (~scanf("%d", ask+sz)) {
        if(ask[sz]>maxask) maxask=ask[sz];
        ++sz;
    }
    int st=clock();
    ans[1]=1, ans[2]=3, ans[3]=8;
    ++maxask;
    init();
    printf("1\n2\n5\n");
    for(int i=4; i<maxask; ++i) {
        ans[i] = (cal(i)+ans[i-1])%mod;
        //printf("%lld\n", ans[i]-ans[i-1]);
    }
    rep(i, 0, sz) printf("%I64d\n", ans[ask[i]]);
    int ed=clock();
    cout << (ed-st)/1000.0 << endl;
    return 0;
}
