#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 105
struct edge{
    int to;
    ll cost;
    edge(int t,ll v) : to(t) , cost(v) {}
    edge () {}
    bool operator< (const edge &a) const{
        return a.cost<cost;
    }
};
priority_queue<edge>que;
vector<edge>G[maxn];

int vis[maxn];
int m,n;
ll res;
long long prim(){
    //long long res = 0;
    vis[1]=1;
    for(int i=0;i<G[1].size();i++){
        que.push(G[1][i]);
    }
    while(que.size()){
        edge cur = que.top();
        que.pop();
        if(vis[cur.to]) continue;
        vis[cur.to]=1;
        res+=cur.cost;
        for(int i=0;i<G[cur.to].size();i++){
            que.push(G[cur.to][i]);
        }
        
    }
    return res;
}
void init(){
    res = 0;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=m;i++) G[i].clear();
    while(que.size()) que.pop();
    n = m*(m-1)/2;
}
int main(){
    while(cin >> m){
        if(!m) break;
        init();
        for(int i=0;i<n;i++){
            int u,v;
            ll x;
            scanf("%d %d %lld",&u,&v,&x);
            G[u].push_back(edge(v,x));
            G[v].push_back(edge(u,x));
            
        }
        cout << prim() << endl;
    }

}