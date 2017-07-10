#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include<set>
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
int fa[maxn];
int son[maxn];
int pre[maxn];
int vis[maxn];
int a[maxn];
typedef pair<int,int>pr;

vector<int>ans[maxn];
int Find(int x){
    return fa[x]==x?x:fa[x]=Find(fa[x]);
}
void Union(int a,int b){
    int faa = Find(a);
    int fab = Find(b);
    fa[fab]=faa;
}
set<pair<int,int> >st;
set<pair<int,int> >::iterator it;
int n; 
void init(){
    for(int i=1;i<=n;i++){
        fa[i]=i;
        son[i]=2;
        vis[i]=0;
        ans[i].clear();
    }
    st.clear();
}
int main()
{
    
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        init();
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        for(int i=1;i<=n;i++){
            it = st.upper_bound(MP(a[i],i));
            if(it==st.begin()){
                st.insert(MP(a[i],i));
            }
            else{
                it--;
                pr tmp = *it;
                son[tmp.se]--;
                if(son[tmp.se]<=0)
                st.erase(it);
                st.insert(MP(a[i],i));
                Union(tmp.se,i);
            }
        }
        int cnt = 0;
        for(int i=1;i<=n;i++){
            int now = Find(i);
            if(!vis[now])  { 
            vis[now]=1;
            cnt++;
            }
            ans[now].PB(i);
        }
        cout << cnt << "\n";
        for(int i=1;i<=n;i++){
            if(!vis[i]) continue;
            cout << ans[i].size();
            for(int j=0;j<ans[i].size();j++){
                printf(" %d",ans[i][j]);
            }
            cout << "\n";
        }
    }
}
