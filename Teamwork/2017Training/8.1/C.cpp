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
const int maxn = 4e5+5;
typedef long long ll;
typedef double db;
const int inf = INT_MAX;
const ll INF = LLONG_MAX;
const ll mod = 1e9 + 7;
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
int query(int x, int y, int k) {
    return query(1,n, root[x-1], root[y], k);
}
int bit[maxn];
void init() {
    cnt =0;
    memset(bit, 0, sizeof(bit));
}
int Ask(int pos) {
    int ret=0;
    while(pos) {
        ret += bit[pos];
        pos -= lowbit(pos);
    }
    return ret;
}
void Add(int pos, int v) {
    while(pos<=n) {
        bit[pos] += v;
        pos += lowbit(pos);
    }
}
int findl(int l, int r, int ed, int v, int k) {
    if(r>ed-k+1) r=ed-k+1;
    while(l<r) {
        int m=(l+r)/2;
        int res = query(m, ed, k);
        if(res<v) r=m;
        else l=m+1;
    }
    while(l>1&&query(l,ed,k)<=v) --l;
    return l;
}
int findr(int st, int l, int r, int v, int k) {
    if(st+k-1>l) l=st+k-1;
    while(l<r) {
        int m=(l+r)/2;
        int res = query(st,m,k);
        if(res>v) r=m;
        else l=m+1;
    }
    while(l>1&&query(st,l,k)>v) --l;
    return l;
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
            scanf("%d", a+i);
        a[0] = 0;
        for(int i=1; i<=n; i++)
            update(1,n,root[i],root[i-1],a[i]);
        ll ans=0;
        for(int i=1; i<=n; ++i) {
            int nk, l, r;
            nk = i-Ask(a[i]);
            Add(a[i], 1);
            if(nk>k)  nk = k;
            printf("%d,%d:\n", i, nk);

            while(nk) {
                int l, r, nl, nr;
                l = findl(1, i, i, a[i], nk);
                if(n-l+1<k) break;
                if(nk==1) nl = i+1;
                else nl=findl(1, i, i, a[i], nk-1);
                if(nk==k) r=i-1;
                else r = findr(l, l, n, a[i], k-1);
                nr = findr(l, l, n, a[i], k);
                ans += 1ll*(nl-l)*(nr-r)*a[i ];
                printf("%d\t%d\t%d\t%d\n", l, nl, r, nr);
                l = nl;
                r = nr;
                --nk;
            }
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
