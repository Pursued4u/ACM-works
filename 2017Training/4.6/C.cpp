#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
#define db double  
using namespace std;
#define maxn 100005
#define ll long long
struct node{
    int num;
    int p;
}a[maxn],c[maxn];
struct node1{
    int pr;
    int p;
}b[maxn];
int dis[105];
int np[maxn];
int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    int cnt = 0;
    db ans = 0;
    for(int i=0;i<m;i++){
        scanf("%d %d",&b[i].pr,&b[i].p);
        ans += b[i].pr*(100.0-b[i].p);
    }
    memset(dis,-1,sizeof(dis));
    for(int i=0;i<n;i++){
        scanf("%d %d",&a[i].num,&a[i].p);
        if(dis[a[i].p]==-1||dis[a[i].p]>a[i].num) dis[a[i].p] = a[i].num;
   }
   db tmpp = ans;
   for(int i=0;i<=100;i++){
       if(dis[i]==-1||dis[i]>m) continue;
       for(int j=0;j<m;j++){
            np[j] = b[j].pr*(b[j].p-i);
       }
       sort(np,np+m);
       db tmp = tmpp;
       for(int j=0;j<dis[i];j++){
           tmp+=np[j];
       }
       while(dis[i]<m&&np[dis[i]]<0){
           tmp+=np[dis[i]++];
       }
       ans = min(ans,tmp);
   }
   printf("%.6f\n",ans/100.0);

}