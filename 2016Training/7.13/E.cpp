#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;
int vis[8][8];
int m,n;
int ans;
int MAX(int a,int b)
{
    if(a>b)
    return a;
    return b;
}
void dfs(int x,int y,int cnt )
{
    if(x>=m)
    {
        ans=MAX(ans,cnt);
        return;
    }
    if(y>=n)
    {
        dfs(x+1,0,cnt);
        return;
    }
    if(vis[x][y]==1)
    {
        dfs(x,y+1,cnt);
        return;
    }
    dfs(x,y+1,cnt);
    int t,flag=0;
    for(t=x-1;t>=0;t--)
    {
        if(vis[t][y])
        break;
    }
    for(int i=t-1;i>=0;i--)
    {
        if(vis[i][y])
        {
            if(vis[i][y]==2)
            {
                flag=1;
            }
            break;
        }
    }
    if(flag) return;
    for(t=y-1;t>=0;t--)
    {
        if(vis[x][t])
            break;
    }
    for(int j=t-1;j>=0;j--)
    {
        if(vis[x][j])
        {
            if(vis[x][j]==2)
            {
             flag=1;
            }
            break;
        }
    }
    if(flag) return;
    vis[x][y]=2;
    dfs(x,y+1,cnt+1);
    vis[x][y]=0;
}
int main()
{
    int t;
    while(scanf("%d %d %d",&m,&n,&t)!=EOF)
    {


    memset(vis,0,sizeof(vis));
    for(int i=0;i<t;i++)
    {
        int x,y;
        cin >> x >> y;
        vis[x][y]=1;
    }
    ans=0;
    dfs(0,0,0);
    cout << ans << endl;
    }
}
