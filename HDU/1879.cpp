#include<bits/stdc++.h>
using namespace std;
#define maxn 10005
int m,n;
int fa[maxn];
struct node{
    int u,v;
    int x,bj;
    node(int uu,int vv,int xx,int bbj){
        u = uu;
        v = vv;
        x = xx;
        bj = bbj;
    }
    node() {}
}E[maxn];
bool cmp(node a,node b){
    return a.bj==b.bj?a.x<b.x:a.bj>b.bj;
}
int Find(int x){
    return fa[x]==x?x:fa[x]=Find(fa[x]);
}
int res; 
void init(){
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    res = 0;
}
void kruskal(){
    for(int i=0;i<m;i++){
        int faa = Find(E[i].u);
        int fab = Find(E[i].v);
        if(faa!=fab){
            fa[fab]=faa;
            if(!E[i].bj)
            res+=E[i].x;
        }
    }
}

int main(){
    while(cin >> n){
    if(n==0) break;    
    m = n*(n-1)/2;
    init();
    for(int i=0;i<m;i++){
        int w,x,y,z;
        scanf("%d %d %d %d",&x,&y,&z,&w);
        E[i]=node(x,y,z,w);
    }
    sort(E,E+m,cmp);    
   /* for(int i=0;i<m;i++){
        cout << E[i].bj << endl;
    }*/
    kruskal();
        cout << res << endl;
    }
}



