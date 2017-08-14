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
const int maxn = 50+5;
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
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
char dir[] = {'U','D','L','R'};
char mapp[maxn][maxn];
char s[maxn];
int dis[maxn][maxn][maxn];
struct node{
    int v,x,y,z;
    node(int vv,int xx,int yy,int zz):v(vv),x(xx),y(yy),z(zz){}
    bool operator < (const node &a) const {
        return v>a.v;
    }
};

int m,n,len;
int sx,sy,ex,ey;
void init(){
    for(int i=0;i<55;i++){
        for(int j=0;j<55;j++)
            for(int k=0;k<55;k++)
            dis[i][j][k] = 3000;
    }
}
void Dijkstra(){
    init();
    dis[sx][sy][0] = 0;
    priority_queue<node>pq;
    pq.push(node(dis[sx][sy][0], sx, sy, 0));
    while(pq.size()){
        node cur = pq.top();
        pq.pop();
        if(cur.x==ex&&cur.y==ey) break;
        if(cur.z<len){
            int k = 0;
            for(;k<4;k++) if(dir[k]==s[cur.z+1]) break;
            int nx = cur.x+dx[k];
            int ny = cur.y+dy[k];
            if(mapp[nx][ny]==0||mapp[nx][ny]=='#'){
                nx = cur.x;
                ny = cur.y;
            }
            if(dis[nx][ny][cur.z+1]>dis[cur.x][cur.y][cur.z]){
                dis[nx][ny][cur.z+1] = dis[cur.x][cur.y][cur.z];
                pq.push(node(dis[nx][ny][cur.z+1],nx,ny,cur.z+1));
            }
        }
        if(cur.z<len&&dis[cur.x][cur.y][cur.z+1]>dis[cur.x][cur.y][cur.z]+1)
        {
            dis[cur.x][cur.y][cur.z+1] = dis[cur.x][cur.y][cur.z]+1;
            pq.push(node(dis[cur.x][cur.y][cur.z+1],cur.x,cur.y,cur.z+1));
        }
        for(int i=0;i<4;i++){
            int nx = cur.x+dx[i];
            int ny = cur.y+dy[i];
            if(mapp[nx][ny]==0||mapp[nx][ny]=='#') continue;
            if(dis[nx][ny][cur.z]>dis[cur.x][cur.y][cur.z]+1){
                 dis[nx][ny][cur.z] = dis[cur.x][cur.y][cur.z] +1;
                 pq.push(node(dis[nx][ny][cur.z],nx,ny,cur.z));
            }
        }
    }
}
int main(){
    cin >> m >> n;
    for(int i=1;i<=m;i++){
        scanf("%s",mapp[i]+1);
        for(int j=1;j<=n;j++){
            if(mapp[i][j]=='R') sx = i,sy = j;
            if(mapp[i][j]=='E') ex = i,ey = j;
        }
    }
    scanf("%s",s+1);
    len = strlen(s+1);
    Dijkstra();
    int ans = inf;
    for(int i=0;i<=len;i++){
        ans = min(ans,dis[ex][ey][i]);
    }
    cout << ans << endl;
    
}



