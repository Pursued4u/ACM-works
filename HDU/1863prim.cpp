#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 105
struct node{
    int to;
    ll v;
    bool operator < (const node & a) const{
        return a.v<v;
    }
    node(int c,ll x):to(c),v(x) {}
    node () {}
}edge[maxn*maxn];

priority_queue<node>que;
vector<node>G[maxn];
int vis[maxn];
ll m,n;
ll res;
void prim(){
    for(int i=0;i<G[1].size();i++){
        que.push(G[1][i]);
    }
    vis[1]=1;
    while(que.size()){
        node tmp = que.top();
        que.pop();
        if(vis[tmp.to]) continue;
        vis[tmp.to]=1;
        res+=tmp.v;
        for(int i=0;i<G[tmp.to].size();i++){
            que.push(G[tmp.to][i]);
        }

    }
}
void init(){
    res = 0;
    for(int i=1;i<=n;i++) G[i].clear();
    while(que.size()) que.pop();
    memset(vis,0,sizeof(vis));
}
int main(){
    while(cin >> m >> n){
        if(!m) break;
        init();
        for(int i=1;i<=m;i++){
            int u,v;
            ll x;
            scanf("%d %d %lld",&u,&v,&x);
            G[u].push_back(node(v,x));
            G[v].push_back(node(u,x));
        }
        prim();
        for(int i=1;i<=n;i++){if(!vis[i]){
            res=-1;
            break;
        }}

        if(res==-1){cout << "?\n";}
        else cout << res << "\n";
    }
}