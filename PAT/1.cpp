#include<bits/stdc++.h>
using namespace std;
struct node{
    char name[5];
    int t;
    int last;
};

node a[10005];
set<string>st[105];
int vis[10005] = {false};
map<string,int>mp;
queue<node>que;
int main(){
    int m,n;
    cin >> m >> n;
    for(int i=1;i<=n;i++){
        int q; cin >> q;
        while(q--){

            string a; cin >> a;
            st[i].insert(a);  
            mp[a]=i;
            
        }
    }
    for(int i=0;i<m;i++){
        scanf("%s %d %d",a[i].name,&a[i].t,&a[i].last);
        if(a[i].last>60)
        a[i].last = 60;
    } 
    que.push(a[0]);
    vis[0]=1;
    int now = a[0].t+a[0].last;
    int sum = 0;
    //sum += a[0].t;
        while(que.size()){
        node tmp = que.front();
        que.pop();
        puts(tmp.name);
        bool flag = 0;
        for(int i=1;i<m;i++){
            if(vis[i]) continue;
            if(a[i].t>now){
                break;
            }
            if(mp[a[i].name]==mp[tmp.name])
            {
                que.push(a[i]);
                vis[i]=1;
                flag= 1;
                sum+=now-a[i].t;
                now+=a[i].last;
                break;
            }
        }
        if(!flag){
            for(int i=1;i<m;i++){
                if(!vis[i]){
                    que.push(a[i]);
                    vis[i]=1;
                    sum+=max(0,now-a[i].t);
                    if(a[i].t>now)
                    now = a[i].t;
                    now+=a[i].last;
                    break;
                }
            }
        }
    


    }
    printf("%.1f\n",(double)sum/(double)m);
}