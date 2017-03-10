#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define LL long long
using namespace std;
const int M=1003;
LL C[M];
int n,m,k;
struct Node
{
  int x,y;
}edge[1003*1002];
bool cmp(Node a,Node b)
{
    if(a.x==b.x)return a.y<=b.y;
    else return a.x<b.x;
}
int lowbit(int a)
{
    return a&(-a);
}
void Modify(int p,int c)
{
    for(int i=p;i<=m;i+=lowbit(i))
     C[i]+=c;
}
int getsum(int p)
{
    LL ans=0;
    for(int i=p;i>0;i-=lowbit(i))
    {
      ans+=C[i];
    }
    return ans;
}
int main()
{
    int T=0;
    int cas;
    scanf("%d",&cas);
    while(cas--)
    {
      scanf("%d%d%d",&n,&m,&k);
      for(int i=0;i<k;i++)
       scanf("%d%d",&edge[i].x,&edge[i].y);
     memset(C,0,sizeof(C));
     sort(edge,edge+k,cmp);
     LL ans=0;
     for(int i=0;i<k;i++)
     {
        Modify(edge[i].y,1);
        ans+=(getsum(m)-getsum(edge[i].y));
     }
     T++;
     printf("Test case %d: %lld\n",T,ans);
    }
    return 0;
}
