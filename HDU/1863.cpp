#include<bits/stdc++.h>
using namespace std;
#define maxn 105
#define ll long long
int fa[maxn];
int Find(int x){
    return fa[x]==x?x:fa[x]=Find(fa[x]);
}
struct node{
    int from,to;
    ll cost;
    node(int x,int y,ll v) : from(x),to(y),cost(v) {}
    node (){}
}edge[maxn*maxn];

int m,n;
ll res = 0;
bool cmp(node a,node b){
    return a.cost < b.cost;
}
void Union(node a){
    int faa = Find(a.from);
    int fab = Find(a.to);
    if(faa==fab) return;
    fa[fab] = faa;
    res+=a.cost;
}
void init(){
    for(int i=0;i<=n;i++) fa[i] = i;
    res = 0;
}

int main(){
    while(scanf("%d %d",&m,&n)!=EOF)
    {   
        if(!m) break;
        init();
        for(int i=1;i<=m;i++){
        int x,y;ll v;
        scanf("%d %d %lld",&x,&y,&v);        
        edge[i] = node(x,y,v);
    }
    sort(edge+1,edge+1+m,cmp);
    for(int i=1;i<=m;i++){
        Union(edge[i]);
    }
    int jd = Find(1);
    for(int i=1;i<=n;i++){
        if(Find(i)!=jd)
        {
            res = -1;
            break;
        }
        
    }
    if(res==-1) cout << "?" << endl;
    else cout << res << endl;
    }
}