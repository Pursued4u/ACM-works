#include<bits/stdc++.h>
using namespace std;
#define db double
#pragma comment(linker, "/STACK:102400000,102400000")
int m,n,l,tmp;
int mapp[1500][150][80];
int vis[1500][150][80];
int ans = 0;
int dx[6] = {0,0,0,0,1,-1};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {1,-1,0,0,0,0};
struct node 
{
    int x,y,z;
};
node st,en;
node now;
bool check(int x,int y,int z){
    if(x>=0&&x<m&&y>=0&&y<=n&&z>=0&&z<l&&!vis[x][y][z]&&mapp[x][y][z])
    return true;
    return false;
}
queue<node>que;

int bfs(){
    now.x = st.x;
    now.y = st.y;
    int ans = 1;
    now.z = st.z;
    que.push(now);
    vis[now.x][now.y][now.z]=1;
    while(!que.empty()){
        now = que.front();
        que.pop();
        for(int i=0;i<6;i++){
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];
            int nz = now.z + dz[i];
            if(check(nx,ny,nz)){
                vis[nx][ny][nz]=1;
                ans++;
                node nn;
                nn.x = nx;
                nn.y = ny;
                nn.z = nz;
                que.push(nn);
            }
        }
        
    }
    return ans;
}


int main(){
    cin >> m >> n >> l >> tmp;
    for(int i=0;i<l;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<n;k++){
                scanf("%d",&mapp[j][k][i]);
            }
        }
    }
    int ansr= 0;
    for(int i=0;i<l;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<n;k++){
                if(mapp[j][k][i]&&!vis[j][k][i])
                {
                    st.x = j; st.y = k; st.z = i;
                    //cout << j<< " " << k << " " << i << endl;
                    int num = bfs();
                   // cout << num << endl;
                    if(num>=tmp){
                        ansr+=num;
                    }
                }
            }
        }
    }
    cout << ansr << endl;
    
    

}