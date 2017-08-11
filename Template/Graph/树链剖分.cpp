#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <ctime>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define N 100005
#define pb push_back
#define mp make_pair
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define calm (l+r)>>1
    #define FILEIN freopen("in.txt", "r", stdin)
const int INF = 2139062143;

template <class T>
inline void rd(T &x) {
    char c = getchar(); x = 0;while(!isdigit(c)) c = getchar();
    while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar();  }
}
struct Edge
{
    int to,nx;
}edge[N*2];
int val[N];
int head[N],cnt;
void addedge(int u,int v)
{
    edge[cnt] = Edge{v,head[u]};
    head[u] = cnt++;
}
int top[N],son[N],dep[N],siz[N];
int fa[N],Rank[N],tid[N],tot;
inline void dfs1(int u,int father,int d)
{
    dep[u] = d;
    fa[u] = father;
    siz[u] = 1;
    for(int i=head[u];i;i=edge[i].nx)
    {
        int v = edge[i].to;
        if(v==father)continue;
        dfs1(v,u,d+1);
        siz[u] += siz[v];
        if(son[u]==-1 || siz[v]>siz[son[u]])
            son[u] = v;
    }
}
inline void dfs2(int u,int tp)
{
    top[u] = tp;
    tid[u] = ++tot;
    Rank[tot] = u;
    if(son[u]==-1)return;
    dfs2(son[u],tp);
    for(int i=head[u];i;i=edge[i].nx)
    {
        int v = edge[i].to;
        if(v==fa[u] || v==son[u])continue;
        dfs2(v,v);
    }
}
const int maxn=100010;
int n,m;
struct Seg{
    int mx[maxn<<2],mn[maxn<<2],tag[maxn<<2],cover[maxn<<2];
    ll sum[maxn<<2];
    inline void pushup(int rt){
        sum[rt]=sum[rt<<1]+sum[rt<<1|1];
        mx[rt]=max(mx[rt<<1],mx[rt<<1|1]);
        mn[rt]=min(mn[rt<<1],mn[rt<<1|1]);
    }
    inline void pushdown(int rt,int l,int r){
        if(cover[rt]!=0){
            int m=calm;
            ll llen=m-l+1;
            ll rlen=r-m;
            cover[rt<<1]=cover[rt<<1|1]=cover[rt];
            sum[rt<<1]=(ll)cover[rt]*llen; sum[rt<<1|1]=(ll)cover[rt]*rlen;
            mx[rt<<1]=mx[rt<<1|1]=mn[rt<<1]=mn[rt<<1|1]=cover[rt];
            tag[rt<<1]=tag[rt<<1|1]=0;
            cover[rt]=0;
        }
        if(tag[rt]!=0){
            int m=calm;
            ll llen=m-l+1;
            ll rlen=r-m;
            tag[rt<<1]+=tag[rt];tag[rt<<1|1]+=tag[rt];
            sum[rt<<1]+=tag[rt]*llen; sum[rt<<1|1]+=tag[rt]*rlen;
            mx[rt<<1]+=tag[rt];mx[rt<<1|1]+=tag[rt];
            mn[rt<<1]+=tag[rt];mn[rt<<1|1]+=tag[rt];
            tag[rt]=0;
        }
    }
    void print(int l,int r,int rt){
        if(l==r){
            printf("%I64d ",sum[rt]);
            return;
        }
        pushdown(rt,l,r);
        int m=calm;
        print(lson);print(rson);
    }
    void build(int l,int r,int rt){
        tag[rt]=cover[rt]=0;
        if(l==r){
            mx[rt]=mn[rt]= sum[rt] = val[Rank[r]];
            return;
        }
        int m=calm;
        build(lson);build(rson);
        pushup(rt);
    }
    inline void add(int L,int R,int v,int l,int r,int rt){
        if(L<=l&&r<=R){
            sum[rt]+=(ll)v*(r-l+1);
            mx[rt]+=v;
            mn[rt]+=v;
            tag[rt]+=v;
            return;
        }
        pushdown(rt,l,r);
        int m=calm;
        if(L<=m)add(L,R,v,lson);
        if(R>m)add(L,R,v,rson);
        pushup(rt);
    }
    inline void update(int L,int R,int l,int r,int rt){
        if(L<=l&&r<=R){
            if(mx[rt]==1)return;
            if(l==r){
                sum[rt]=floor(sqrt(sum[rt]));
                mx[rt]=mn[rt]=sum[rt];
                return;
            }
            if(mx[rt]==mn[rt]){
                int t=mx[rt];
                mx[rt]=mn[rt]=floor(sqrt(t));
                tag[rt]+=mx[rt]-t;
                sum[rt]=(ll)mx[rt]*(r-l+1);
                return;
            }
            else if(mx[rt]-mn[rt]==1){//区间极差==1的情况
                int ta=mx[rt],tb=mn[rt];
                int mxnum=sum[rt]-(ll)tb*(r-l+1);//直接计算出个数
                int mnnum=r-l+1-mxnum;
                mx[rt]=floor(sqrt(mx[rt]));
                mn[rt]=floor(sqrt(mn[rt]));
                if(mx[rt]-mn[rt]==1){
                    tag[rt]+=mx[rt]-ta;
                    sum[rt]=(ll)mx[rt]*mxnum+(ll)mn[rt]*mnnum;
                }
                else{

                    tag[rt]=0;cover[rt]=mx[rt];
                    sum[rt]=(ll)mx[rt]*(r-l+1);
                }
                return;
            }
            pushdown(rt,l,r);
            int m=calm;
            update(L,R,lson);
            update(L,R,rson);
            pushup(rt);
            return;
        }
        pushdown(rt,l,r);
        int m=calm;
        if(L<=m)update(L,R,lson);
        if(R>m)update(L,R,rson);
        pushup(rt);
    }
    ll query(int L,int R,int l,int r,int rt){
        if(L<=l&&r<=R){
            return sum[rt];
        }
        pushdown(rt,l,r);
        int m=calm;
        ll ans=0;
        if(L<=m)ans+=query(L,R,lson);
        if(R>m)ans+=query(L,R,rson);
        return ans;
    }
}tree;
inline void change1(int x,int y,int k)
{
    while(top[x]!=top[y])
    {
        if(dep[top[x]]<dep[top[y]])swap(x,y);
        tree.add(tid[top[x]],tid[x],k,1,n,1);
        x = fa[top[x]];
    }
    if(dep[x]>dep[y])swap(x,y);
    tree.add(tid[x],tid[y],k,1,n,1);
}
inline void change2(int x,int y)
{
    while(top[x]!=top[y])
    {
        if(dep[top[x]]<dep[top[y]])swap(x,y);
        tree.update(tid[top[x]],tid[x],1,n,1);
        x = fa[top[x]];
    }
    if(dep[x]>dep[y])swap(x,y);
    tree.update(tid[x],tid[y],1,n,1);
}
void init()
{
    memset(head,0,sizeof(head));
    memset(son,-1,sizeof son);
    cnt = 1;
    tot = 0;
}
ll get(int x,int y){
	ll ans = 0;
	ll res = 0;
	while(top[x]!=top[y])
    {
        if(dep[top[x]]<dep[top[y]])swap(x,y);
        res+=tree.query(tid[top[x]],tid[x],1,n,1);
        x = fa[top[x]];

    }
	ans+=res;
    if(dep[x]>dep[y])swap(x,y);
    ans+=tree.query(tid[x],tid[y],1,n,1);
    return ans;
}
int main(){
    //freopen("D://input.txt","r",stdin);
		//FILEIN;
		init();
        rd(n);rd(m);
        for(int i=0;i<n-1;i++){
			int u,v;
			rd(u);
			rd(v);
			addedge(u,v);
			addedge(v,u);
        }
        for(int i=1;i<=n;i++){
			rd(val[i]);
        }
        dfs1(1,0,0);
        dfs2(1,1);
        tree.build(1,n,1);
        for(int i=1;i<=m;i++){
            int op,l,r;
            rd(op);rd(l);rd(r);
            if(op==1){
				int x;
                rd(x);
                change1(l,r,x);
            }
            else if(op==2){
                change2(l,r);
            }
            else{
                printf("%lld\n",get(l,r));
            }
            //tree.print(1,n,1);printf("\n");
        }
    return 0;
}
