#include<bits/stdc++.h>
using namespace std;
double dis(double x1 ,double y1,double x2 ,double y2 )
{
    double xx=x2-x1;
    double yy=y2-y1;
    return sqrt(xx*xx+yy*yy);
}
int main()

{
    double x1,y1,x2,y2;
    double v1x,v1y,v2x,v2y;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> v1x >> v1y >> v2x >> v2y;
    double ans;
    double a=((v1x-v2x)*(v1x-v2x)+(v1y-v2y)*(v1y-v2y));
    double b=2.0*((v1x-v2x)*(x1-x2)+(v1y-v2y)*(y1-y2));
    double c=((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    double t=b/(-2.0*a);
    //cout << t << endl;
    if(t>0)
    ans=sqrt(fabs(a*t*t+b*t+c));
    else
        ans=sqrt(c);
    printf("%.7f\n",ans);
}
