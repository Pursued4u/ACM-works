#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<cstring>
#include<math.h>
#include<climits>
#define LL long long
#define db double
const int maxn = 1e2+10;
using namespace std;
struct point{
    int x,y,h;
    double v;
}p[maxn];
double dis(int x,int y,point z){
    int dx = abs(z.x-x);
    int dy = abs(z.y-y);
    return sqrt(dx*dx+dy*dy+z.h*z.h);
}
int main()
{
   int t;
   cin >>t;
   while(t--){
    int minx,miny,maxx,maxy;
   minx = miny = INT_MAX;
    maxx = maxy = INT_MIN;
   int n;
   cin >>n;
   for(int i=0;i<n;i++){
        scanf("%d %d %d %lf",&p[i].x,&p[i].y,&p[i].h,&p[i].v);
        minx = min(p[i].x,minx);
        miny = min(p[i].y,miny);
        maxx = max(p[i].x,maxx);
        maxy = max(p[i].y,maxy);

   }
   //cout <<minx <<maxx <<endl;
   db ans = INT_MIN;
   for(int i=minx;i<=maxx;i++){
        for(int j=miny;j<=maxy;j++){
            db tmp = 0;
            for(int k = 0;k<n;k++){
                db R = dis(i,j,p[k]);
               // cout <<R << endl;

                tmp += p[k].v/R/R*p[k].h/R;
                //cout << tmp << endl;
            }
            //cout <<tmp << endl;
            if(tmp > ans){
                ans = tmp;
            }

        }
   }
   printf("%.2f\n",ans);
      }



}