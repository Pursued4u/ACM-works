#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define CLRR(x) memset(x,-1,sizeof(x))
#define CLR(x) memset(x,0,sizeof(x))

#define db double
const int maxn = 1e5+5;
#define inf INT_MAX
#define INF LLONG_MAX
#define PB(x) push_back(x)
const int DEG = 20;
int dis[maxn];
struct Edge{
    int to,next,v;
}edge[maxn*2];

int head[maxn],tot;
void addedge(int u,int v,int w){
    edge[tot].to = v;
    edge[tot].next = head[u];
    edge[tot].v = w;
    head[u] = tot++;

}
int flag[maxn];
void init(){
    tot = 0;
    CLRR(head);
    CLR(flag);

}
int fa[maxn][DEG];
int deg[maxn];
void BFS(int root)
{
    queue<int>que;
    deg[root]=0;
    fa[root][0]=root;
    que.push(root);
    while(!que.empty()){
        int tmp = que.front();
        que.pop();
        for(int i=1;i<DEG;i++){
            fa[tmp][i] = fa[fa[tmp][i-1]][i-1];
        }
        for(int i=head[tmp];i!=-1;i=edge[i].next){
            int v = edge[i].to;
            if(v==fa[tmp][0]) continue;
            deg[v] = deg[tmp]+1;
            fa[v][0] =tmp;
            que.push(v);
        }
    }
}
int LCA(int u,int v){
    if(deg[u]>deg[v]) swap(u,v);
    int hu = deg[u],hv = deg[v];
    int tu = u,tv =v;
    for(int det = hv-hu,i=0;det;det>>=1,i++){
        if(det&1)
            tv = fa[tv][i];
    }
    if(tu==tv) return tu;
    for(int i=DEG-1;i>=0;i--){
        if(fa[tu][i]==fa[tv][i]) continue;
        tu = fa[tu][i];
        tv = fa[tv][i];
    }
    return fa[tu][0];
}

void DFS(int cur,int fa){
    for(int i = head[cur];i != -1;i = edge[i].next){
        int &v = edge[i].to;
        if(v == fa)  continue;
        dis[v] = dis[cur] + edge[i].v;
        DFS(v,cur);
    }
}
int main(){
    int t;
    cin >> t;
    int ca = 1;
    while(t--){
        init();
        printf("Case #%d:\n",ca++);
        int n,q;
        scanf("%d %d",&n,&q);
        for(int i=0;i<n-1;i++){
            int x,y,w;
            scanf("%d %d %d",&x,&y,&w);
            addedge(x,y,w);
            addedge(y,x,w);
            flag[y]++;
            flag[x]++;
        }
        int root;
        for(int i=1;i<=n;i++){
            if(flag[i]==1)
            {
                root= i;
                break;
            }
        }
        BFS(root);

        /// get distance to root
        dis[root] = 0;
        DFS(root,0);
        int a,b,l;
        scanf("%d %d %d",&a,&b,&l);
        while(q--){
            int u,v;
            scanf("%d %d",&u,&v);
            int duv = dis[u]+dis[v]-2*dis[LCA(u,v)];
            int dua = dis[u]+dis[a]-2*dis[LCA(u,a)];
            int dbv = dis[b]+dis[v]-2*dis[LCA(b,v)];
            int dub = dis[u]+dis[b]-2*dis[LCA(u,b)];
            int dav = dis[a]+dis[v]-2*dis[LCA(a,v)];
            int dd = min(dua+dbv,dub+dav);
            printf("%d\n",max(0,duv-(dd+l)));
        }
    }
}


