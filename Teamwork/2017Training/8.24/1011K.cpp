#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cstdlib>
using namespace std;
#define ll long long
const ll INF=500000000000000ll;
const int MAXN=100000+10;
struct Rec
{
    ll num,len;
    bool operator < (const Rec &a) const
    {
        return len>a.len;
        /*优先队列强制设为以len为关键词的小顶堆*/
    }
};
int u[MAXN*2],v[MAXN*2],w[MAXN*2];
/*依次表示每条道路的起点、终点和长度*/
ll dis[MAXN],secondis[MAXN];
/*记录通往每一个路口的最短和次短距离*/
int first[MAXN],Next[MAXN*2];
int n,r;

void dijkstra()
{
    priority_queue<Rec> que;
    for (int i=1;i<n;i++)
    {
         dis[i]=INF;
         secondis[i]=INF;
    }
    dis[0]=0;
    secondis[0]=INF;
    Rec temp;
    temp.len=0;temp.num=0;
    que.push(temp);
    while (!que.empty())
    {
        Rec head=que.top();
        que.pop();
        if (head.len>secondis[head.num]) continue;
        int k=first[head.num];
        while (k!=-1)
        {
            ll d=head.len+w[k];
            if (dis[v[k]]>d)
            {
                swap(dis[v[k]],d);
                temp.len=dis[v[k]];temp.num=v[k];
                que.push(temp);
            }
            if (dis[v[k]]<=d && secondis[v[k]]>d)
            {
                secondis[v[k]]=d;
                temp.len=secondis[v[k]];temp.num=v[k];
                que.push(temp);
            }
            k=Next[k];
        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
    scanf("%d%d",&n,&r);
    memset(first,-1,sizeof(first));
    memset(Next,0,sizeof(Next));
    for (int i=0;i<r;i++)
    {
        scanf("%d%d%d",&u[i],&v[i],&w[i]);
        u[i]--;
        v[i]--;
        Next[i]=first[u[i]];
        first[u[i]]=i;
        v[i+r]=u[i];
        u[i+r]=v[i];
        w[i+r]=w[i];
        Next[i+r]=first[u[i+r]];
        first[u[i+r]]=i+r;
    }
    dijkstra();
    cout<<secondis[n-1]<<endl;
}
    return 0;
}
