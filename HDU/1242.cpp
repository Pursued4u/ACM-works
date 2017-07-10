#include<bits/stdc++.h>
#define FILEIN freopen("in.txt", "r", stdin)
#define FILEOUT freopen("output.txt", "w", stdout)
#define CLOSEIO ios::sync_with_stdio(false)
#define PI acos(-1)
#define eps 1e-8
#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)
using namespace std;
const int maxn = 2e2+100;
typedef long long LL;
const int inf = ((1LL<<29)-10);
const LL mod = 1000000007;

int ansr;
char a[maxn][maxn];
int vis[maxn][maxn];
int m,n;
int dir [][2] ={{0,-1},{0,1},{1,0},{-1,0}};
bool check(int x,int y)
{
    if(x<0||x>=m||y<0||y>=n)
    return true;
    if(a[x][y]=='#')
    return true;
    if(vis[x][y])
    return true;
    return false;
}
void dfs(int x,int y,int cnt)
{
    if(check(x,y))
    return;
    if(cnt>=ansr)
    return;
    if(a[x][y]=='r')
    {
        if(cnt<ansr)
        {
            ansr=cnt;
        }
        return;
    }
    if(a[x][y]=='x')
    cnt++;
    vis[x][y]=1;
    for(int i=0;i<4;i++)
    {
        int nx=x+dir[i][0];
        int ny=y+dir[i][1];
        dfs(nx,ny,cnt+1);
    }
    vis[x][y]=0;
}
int main()
{
    #ifdef LOCAL
    //FILEIN;
    //FILEOUT;
    //CLOSEIO;
    #endif
    while(cin >> m >> n)
    {

        memset(vis,0,sizeof(vis));
        int ax,ay;
        for(int i=0;i<m;i++)
            scanf("%s",a[i]);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                    if(a[i][j]=='a')
                    {
                        ax=i;
                        ay=j;
                    }
            }
        }

        ansr=inf;
        dfs(ax,ay,0);

        if(ansr!=inf)
        cout << ansr << endl;
        else
        cout << "Poor ANGEL has to stay in the prison all his life." << endl;
    }

}
