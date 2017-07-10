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
int cas = 1;
db abss(db x)
{
    return x>=0?x:-x;
}
db dis(db x1, db y1, db x2, db y2)
{
    return sqrt((y2-y1)*(y2-y1)+(x1-x2)*(x1-x2));
}

db aa(db x1, db y1, db x2, db y2, db r1, db r2) {
    db dd = dis(x1,y1,x2,y2);
    db d2 = (r2*r2+dd*dd-r1*r1)/(2.0*dd);
    //cout <<d2 << endl;
    //db si = acos(cossi);
    db consis = d2/r2;
    db si = acos(consis);
    db pd=sqrt(1-consis
    return si*r2*r2;
    //return si*r2*r2 -d2*r2*sin(si);
}
db are(db x1, db y1, db x2, db y2, db r1, db r2) {
    db dd = dis(x1,y1,x2,y2);
    db rr = min(r1,r2);
    if (dd>=()) return 0;
    if (dd - (abss(r1-r2))<=eps) return PI*rr*rr;
    db S1 = aa(x1,y1,x2,y2,r1,r2);
    db S2 = aa(x2,y2,x1,y1,r2,r1);
   //cout << S1 << " " << S2 <<endl;
    return S1 + S2 - ;
}


void solve() {
    int r1, r2, x1, x2, y1, y2;

    scanf("%d%d", &r1, &r2);
    scanf("%d%d", &x1, &x1);
    scanf("%d%d", &x2, &y2);
    db s1 = are(x1*1.0,y1*1.0,x2*1.0,y2*1.0,r2*1.0,r2*1.0);
    db s2 = are(x1*1.0,y1*1.0,x2*1.0,y2*1.0,r1*1.0,r2*1.0);
    db s3 = are(x1*1.0,y1*1.0,x2*1.0,y2*1.0,r1*1.0,r1*1.0);
    //cout << s1 << ' ' << s2 << ' ' << s3 << endl;
    db ans = s1 - 2*s2 + s3;
    printf("Case #%d: %.6f\n", cas++, ans);
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
