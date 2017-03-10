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
const int maxn = 1e3+5;
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
char mapp[maxn][maxn];
int vis[maxn][maxn];
typedef pair<int,int>P;
int m,n;
    int sx,sy;
    int ex,ey;
int dis[maxn][maxn];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int flag1=0;
int flag2=0;
int ans1;
void bfs()
{
    queue<P>que;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        dis[i][j]=inf;
    }
    que.push(P(ex,ey));
    dis[ex][ey]=0;
    while(que.size())
    {
        P p = que.front();
        que.pop();
        if(p.first==sx&&p.se==sy)
        {
            flag1=1;
        }
        if(mapp[p.fi][p.se]=='$')
        {
            flag2=1;
            ans1=dis[p.fi][p.se];
        }
        if(flag1&&flag2)
        break;
        for(int i=0;i<4;i++)
        {
            int nx=p.fi+dx[i];
            int ny=p.se+dy[i];
            if(nx>=0&&nx<m&&ny>=0&&ny<n&&mapp[nx][ny]!='#'&&!vis[nx][ny])
            {
                que.push(P(nx,ny));
                vis[nx][ny]=1;
                dis[nx][ny]=dis[p.fi][p.second]+1;
                //cout << dis[nx][ny] << ' ' << p.fi << ' ' << p.se << ' ' << nx << ' ' << ny << endl;;
            }

        }
    }

}
int main()
{
    while(scanf("%d %d",&m,&n)!=EOF)

    {
    ans1=inf;
    CLR(vis);
    flag1=0;
    flag2=0;


    rep(i,0,m) scanf("%s",mapp[i]);
    rep(i,0,m)
    rep(j,0,n)
    {
        if(mapp[i][j]=='@')
        {
            sx=i;
            sy=j;
        }
        else if(mapp[i][j]=='%')
        {
            ex=i;
            ey=j;
        }

    }
    //cout << ex << " " << ey <<endl;
    bfs();
    /*for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout << dis[i][j] <<endl;
        }
    }*/
    //cout << ans1 << dis[sx][sy] <<endl;
    if(dis[sx][sy]<ans1)
    cout << "Yes" << endl;
    else
    cout << "No" <<endl;
    }
}



