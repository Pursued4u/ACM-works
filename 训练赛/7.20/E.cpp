#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<map>
#include<vector>
#define FILEIN freopen("in.txt", "r", stdin)
#define FILEOUT freopen("output.txt", "w", stdout)
#define CLOSEIO ios::sync_with_stdio(false)
#define PI acos(-1)
#define eps 1e-8
#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)
using namespace std;
const int maxn = 1e2+100;
typedef long long ll;
const int inf = ((1LL<<29)-10);
const ll mod = 1000000007;

int main()
{
    double a,b;
   while(scanf("%lf %lf",&a,&b)!=EOF)
   printf("%.0f\n",pow(b,(1.0/a)));
}
