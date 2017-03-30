#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include<vector>
#include<stack>
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


using namespace std;
const int maxn = 5e4+5;
typedef long long ll;
const int inf = ((1ll<<29)-10);
const ll mod = 1000000007;
int mul(int x,int y)
{
    return 1LL*x*y%mod;
}
int qpow(int x , int y)
{
    int res=1;
    while(y)
    {
        if(y&1) res=mul(res,x) ;
        y>>=1 ;
        x=mul(x,x);
    }
    return res;
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
const int MAXN = 10010;
struct Edge

{
int to,next;
}edge[MAXN*2];
int head[MAXN],tot;
int top[MAXN];//top[v]��ʾv���ڵ������Ķ��˽ڵ�
int fa[MAXN]; //���׽ڵ�
int deep[MAXN];//���
int num[MAXN];//num[v]��ʾ��vΪ���������Ľڵ���
int p[MAXN];//p[v]��ʾv���丸�׽ڵ���������߶����е�λ��
int fp[MAXN];//��p�����෴
int son[MAXN];//�ض���
int pos;
void init()
{
tot = 0;
memset(head,-1,sizeof(head));
pos = 0;
memset(son,-1,sizeof(son));
}
void addedge(int u,int v)
{
edge[tot].to = v;edge[tot].next = head[u];head[u] = tot++;
}
void dfs1(int u,int pre,int d) //��һ��dfs���fa,deep,num,son
{
deep[u] = d;
fa[u] = pre;
num[u] = 1;
for(int i = head[u];i != -1; i = edge[i].next)
{
int v = edge[i].to;
if(v != pre)
{
dfs1(v,u,d+1);
num[u] += num[v];
if(son[u] == -1 || num[v] > num[son[u]])
son[u] = v;
}
}
}
void getpos(int u,int sp) //�ڶ���dfs���top��p
{
top[u] = sp;
p[u] = pos++;
fp[p[u]] = u;
if(son[u] == -1) return;
getpos(son[u],sp);
for(int i = head[u] ; i != -1; i = edge[i].next)
{
int v = edge[i].to;
if(v != son[u] && v != fa[u])
getpos(v,v);
}
}
//�߶���
struct Node
{
int l,r;
int Max;
}segTree[MAXN*3];
void build(int i,int l,int r)
{
segTree[i].l = l;
segTree[i].r = r;
segTree[i].Max = 0;
if(l == r)return;
int mid = (l+r)/2;
build(i<<1,l,mid);
build((i<<1)|1,mid+1,r);
}
void push_up(int i)
{
segTree[i].Max = max(segTree[i<<1].Max,segTree[(i<<1)|1].Max);
}
void update(int i,int k,int val) // �����߶����ĵ�k��ֵΪval
{
if(segTree[i].l == k && segTree[i].r == k)
{
segTree[i].Max = val;
return;
}
int mid = (segTree[i].l + segTree[i].r)/2;
if(k <= mid)update(i<<1,k,val);
else update((i<<1)|1,k,val);
push_up(i);
}
int query(int i,int l,int r) //��ѯ�߶�����[l,r] �����ֵ
{
if(segTree[i].l == l && segTree[i].r == r)
return segTree[i].Max;
int mid = (segTree[i].l + segTree[i].r)/2;
if(r <= mid)return query(i<<1,l,r);
else if(l > mid)return query((i<<1)|1,l,r);
else return max(query(i<<1,l,mid),query((i<<1)|1,mid+1,r));
}
int find(int u,int v)//��ѯu->v�ߵ����ֵ
{
int f1 = top[u], f2 = top[v];
int tmp = 0;
while(f1 != f2)
{
if(deep[f1] < deep[f2])
{
swap(f1,f2);
swap(u,v);
}
tmp = max(tmp,query(1,p[f1],p[u]));
u = fa[f1]; f1 = top[u];
}
if(u == v)return tmp;
if(deep[u] > deep[v]) swap(u,v);
return max(tmp,query(1,p[son[u]],p[v]));
}
int e[MAXN][3];
int main()
{
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
int T;
int n;
scanf("%d",&T);
while(T--)
{
init();
scanf("%d",&n);
for(int i = 0;i < n-1;i++)
{
scanf("%d%d%d",&e[i][0],&e[i][1],&e[i][2]);
addedge(e[i][0],e[i][1]);
addedge(e[i][1],e[i][0]);
}
dfs1(1,0,0);
getpos(1,1);
build(1,0,pos-1);
for(int i = 0;i < n-1; i++)
{
if(deep[e[i][0]] > deep[e[i][1]])
swap(e[i][0],e[i][1]);
update(1,p[e[i][1]],e[i][2]);
}
char op[10];
int u,v;
while(scanf("%s",op) == 1)
{
if(op[0] == 'D')break;
scanf("%d%d",&u,&v);
if(op[0] == 'Q')
printf("%d\n",find(u,v));//��ѯu->v·���ϱ�Ȩ�����ֵ
else update(1,p[e[u-1][1]],v);//�޸ĵ�u���ߵĳ���Ϊv
}
}
return 0;
}
