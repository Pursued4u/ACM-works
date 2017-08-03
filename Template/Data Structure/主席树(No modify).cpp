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
using namespace std;
const int maxn = 1e5+5;
typedef long long ll;
typedef double db;
const int inf = INT_MAX;
const ll INF = LLONG_MAX;
const ll mod = 1e9 + 7;
ll mul(ll x,ll y)
{
    return x*y%mod;
}
ll q_mul(ll a, ll b)
{
    ll ans = 0;
    while(b)
    {
        if(b & 1)
        {
            ans=(ans+a)%mod;
        }
        b>>=1;
        a=(a+a) % mod;
    }
    return ans;
}
ll q_pow(ll x, ll y)
{
    ll res=1;
    while(y)
    {
        if(y&1) res=q_mul(res,x) ;
        y>>=1 ;
        x=q_mul(x,x);
    }
    return res;
}
ll inv(ll x)
{
    return q_pow(x, mod-2);
}
int Read()
{
    int x = 0, F = 1;
    char C = getchar();
    while (C < '0' || C > '9')
    {
        if (C == '-') F = -F;
        C = getchar();
    }
    while (C >= '0' && C <= '9')
    {
        x = x * 10 - '0' + C, C = getchar();
    }
    return x * F;
}
vector<int>v;
struct node
{
    int l,r,sum;
} T[maxn*20];
int k,n;
int a[maxn];
int cnt,root[maxn];
int getid(int x)
{
    return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
void update(int l,int r,int &x,int y,int pos)
{

    T[++cnt] = T[y];
    T[cnt].sum++, x = cnt;
    if(l<r)
    {
        int mid = (l+r)/2;
        if(mid>=pos) update(l,mid,T[x].l,T[y].l,pos);
        else update(mid+1,r,T[x].r,T[y].r,pos);
    }
}
int query(int l,int r,int x,int y,int k)
{
    if(l==r) return l;
    int mid = (l+r)/2;
    int sum = T[T[y].r].sum - T[T[x].r].sum;
    if(sum<k) return query(l,mid,T[x].l,T[y].l,k-sum);
    else return query(mid+1,r,T[x].r,T[y].r,k);

}
void init() {
    cnt =0;
    v.clear();
}
int myfind(int st, int ll, int rr, int v) {
    //printf("%d %d", st, ll);
    while(ll<=rr) {
        int mid = ll+rr>>1;
        int a = query(1,n,st-1, mid, k);
        if(a>v) rr = mid-1;
        else ll = mid+1;
    }
    return rr;
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    //FILEIN;
#endif
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        init();
        for(int i=1; i<= n; i++)
        {
            scanf("%d",&a[i]);
            v.PB(a[i]);
        }
        sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end());
        a[0] = 0;
        for(int i=1; i<=n; ++i)
            a[i] = getid(a[i]);
        for(int i=1; i<=n; i++)
        {
            update(1,n,root[i],root[i-1],a[i]);
        }
        ll ans=0;
        for(int i=1; i<=n; ++i) {
            int j=i+k-1;
            while(j<=n) {
                int tmp=query(1,n, root[i-1], root[j], k);
                int nj = myfind(i,j,n, tmp);
                ans += v[tmp]*(nj-j+1);
                j = nj+1;
            }
            //puts("");
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
