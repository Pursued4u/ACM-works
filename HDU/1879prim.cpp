#include<bits/stdc++.h>
using namespace std;
#define maxn 105
int vis[maxn];
struct node{
    int to;
    int v;
    bool operator < (const node &a) const{
        return a.v<v;
    }     
    node (int u,int x){
        to = u;
        v = x;
    }
    node () {}
};    
priority_queue<node>que;
int ans,m,n; 
vector<node>G[maxn];
void init(){
    while(!que.empty())que.pop();
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++) G[i].clear();
    ans = 0;
}
void prim(){
    for(int i=0;i<G[1].size();i++) que.push(G[1][i]);
    vis[1] = 1; 
    while(que.size()){
        node tmp = que.top();
        que.pop();
        if(vis[tmp.to]) continue;
        ans+=tmp.v;
        vis[tmp.to]=1;
        for(int i=0;i<G[tmp.to].size();i++){
            que.push(G[tmp.to][i]);
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    while(cin >> n){
        if(!n) break;
        m = n*(n-1)/2;
        init();
        for(int i=0;i<m;i++){
            int x,y,z,w;
            scanf("%d %d %d %d",&x,&y,&z,&w);
            if(w) z= 0;
            G[x].push_back(node(y,z));
            G[y].push_back(node(x,z));
        }
        prim();
        cout << ans << endl;
    }
}


