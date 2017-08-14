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
#define MEM(a,x) memset(a,x,sizoef(a))
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
int vis[10005];
int cnt[105][105];
int c[105][105];
int a[105];
int b[105];
int n,m;
vector<pair<ll,ll> >ve[10005];
void init(){
    CLR(vis);
    CLR(cnt);
    for(int i=1;i<=10000;i++) ve[i].clear();
}
ll work1(int x){
    ll res = 0;
    for(int i=1;i<=n;i++){
        int pos = 0,tmp,sum = 0;
        for(int j=1;j<=m;j++){
            if(c[i][j]!=x) cnt[i][j] = cnt[i-1][j]+1;
            else cnt[i][j] = 0;
            tmp = 1;
            while(pos&&a[pos]>=cnt[i][j]){
                 tmp += b[pos];
                 sum -= a[pos]*b[pos];
                 pos--;
            }
            pos++;
            a[pos] = cnt[i][j];
            b[pos] = tmp;
            sum+=a[pos]*b[pos];
            res+=sum;
        }
    }
    return res;
}
ll work2(int x){
    int sz = ve[x].size();
    ll res = 0;
    for(int i=1;i<(1<<sz);i++){

        int flag = 0;
        ll minx = inf;
        ll miny = inf;
        ll maxx = -1;
        ll maxy = -1;
        for(int j=0;j<sz;j++){
            if((i>>j)&1)
            {
                flag^=1;
                minx = min(minx,ve[x][j].fi);
                maxx = max(maxx,ve[x][j].fi);
                miny = min(miny,ve[x][j].se);
                maxy = max(maxy,ve[x][j].se);
            }
        }

        ll tmp = (n-maxx+1)*(minx)*(miny)*(m-maxy+1);
        if(flag) res+=tmp;
        else res-=tmp;
    }
    return res;
}
pair<ll,ll>pr;
int main()
{
    int t = Read();
    while(t--){
        init();
        int now = 0;
        n = Read(); m = Read();
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
            int x = Read();
            if(!vis[x])vis[x] = ++now;
            c[i][j] = vis[x];
            pr.fi = i;pr.se = j;
            ve[vis[x]].PB(pr);
        }
        ll res = 0;
        ll tot = 1ll*n*(n+1ll)*1ll*m*(m+1ll)/4;
        for(int i=1;i<=now;i++){
            if(ve[i].size()>10)res+=tot-work1(i);
            else res+=work2(i);
        }

        printf("%.9f\n",db(res)/db(tot));
    }
}
