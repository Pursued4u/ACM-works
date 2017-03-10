#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<cstring>
#include<queue>
#include<set>
#include<string>
#include<map>
#define inf 9223372036854775807
#define INF 9e7+5
#define PI acos(-1)
using namespace std;
typedef long long ll;
typedef double db;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
const db eps = 1e-9;
db getnum(db v1,db v2,db h)
{
    db so=v1*h*1.0;
    db mo=v1*v1-v2*v2*1.0;
    return so/mo;
}
int main(){
    //cin.sync_with_stdio(false);
    //freopen("tt.txt", "r", stdin);
    //freopen("isharp.out", "w", stdout);
    double v1,v2,h;
    while(scanf("%lf %lf %lf",&h,&v1,&v2)!=EOF)

    {
        if(h==0)
        {
            cout << "0.000000" << endl;
            continue;
        }
        if(v1<=v2)
    cout << "Infinity" << endl;
    else
    {
        printf("%.6lf",getnum(v1,v2,h));
    }
    }

    return 0;
}
