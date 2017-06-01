#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int MAXN = 1024;
#include<climits>
#include<cmath>
#define db double
#define eps 1e-7
const db inf = 10000;
#define ll long long
#include<iostream>

double a,b,c,d,e,f;

db dis(db x,db y){
    db bb = d*y+e*x;
    db aa = c;
    db cc = f*x*y+a*x*x+b*y*y-1.0;
    db z;
    if(bb*bb-4*aa*cc<0){
        z = inf;
    }
    else{
        z = (sqrt(bb*bb-4*aa*cc)-bb)/(2.0*aa);
    }
    return z*z+x*x+y*y;
}

db Findy(db x){
    db l  = -inf;
    db r = inf;
    int tt = 200;
    while(tt--){
        db mid1 = l+(r-l)/2.0;
        db mid2 = r -(r-l)/4.0;
        if(dis(x,mid2)<dis(x,mid1)){
            l = mid1;
        }
        else r = mid2;
    }
    return dis(x,l);
}
int main(){
    while(~scanf("%lf %lf %lf %lf %lf %lf",&a,&b,&c,&d,&e,&f))
    {
        db r = inf;
        db l = -inf;
        int tt =200;
        while(tt--){
            db mid1 = l + (r-l)/2.0;
            db mid2 = r - (r-l)/4.0;

            if(Findy(mid2)<Findy(mid1))
                l = mid1;
            else
                r = mid2;
        }

        printf("%.5f\n",sqrt(Findy(l)));
    }
}
