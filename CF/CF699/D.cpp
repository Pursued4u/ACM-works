#include<bits/stdc++.h>
#define FILEIN freopen("in.txt", "r", stdin)
#define FILEOUT freopen("output.txt", "w", stdout)
#define CLOSEIO ios::sync_with_stdio(false)
#define PI acos(-1)
#define eps 1e-8
#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)
using namespace std;
const int maxn = 2e5+100;
typedef long long LL;
const int inf = ((1LL<<29)-10);
const LL mod = 1000000007;
int fa[maxn];
int vis[maxn];
int a[maxn];
int findset(int x)
{
    return x==fa[x]?fa[x]:fa[x]=findset(fa[x]);
}
void init(int n)
{
    for(int i=0;i<=n;i++)
    fa[i]=i;
    memset(vis,0,sizeof(vis));
}
int main()
{
    int n;
    cin >> n;
    int ans=0;
    init(n);
    int flag=-1;
    int ans1=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]==i&&flag==0)
        {
            flag=-1;
            ans=i;
        }
    }
    for(int i=1;i<=n;i++)
    {
        int fx=findset(i);
        int fy=findset(a[i]);
        if(fx!=fy)
            fa[fx]=fy;
        else
        {
            if(flag==-1)
            {
                ans=i;
                flag=0;
            }
            ans1++;
            a[i]=ans;
        }
    }
    cout << ans1+flag << endl;
    for(int i=1;i<=n;i++)
    {
        if(i==n)
        cout << a[i] << endl;
        else
        cout << a[i] << " " ;
    }
}
