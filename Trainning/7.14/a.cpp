#include<bits/stdc++.h>
using namespace std;
int a[105][105];
int main()
{
    int m,n;
    cin >> m >> n;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin >> a[i][j];
        }
    }
    int minn=10000;
    int x,y;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            int vis[105];
            int p;
            memset(vis,0,sizeof(vis));
            for(int k=1;k<=m;k++)
            {
                if(a[k][i]&&a[k][j])
                    vis[1]++;
                if(a[k][i]&&!a[k][j])
                    vis[2]++;
                if(!a[k][i]&&a[k][j])
                 vis[3]++;
                if(!a[k][i]&&!a[k][j])
                    vis[4]++;
                p=k;
            }
            sort(vis+1,vis+5);
            //minn=min(vis[4],minn);
            if(vis[4]<minn)
            {
                minn=vis[4];
                x=i;
                y=j;
            }
        }
    }
    cout << minn << endl;
    cout << x << " " << y << endl;

}
