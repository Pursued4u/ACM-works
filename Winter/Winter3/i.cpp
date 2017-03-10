#include<cstdio>
#include<iostream>
#include<cmath>
#define PI acos(-1)
using namespace std;

int main(){
    double r,R,h;
    scanf("%lf%lf%lf",&r,&R,&h);
    double ans = 2.0*R*h/(R-r)*R/(2.0*R+2.0*sqrt(R*R+R*h/(R-r)*R*h/(R-r)));
    if(ans-h/2.0>pow(10,-6))
    {
        printf("%.8lf\n",h/2.0);
        return 0;
    }
    printf("%.12f\n",ans);
}