#include<cstdio>
#include<iostream>
using namespace std;
double func(double x)
{
    return 8*x*x*x*x+7*x*x*x+2*x*x+3*x+6;
}
int main()
{
    int t;
    double a;
    double mid;
    cin >> t;
    while(t--)
    {
        cin >> a;
        if(a>func(100.0)||a<func(0.0))
            cout << "No solution!" << endl;
        else{
        double l=0.0;
        double r=100.0;
        while((l-r)<=1e-8)
        {
            mid=(l+r)/2.0;

            if(func(mid)-a>1e-8)
            {
                r=mid-1e-8;
            }
            else
            {
                l=mid+1e-8;
            }

        }
        printf("%.4lf\n",mid);

        }
    }
}
