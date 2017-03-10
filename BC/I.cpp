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
#define PI acos(-1.0)
using namespace std;
typedef long long ll;
typedef double db;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
const db eps = 1e-9;
int cas = 1;
db abss(db x)
{
    return x>=0?x:-x;
}
db dis(db x1, db y1, db x2, db y2)
{
    return sqrt((y2-y1)*(y2-y1)+(x2-x1)*(x2-x1));
}

db sum(db x1,db y1,db x2,db y2,db r1,db r2)
{
    db dd=dis(x1,y1,x2,y2);
    if(r1>r2)
    {
        db t;
        t=r1;
        r1=r2;
        r2=t;
    }
    if ((int)(dd+0.5) >= (int)(r1+r2+0.5)) return 0;
    else if ((int)(dd+0.5) <= (int)(r2-r1+0.5)) return PI*r1*r1;
    else
    {
        db cos1=acos((r1*r1-r2*r2+dd*dd)/(2.0*dd)/r1);
        db cos2=acos((r2*r2-r1*r1+dd*dd)/(2.0*dd)/r2);
        db S3=sin(cos1)*r1*dd;
        db S1=cos1*r1*r1;
        db S2=cos2*r2*r2;
        return S1+S2-S3;
    }
}
void solve() {
    db r1, r2, x1, x2, y1, y2;

    scanf("%lf%lf", &r1, &r2);
    scanf("%lf%lf", &x1, &y1);
    scanf("%lf%lf", &x2, &y2);
    //cout << s1 << ' ' << s2 << ' ' << s3 << endl;
    db ans = sum(x1,y1,x2,y2,r2,r2) - 2.0*sum(x1,y1,x2,y2,r1,r2) + sum(x1,y1,x2,y2,r1,r1);
    printf("Case #%d: %.6lf\n", cas++, ans);
}

int main(){
    //cin.sync_with_stdio(false);
    //freopen("tt.txt", "r", stdin);
    //freopen("isharp.out", "w", stdout);
    int t;
    //cout << are(0,0,5,0,3,4) <<endl;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
