#include<bits/stdc++.h>
using namespace std;
#define maxn 1005
char a[maxn][maxn];
int vis[maxn][maxn];
int dir[][2]={{1,0},{0,1},{-1,0},{0,-1}};
int m,n;
struct pos
{
    int x,y,step,in;
};
queue<pos>q;
bool safe(int x,int y)
{
    return x>=1&&x<=m&&y>=1&&y<=n;
}
void bfs()
{
    while(!q.empty())
    {
        pos tmp=q.front();
        q.pop();
        if(a[tmp.x][tmp.y]=='*')
        continue;
        for(int i=0;i<4;i++)
        {
            int x=tmp.x+dir[i][0];
            int y=tmp.y+dir[i][1];
            if(safe(x,y))
            {
                if(a[x][y]=='.')
                {
                    a[x][y]=tmp.in;
                    vis[x][y]=tmp.step+1;
                    q.push(pos{x,y,tmp.step+1,tmp.in});
                }
                else if(a[x][y]!='#'&&a[x][y]!=tmp.in&&tmp.step+1==vis[x][y])
                    a[x][y]='*';
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> m >> n;
        getchar();
        for(int i=1;i<=m;i++)
        scanf("%s",a[i]+1);
        memset(vis,-1,sizeof(vis));
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[i][j]>='a'&&a[i][j]<='z')
                {
                    q.push(pos{i,j,0,a[i][j]} );
                    vis[i][j]=0;
                }
            }
        }
        bfs();
        for(int i=1;i<=m;i++)
        {
            printf("%s\n",a[i]+1);
        }


    }
}
