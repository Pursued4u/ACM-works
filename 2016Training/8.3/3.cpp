#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include<vector>
#include<queue>
#define FILEIN freopen("in.txt", "r", stdin)
#define FILEOUT freopen("output.txt", "w", stdout)
#define CLOSEIO ios::sync_with_stdio(false)
#define PI acos(-1)
#define CLR(a) memset(a,0,sizeof(a))
#define MEM(a,x) memset(a,x,sizoef(a))
#define eps 1e-8
#define scf(x) scanf("%d",&x)
#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)
#define lowbit(x) x&(-x)
#define db double
#define rep(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define drep(a,b,c) for(int (a)=(b);(a)>(c);--(a))
#define dbg(x) cout << #x << "=" << x << endl
int n,k;
using namespace std;
const int maxn = 5e4+5;
typedef long long ll;
const int inf = ((1ll<<29)-10);
const ll mod = 1000000007;
int mul(int x,int y){return 1LL*x*y%mod;}
int qpow(int x , int y){int res=1;while(y){if(y&1) res=mul(res,x) ; y>>=1 ; x=mul(x,x);} return res;}
int fa[maxn];
int Rank[maxn];
void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
        Rank[i]=0;
    }
}
int Find(int x)
{
    if(x!=fa[x])
    {
        int fx=Find(fa[x]);
        Rank[x]=(Rank[x]+Rank[fa[x]])%3;
        fa[x]=fx;
    }
    return fa[x];
}
bool Union(int x,int y,int type)
{
    int fx,fy;
    fx=Find(x);
    fy=Find(y);
    if(fx==fy)
    {
        if((Rank[y]-Rank[x]+3)%3!=type)return true;
        else return false;
    }
    fa[fy]=fx;
    Rank[fy]=(Rank[x]-Rank[y]+type+3)%3;
    return false;
}
int main()
{
    cin >> n >> k;
    int ans=0;
    init(n);
    for(int i=0;i<k;i++)
    {
        int op,a,b;
        cin >> op >> a >> b;
        if(a>n||b>n||(op==2&&a==b))
        {
            ans++;
            continue;
        }
        else if(Union(a,b,op-1))
        ans++;
    }
    cout << ans << endl;
}
