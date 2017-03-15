#include<cstdio>
#include<map>
#include<queue>
#include<iostream>
#include<cstring>
#include<algorithm>
const int maxn = 1e5+1e3;;
using namespace std;
#define eps 1e-6
#define ll long long
int a[maxn];
int b[maxn];
struct node{
	int type;
    int v;
};
map<string,int> id;
string gd[maxn];
int cnt[maxn];
node q[maxn];
bool cross(double x1, double y1, double r1,
           double x2, double y2, double r2) {
   double c=(x1-x2), d=(y1-y2), e=r1+r2;
   if(c*c+d*d-e*e>-eps) return false;
   return true;
}
int main(){
    double H,h,r1,R1,r2,R2;
    double m,n;
    cin >> m >> n >> h;
    cin >> r1 >> R1;
    cin >> r2 >> R2;
    cin >> H;
    
    if(H<=h){
        if(R1*2>m||R2*2>m||R1*2>n||R2*2>n)
    {
        cout << "NO" <<endl;
        return 0;
    }
        double x1,y1,x2,y2;
        x1 = m-R1;
        y1 = n-R1;
        x2 = R2;
        y2 = R2;
        if(cross(x1,y1,R1,x2,y2,R2))
            cout <<"NO" <<endl;
        else
            cout << "YES" <<endl;

    }
    else{
        double tmp1 = (h*R1-h*r1+H*r1)/(H);
        double tmp2 = (h*R2-h*r2+H*r2)/(H);
        if(tmp1*2>m||tmp2*2>m||tmp1*2>n||tmp2*2>n)
        {
            cout << "NO" <<endl;
            return 0;
        }
        double x1,y1,x2,y2;
        x1 = m - tmp1;
        y1 = n - tmp1;
        x2 = tmp2;
        y2 = tmp2;
        if(cross(x1,y1,R1,x2,y2,R2))
            cout <<"NO" <<endl;
        else
            cout << "YES" <<endl;
    }

}