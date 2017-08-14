#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include<vector>
#include<stack>
#include<climits>
#include<ctime>
#include<queue>
#define FILEIN freopen("in.txt", "r", stdin)
#define FILEOUT freopen("out.txt", "w", stdout)
#define CLOSEIO ios::sync_with_stdio(false)
#define PI acos(-1)
#define CLR(a) memset(a,0,sizeof(a))
#define MEM(a,x) memset(a,x,sizeof(a))
#define eps 1e-8
#define sf(x) scanf("%d",&x)
#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)
#define lowbit(x) x&(-x)
#define fi first
#define se second
#define rep(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define drep(a,b,c) for(int (a)=(b);(a)>(c);--(a))
#define dbg(x) cout << #x << "=" << x << endl
#define _ixvii0iv
using namespace std;
const int maxn = 1e5+5;
typedef long long ll;
typedef double db;
const int inf = INT_MAX;
const ll INF = LLONG_MAX;
const ll mod = 1e9 + 7;
ll mul(ll x,ll y){return x*y%mod;}
ll q_mul(ll a, ll b){ ll ans = 0;while(b){if(b & 1){ans=(ans+a)%mod;} b>>=1;a=(a+a) % mod;}return ans;}
ll q_pow(ll x , ll y){ll res=1;while(y){if(y&1) res=q_mul(res,x) ; y>>=1 ; x=q_mul(x,x);} return res;}
ll inv(ll x) { return q_pow(x, mod-2); }
int Read() {
    int x = 0, F = 1; char C = getchar();
    while (C < '0' || C > '9') { if (C == '-') F = -F; C = getchar(); }
    while (C >= '0' && C <= '9') { x = x * 10 - '0' + C, C = getchar(); }
    return x * F;

}
const int MAXL=1e5+100;
int L,A[MAXL],B[MAXL],C[MAXL],changed[MAXL],changedCnt,cur=1,T,ans[MAXL],fa[MAXL];
int l,r,m;
int root(int x){return fa[x]==x?x:fa[x]=root(fa[x]);}
void merge(int a,int b){a=root(a);b=root(b);fa[changed[++changedCnt]=a]=b;}
void init()
{
    scanf("%d",&L);
    for(int i=1;i<=L;i++) scanf("%d%d%d",&A[i],&B[i],&C[i]);
    for(int i=1;i<=L;i++) fa[i]=i;
}
bool judge(int a,int b)
{
    for(int i=1;i<=changedCnt;i++)
        fa[changed[i]]=changed[i];
    changedCnt=0;
    for(int i=a;i<=b;i++)
        if(C[i]==1) merge(A[i],B[i]);
    for(int i=a;i<=b;i++)
        if(C[i]==0 && root(A[i])==root(B[i])) return false;
    return true;
}
void solve()
{
    while(cur<=L)
    {
        l=r=1;
        while(judge(cur,cur+r-1))
            r=max(r*2,L-cur+1);
        r--;
        while(l!=r)
        {
            m=(l+r)/2+1;
            if(judge(cur,cur+m-1))
                l=m;
            else
                r=m-1;
        }
        ans[++T]=l+1;
        cur+=l+1;
    }
    printf("%d\n",T);
    for(int i=1;i<=T;i++) printf("%d\n",ans[i]);
}
int main()
{
    init();
    solve();
}
