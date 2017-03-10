#include<cstdio>
#include<iostream>
#include<climits>
#include<cstring>
#include<map>
using namespace std;
#define CLR(x) memset(x,0,sizeof(x))
#define maxn 20
#define dbg(x) cout << #x << " = " << x << endl;
const int INF = INT_MAX;
int m,n;
int dx[5]={0,1,0,-1,0};
int dy[5]={1,0,0,0,-1};
char mapp[maxn][maxn];
int cur[maxn][maxn];




bool safe(int x, int y)
{
    if(x>=0&&x<m&&y>=0&&y<n)
    return true;
    return false;
}

int getstatus(int x,int y)
{
    int cnt;
    if(mapp[x][y]=='X')
    cnt=1;
    else
    cnt=0;
    for(int i=0;i<5;i++)
    {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(safe(nx,ny))
        cnt+=cur[nx][ny];
    }
    return cnt&1;
}

int calc()
{
    for(int i=1;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(getstatus(i-1,j))
            cur[i][j]++;
        }
    }
    for(int i=0;i<n;i++)
        if(getstatus(m-1,i))
            return -1;
    int num=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            num+=cur[i][j];
        }
    }
    return num;
}
void solve()
{
    int ansr = INF;
    for(int i=0;i<1<<n;i++)
    {
        CLR(cur);
        for(int j=0;j<n;j++)
        {
            cur[0][n-j-1]=(i>>j)&1;
        }
        int anss = calc();
        if(anss < ansr && anss!=-1)
        {
            ansr = anss;
        }

    }
    if(ansr ==INF)
        cout << "Damaged billboard.\n";
    else
        cout << "You have to tap " << ansr << " tiles.\n";

}
int main()
{

    while(scanf("%d %d",&m,&n)!=EOF)
    {

    if(!m&&!n)
    break;
    CLR(cur);
    for(int i=0;i<m;i++)
        scanf("%s",mapp[i]);
    solve();
    }


}
