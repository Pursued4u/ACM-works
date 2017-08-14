#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define maxn 100005
struct Edge{
    int to,Next;
}edge[maxn/2];

int n,m,cnt,head[maxn],str[maxn];
int deep,have[maxn],low[maxn],high[maxn],vis[maxn];
void addedge(int cu,int cv){
    edge[cnt].to=cv;    edge[cnt].Next=head[cu];
    head[cu]=cnt++;
}

void DFS(int x){
    low[x]=deep++;
    vis[x]=1;
    for(int i=head[x];i!=-1;i=edge[i].Next){
        while(!vis[edge[i].to])
            DFS(edge[i].to);
    }
    high[x]=deep;
}

int lowbit(int x){
    return x&(-x);
}

void add(int x,int val){
    while(x<=n){
        str[x]+=val;
        x+=lowbit(x);
    }
}

int sum(int x){
    int ans=0;
    while(x>0){
        ans+=str[x];
        x-=lowbit(x);
    }
    return ans;
}

int main(){


    cin >> n;
        cnt=0;
        memset(head,-1,sizeof(head));
        deep=0;
        memset(have,0,sizeof(have));
        memset(vis,0,sizeof(vis));
        memset(str,0,sizeof(str));
        for(int i=1;i<=n;i++){
            have[i]=1;
            add(i,1);
        }
        int u,v;
        for(int i=1;i<n;i++){
            scanf("%d%d",&u,&v);
            addedge(u,v);
        }
        DFS(1);
        scanf("%d",&m);
        char op[3];
        int id;
        while(m--){
            scanf("%s%d",op,&id);
            if(op[0]=='Q')
                printf("%d\n",sum(high[id])-sum(low[id]-1));
            else{
                if(have[id]){
                    add(low[id],-1);
                    have[id]=0;
                }else{
                    add(low[id],1);
                    have[id]=1;
                }
            }
        }

    return 0;
}
