#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include<vector>
#include<stack>
#include<set>
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
const int maxn = 2e5+5;
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
vector<int>G[maxn];
int op[maxn];
int col[maxn];
set<int>st;
void init(int n){
    MEM(col,-1);
    CLR(op);
}
vector<int>hp;
void bfs(int u)
{
    queue<int>que;
    que.push(u);
    st.erase(u);
    col[u] = 0;
    int cnt = 0;
    while(que.size()){
        int cur = que.front();
        que.pop();
        cnt++;
        if(op[cur]==1){
            for(int i=0;i<G[cur].size();i++){
                int v = G[cur][i];
                if(~col[v]) continue;
                col[v] = col[cur]^1;
                st.erase(v);
                que.push(v);
            }
        }
        else{
            for(int i=0;i<G[cur].size();i++){
                int v = G[cur][i];
                if(~col[v]) continue;
                hp.PB(v);
                st.erase(v);
            }
            for(auto it=st.begin();it!=st.end();it++){
                int v = *it;
                if(~col[v]) continue;
                col[v] = col[cur]^1;
                que.push(v);
            }
            st.clear();
            for(int i=0;i<hp.size();i++){
                st.insert(hp[i]);
            }
            hp.clear();
        }
    }
}
int main()
{

    int n = Read();
    init(n);
    char s[2];int m;
    for(int i=1;i<=n;i++){
        scanf("%s %d",s,&m);
        if(s[0]=='C') op[i]=1;
        else op[i]=-1;
        if(op[i]==1&&!m||op[i]==-1&&m==n-1){
            cout << "Impossible\n";
            return 0;
        }
        for(int j=0;j<m;j++){
            int x = Read();
            G[i].PB(x);
        }
        st.insert(i);
    }

    for(int i=1;i<=n;i++){
        if(!~col[i]) bfs(i);
    }
    for(int i=1;i<=n;i++){
        printf("%c",col[i]?'V':'S');
    }
    cout << "\n";
}

/*
5
C 3 3 4 5
C 3 3 4 5
C 2 1 2
C 2 1 2
C 2 1 2
4
C 2 2 4
N 1 4
N 2 1 4
C 1 1
1
N 0
*/
