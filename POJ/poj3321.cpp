#include<cstdio>
#include<iostream>
#include<cstring>
#define CLR(x) memset(x,0,sizeof(x))
using namespace std;
const int maxn = 1e5+10;
int tot;
int cnt;
struct Edge{
    int to,next;
}edge[maxn<<1];
int c[maxn];
int top[maxn];
int down[maxn];
int head[maxn];
int ori[maxn];
int lowbit(int x){
    return x&(-x);
}
void dfs(int x,int fa){
    top[x]= ++cnt;
    for(int i = head[x];i!=-1;i=edge[i].next)
    {   int v = edge[i].to;
        if(v!=fa)
            dfs(v,x);
    }
    down[x] = cnt;
}
void addedge(int u,int v){
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}

void update(int x,int v){
    while(x<maxn){
        c[x]+=v;
        x+=lowbit(x);
    }
}
int getsum(int x){
    int ans = 0;
    while(x>0){
        ans+=c[x];
        x-=lowbit(x);
    }
    return ans;
}


int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
    memset(head,-1,sizeof(head));
    memset(c,0,sizeof(c));
    tot = 0;
    cnt = 0;
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d",&u);
        scanf("%d",&v);
        addedge(u,v);
        addedge(v,u);
    }
    for(int i=1;i<=n;i++){
        ori[i] = 1;
        update(i,1);
    }

    int m;
    scanf("%d",&m);
    dfs(1,0);
    while(m--){
        char s[10];
        int v;
        scanf("%s%d",s,&v);
        if(s[0]=='Q'){
            printf("%d\n",getsum(down[v])-getsum(top[v]-1));
        }
        else{
            if(ori[v]) update(top[v],-1);
            else update(top[v],1);
            ori[v]^=1;
        }
    }
}
}
