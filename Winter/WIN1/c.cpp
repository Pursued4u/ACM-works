#include<bits/stdc++.h>
#include<queue>
#define ll long long
using namespace std;
int m,n;
typedef struct Pr
{
    int fi,se;
};
Pr s,e1,e2;
int flag=0;
int dis[30][30];
string mapp[30];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
bool check(int x,int y)
{
    if(x>=0&&y>=0&&x<m&&y<n&&mapp[x][y]!='X'&&dis[x][y]==-1)
    return true;
    else
    return false;
}

int bfs(int x,int y)
{
    Pr node;
    node.fi = x;
    node.se = y;
    dis[x][y]=0;
    queue<Pr>que;
    que.push(node);
    while(!que.empty())
    {
        Pr tmp = que.front();
        que.pop();
        //cout << tmp.fi << " " << tmp.se << endl;
        if(tmp.fi==e1.fi&&tmp.se ==e1.se ){
            flag=1;
            break;
        }
        if(tmp.fi==e2.fi&&tmp.se ==e2.se){
            break;
        }
        
        for(int i=0;i<4;i++){
            node.fi = tmp.fi+dx[i];
            node.se = tmp.se+dy[i];
           //cout << node.fi << " " <<node.se << endl;
            if(check(node.fi,node.se))
            {
                que.push(node);
                //cout << node.fi <<" " << node.se << endl;
                dis[node.fi][node.se] = dis[tmp.fi][tmp.se] +1;
                //cout << que.front().fi << " " << que.front().se <<endl;
            }
        }
        
        
    }
    if(flag==1)
    return dis[e1.fi][e1.se];
    else
    return -1;
}

int main(){
    cin >> m >> n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
        {dis[i][j]=-1;}
    }
    for(int i=0;i<m;i++) cin >> mapp[i];
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        {
            if(mapp[i][j]=='A')
            {
                e1.fi = i;
                e1.se = j;
            }
            if(mapp[i][j]=='G')
            {
                e2.fi = i;
                e2.se = j;
            }
            if(mapp[i][j]=='P')
            {
                s.fi = i;
                s.se = j;
            }
        }
        int ans = bfs(s.fi,s.se);
        //cout << ans <<endl;
        if(ans==-1)
        cout << "-1" << endl;
        else
        cout << ans << endl;
        
        
}