 //MS计划
 #include<bits/stdc++.h>
 using namespace std;
 struct point{
     int x,y;
 }a[100005];
 bool cmpx(point a,point b){
     return a.x<b.x;
 }
 bool cmpy(point a,point b){
     return a.y<b.y;
 }
bool cmpxy(point a,point b){
    return (a.x+a.y)<(b.x+b.y);
}
bool cmpyx(point a,point b){
    return (a.x-a.y)<(b.x-b.y);
}
 int maxcol,maxrow;
 #define ll long long
 int main(){
     int n;
     cin >> n;
     for(int i=0;i<n;i++){
         scanf("%d %d",&a[i].x,&a[i].y);
     }
     sort(a,a+n,cmpx);
     ll num = 1;
     ll ans = 0;
     for(int i=0;i<n-1;i++){ 
         if(a[i].x==a[i+1].x){
             num++;
         }
         if(a[i].x!=a[i+1].x){
            ans+=num*(num-1)/2;
            num = 1;
         }
     }
     ans+=num*(num-1)/2;
     sort(a,a+n,cmpy);
     num = 1;
     for(int i=0;i<n-1;i++){
         if(a[i].y==a[i+1].y){
             num++;
         }
         if(a[i].y!=a[i+1].y){
            ans+=num*(num-1)/2;
            num = 1;
         }
     }
     ans+=num*(num-1)/2;
     num=1;
     sort(a,a+n,cmpxy);
     for(int i=0;i<n-1;i++){
         if(a[i].y+a[i].x==a[i+1].y+a[i+1].x){
             num++;
         }
         if(a[i].y+a[i].x!=a[i+1].y+a[i+1].x){
            ans+=num*(num-1)/2;
            num = 1;
         }
     }
     ans+=num*(num-1)/2;
     num=1;
     sort(a,a+n,cmpyx);
     for(int i=0;i<n-1;i++){
         if(a[i].y-a[i].x==a[i+1].y-a[i+1].x){
             num++;
         }
         if(a[i].y-a[i].x!=a[i+1].y-a[i+1].x){
            ans+=num*(num-1)/2;
            num = 1;
         }
     }
     ans+=num*(num-1)/2;
     cout << ans << endl;
 }