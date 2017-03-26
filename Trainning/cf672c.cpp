#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <complex>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>
using namespace std;
#define maxn 100005
#define ll long long
#define inf 2147483647
#define INF 9223372036854775807
#define db double
int i,m,n;

struct pos {

    int x,y;

}a,b,t,c[maxn];

double dis(pos xx,pos yy)
{
    double dist = 0;
    dist = (db(xx.x-yy.x)*(xx.x-yy.x)+(db)(xx.y-yy.y)*(xx.y-yy.y));
    dist = sqrt(dist);
    return dist;
}
int main()
{
    while(cin >>a.x >> a.y >> b.x >> b.y >>t.x >>t.y)
    {
        cin >> n;
        db sum=0;
        for(i=1;i<=n;i++)
        {
            cin >> c[i].x >> c[i].y;
            sum +=2* dis(c[i],t);
        }
        db maa=0;
        db mab=0;
        double daa,dbb;
        double ma=1e20;
        db mb=1e20 ;
        int flaga=0;
        int flagb=0;
        for(i=1;i<=n;i++)
        {
            daa = dis(a,c[i])-dis(c[i],t);
            dbb = dis(b,c[i])-dis(c[i],t);
            if(daa<maa)
            {
                ma = maa;
                maa = daa;
                flaga = i;
            }
            else if(daa < ma)
            {
                ma = daa;
            }
            if(dbb < mab)
            {
                mb = mab;
                mab = dbb;
                flagb = i;
            }
            else if(dbb < mb)
            {
                mb = dbb;
            }
        }
        double temp = 0;
        if(flaga&&flagb)
        {

            if(flaga==flagb)
            {
                temp+=min(maa+mb,mab+ma);
            }
            else
            {
                temp+=maa;
                temp+=mab;
            }
        }
        else if(flaga>0||flagb>0)
        {
            if(flaga>0)
            {
                temp+=maa;
            }
            if(flagb>0)
            {
                temp+=mab;
            }
        }
        else
        {
            temp+=min(ma,mb);
        }

        printf("%.12lf\n",sum+temp);

    }
}
