
#include <stdio.h>
#include <string.h>
char ma[15][15];
int mark[15][15];
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
int flag,step;
void dfs(int x,int y)
{
    ma[x][y]='x';
    for (int i=0;i<4;i++)
    {
        int nx=dx[i]+x,ny=dy[i]+y;
        if(ma[nx][ny]=='.'&&!mark[nx][ny])
        {
            step++;
            mark[nx][ny]=1;
        }

        if(ma[nx][ny]=='o')
            dfs(nx,ny);
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for (int cas=1;cas<=t;cas++)
    {
        for (int i=0;i<=10;i++)
        {
            for (int j=0;j<=10;j++)
               ma[i][j]='x';
        }
        memset(ma,0,sizeof(ma));
        flag=0;
        for (int i=1;i<=9;i++)
            scanf("%s",ma[i]+1);
        for (int i=1;i<=9;i++)
        {
            for (int j=1;j<=9;j++)
            {
                if(ma[i][j]=='o')
                {
                    step=0;
                    memset(mark,0,sizeof(mark));
                    dfs(i,j);
                    if(step==1)
                        flag=1;
                }
                if(flag)
                    break;
            }
            if(flag)
                break;
        }
        printf("Case #%d: ",cas);
        if(flag)
            printf("Can kill in one move!!!\n");
        else
            printf("Can not kill in one move!!!\n");
        /*
        for (int i=1;i<=9;i++)
        {
            for (int j=1;j<=9;j++)
                printf("%c",ma[i][j]);
            printf("\n");
        }
        */
    }
    return 0;
}
