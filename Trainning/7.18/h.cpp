#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>
using namespace std;
#define maxn 100005
#define PB(x) push_back(x)
vector<int>g[maxn];
int m,n,ans,pla;

void dfs(int x,int dep,int fa)
{
    if(ans<dep)
    {
        ans=dep;
        pla=x;
    }
    for(int i=0;i<g[x].size();i++)
    {
        int u=g[x][i];
        if(u==fa)
        continue;
        dfs(u,dep+1,x);

    }
}
int main()
{
    //cin.sync_with_stdio(false);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int m,n;
        scanf("%d %d",&m,&n);
        for(int i=1;i<=m;i++)
        g[i].clear();
        for(int i=1;i<m;i++)
        {
            int a ,b;
            cin >> a >> b;
            g[a].PB(b);
            g[b].PB(a);
        }

        dfs(1,1,-1);
        ans=0;
        dfs(pla,1,-1);
        while(n--)
        {

        int q;
        cin >> q;

        int ansr=0;
        if(q<=ans)
        cout << q-1 << endl;
        else
        {
            cout << 2*(q-ans)+ans-1 << endl;
        }
        }

    }
}
