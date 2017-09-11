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
#define _ixvii0iv
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
int n=4,m;
int ans;
bool vis[4][1000];

inline bool inMat(int x,int y){
    return x > 0 && x <= n && y > 0 && y <= m;
}

void DFS(int x,int y){
    if(y > m){
        DFS(x+1,1);
        return ;
    }
    if(vis[x][y]){
        DFS(x,y+1);
        return;
    }

    if(x == 5){
        ans++;
        return;
    }
    if(inMat(x,y) && inMat(x,y+1) && !vis[x][y] && !vis[x][y+1]){
        vis[x][y] = vis[x][y+1] = true;
        DFS(x,y+2);
        vis[x][y] = vis[x][y+1] = false;
    }
    if(inMat(x,y) && inMat(x+1,y) && !vis[x][y] && !vis[x+1][y]){
        vis[x][y] = vis[x+1][y] = true;
        DFS(x,y+1);
        vis[x][y] = vis[x+1][y] = false;
    }
}

int main(){
    m = Read(),ans = 0;
    DFS(1,1);
    cout << ans << endl;
}
