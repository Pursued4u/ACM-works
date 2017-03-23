#include<bits/stdc++.h>
using namespace std;
#define maxn 101
#define ll long long
int fa[maxn];
int Find(int x){
    return fa[x] == x?x:fa[x] = Find(fa[x]);
}
ll m ,n;
ll res = 0;
struct node{
    int from,to;
    ll v;
}G[maxn*maxn];

bool cmp(node a,node b){
    return a.v<b.v;
}

void init(){
    res = 0; 
    for(int i=1;i<=m;i++)  fa[i]=i;

}
bool same(int x,int y){
    return Find(x)==Find(y);
}
void Union(node a){
    int fax = Find(a.from);
    int fay = Find(a.to);
    if(same(fax,fay)) return;
    fa[fay]=fax;
    res+=a.v; 
}

int main(){
    while(~scanf("%d",&m)){
        if(!m) break;
        init();
        for(int i=0;i<m*(m-1)/2;i++){
            int x,y; ll v;
            scanf("%d %d %lld",&x,&y,&v);
            G[i].from =x;
            G[i].to = y;
            G[i].v = v;
        }
        sort(G,G+(m-1)*m/2,cmp);
        for(int i=0;i<m*(m-1)/2;i++){
            Union(G[i]);
            
        }
        printf("%lld\n",res);
    }
}



