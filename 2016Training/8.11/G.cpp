#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<cstring>
#include<queue>
#include<set>
#include<string>
#include<map>
#define inf 9223372036854775807
#define INF 9e7+5
#define PI acos(-1)
using namespace std;
typedef long long LL;
typedef double db;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
const db eps = 1e-9;

using namespace std;

#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
const int MAX = 1005;
LL ans;
struct Tree
{
    LL l,r;
    LL sum,add;
};
Tree tree[MAX*4];

void pushup(LL x)
{
    LL tmp=2*x;
    tree[x].sum=tree[tmp].sum+tree[tmp+1].sum;
}

void pushdown(LL x)
{
    LL tmp=2*x;
    tree[tmp].add+=tree[x].add;
    tree[tmp+1].add+=tree[x].add;
    tree[tmp].sum+=tree[x].add*(tree[tmp].r-tree[tmp].l+1);
    tree[tmp+1].sum+=tree[x].add*(tree[tmp+1].r-tree[tmp+1].l+1);
    tree[x].add=0;
}

void build(int l,int r,int x)
{
    tree[x].l=l;
    tree[x].r=r;
    tree[x].add=0;
    if(l==r)
    {
        tree[x].sum = 0;
        return ;
    }
    int tmp=x<<1;
    int mid=(l+r)>>1;
    build(l,mid,tmp);
    build(mid+1,r,tmp+1);
    pushup(x);	 //如果在建树的过程中给sum赋值，记得后面要pushup
}


void update(LL l,LL r,LL c,LL x)
{
    if(r<tree[x].l||l>tree[x].r)
        return ;
    if(l<=tree[x].l&&r>=tree[x].r)
    {
        tree[x].add+=c;
        tree[x].sum+=c*(tree[x].r-tree[x].l+1);
        return ;
    }
    if(tree[x].add)
        pushdown(x);
    LL tmp=x<<1;
    update(l,r,c,tmp);	//  !!!
    update(l,r,c,tmp+1);
    pushup(x);
}


void query(LL l,LL r,LL x)
{
    if(r<tree[x].l||l>tree[x].r)		 //要更新的区间不在该区间上
        return ;
    if(l<=tree[x].l&&r>=tree[x].r)	  //要更新区间包括了该区间
    {
        ans+=tree[x].sum;
        return ;
    }
    if(tree[x].add)
        pushdown(x);
    LL tmp=x<<1;
    LL mid=(tree[x].l+tree[x].r)>>1;
    if(r<=mid)
        query(l,r,tmp);
    else if(l>mid)
        query(l,r,tmp+1);
    else
    {
        query(l,mid,tmp);
        query(mid+1,r,tmp+1);
    }
}
int aa[maxn], bb[maxn], sum, ans1;
int main()
{
    int T , n , m;
    scanf("%d",&T);
    for (int cas = 1 ; cas <= T ; cas ++)
    {
        cout << "__________"<<endl;
        scanf("%d%d",&n,&m);
        sum = ans = ans1 = 0;
        for(int i=0; i<n; i++)
            scanf("%d", aa+i);
        for(int i=0; i<n; i++)
        {
            scanf("%d", bb+i);
            if(bb[i]!=aa[i]) sum++;
        }
        cout << sum << endl;
        build(1 , n , 1);
        while (m --)
        {
            int a , b;
            scanf("%d%d",&a,&b);
            update(a , b , 1, 1);
        }
        for(LL i=1; i<=n; i++)
        {
            ans = 0;
            query(i, i, 1);
            if(ans > 1) ans1++;
        }
        if(ans1>=sum) puts("Yes");
        else puts("No");
    }
    return 0;
}
