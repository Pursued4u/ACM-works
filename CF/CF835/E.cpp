#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#define rep(i,x,y) for (int i=x;i<=y;i++)
#define dep(i,y,x) for (int i=y;i>=x;i--)
#define sz(x) (int)(x.size())

using namespace std;

typedef long long LL;
typedef unsigned long long uLL;

const int maxn=5000+7;

int n,l,r,cnt[maxn],F[maxn][maxn];
bool vis[maxn][maxn],pal[maxn][maxn];
char s[maxn];

int solve(int l,int r)
{
    if (!pal[l][r]) return 0;
    if (vis[l][r]) return F[l][r];
    vis[l][r]=1;

    int mid=(l+r)>>1;
    if ((r-l)&1) F[l][r]=min(solve(l,mid),solve(mid+1,r))+1; else F[l][r]=min(solve(l,mid-1),solve(mid+1,r))+1;
    return F[l][r];
}

void init()
{
    memset(pal,0,sizeof(pal));
    rep(i,1,n)
    {
        l=i,r=i;
        while ((l>0)&&(r<=n))
        {
            if (s[l]!=s[r]) break;
            pal[l][r]=true;

            --l,++r;
        }

        l=i,r=i+1;
        while ((l>0)&&(r<=n))
        {
            if (s[l]!=s[r]) break;
            pal[l][r]=true;

            --l,++r;
        }
    }
}

int main()
{
    scanf("%s",s+1);
    n=strlen(s+1);

    init();
    rep(i,1,n) vis[i][i]=1,F[i][i]=1;
    rep(i,1,n)
        rep(j,i,n)
        {
            if (!vis[i][j]) solve(i,j);
        }

        rep(i,1,n) rep(j,1,n) cout << F[i][j] << endl;
    rep(i,1,n) rep(j,1,n) ++cnt[F[i][j]];
    for(int i=1;i<=n;i++){
        cout << cnt[i] << endl;
    }
    dep(i,n-1,1) cnt[i]+=cnt[i+1];
    rep(i,1,n-1) printf("%d ",cnt[i]);
    printf("%d\n",cnt[n]);

    // system("pause");
    return 0;
}

