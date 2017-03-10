#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <climits>
#define inf 0x3f3f3f
using namespace std;
char map[205][205];
int vis[205][205];
int dir[][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
int n, m, ans;

void dfs(int x, int y, int len)
{
    if (x<0||x>=n||y<0||y>=m)
        return;
    if (len>=ans)
        return;
    if (map[x][y]=='x')
        len++;
    if (map[x][y]=='r')
    {
        if (len<ans)
            ans = len;
        return;
    }
    vis[x][y]=1;
    for (int i = 0; i < 4; i++)
    {
        int xx = x+dir[i][0];
        int yy = y+dir[i][1];
        if (map[xx][yy]!='#' && !vis[xx][yy])
        {

            dfs(xx, yy, len+1);

        }
    }
          vis[x][y] = 0;
}


int main()
{
    while(cin >> n >> m)
    {
    memset(vis,0,sizeof(vis));

    for (int i = 0; i < n; i++)
    {
        scanf("%s", &map[i]);
    }
    int x, y;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j]=='a')
            {
                x = i;
                y = j;
            }
        }
    }
    ans=inf;
    int len=0;
    dfs(x, y, len);
    if (ans!=inf)
        cout << ans << endl;
    else
        cout << "Poor ANGEL has to stay in the prison all his life." << endl;
    }
}
