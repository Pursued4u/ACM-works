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
const int maxn = 1e2+5;
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
int n,np,nc,m;
int resi[maxn][maxn];
deque<int>act;
int h[maxn];
int ef[maxn];
int s,t;
int V;
void push_relabel(){
    int i,j;
    int sum = 0;
    int u,v,p;
    CLR(h);

    h[s] = V;
    CLR(ef);ef[s]=inf;
    ef[t]= -inf;
    act.push_front(s);
    while(!act.empty()){
        u = act.back();
        act.pop_back();
        for(int i=1;i<=V;i++){
            v = i;
            if(resi[u][v]<ef[u]) p = resi[u][v];
            else p = ef[u];
            if(p>0&&(u==s||h[u]==h[v]+1)){
                resi[u][v]-=p;
                resi[v][u]+=p;
                if(v==t) sum+=p;
                ef[u]-=p;ef[v]+=p;
                if(v!=s&&v!=t) act.push_front(v);
            }
        }
        if(u!=s&&u!=t&&ef[u]>0){
            h[u]++;
            act.push_front(u);
        }
    }
    printf("%d\n",sum);

}
int main()
{
    int i,j;
    int u,v,val;
    while(scanf("%d %d %d %d",&n,&np,&nc,&m)!=EOF){
        s = n+1;
        t = n+2;
        V = n+2;
        CLR(resi);
        for(i=0;i<m;i++){
            while(getchar()!='(');
            scanf("%d,%d)%d",&u,&v,&val);
            resi[u+1][v+1] = val;
        }
        for(i=0;i<np;i++){
            while(getchar()!='(');
            scanf("%d)%d",&u,&val);
            resi[s][i+1] = val;
        }
        for(i=0;i<nc;i++){
            while(getchar()!='(');
            scanf("%d)%d",&u,&val);
            resi[u+1][t] = val;
        }
        push_relabel();
    }

}
