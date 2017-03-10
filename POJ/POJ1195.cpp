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
#define maxn 1050
#define inf 2147483647
#define INF 9223372036854775807
typedef long long ll;
typedef double db;
#define PI acos(-1)
int c[maxn][maxn];
int n;
int lowbit(int t)
{
    return t&(-t);
}
void add(int x,int y,int v)
{
    for(int i=x;i<=n;i+=lowbit(i))
    {
        for(int j=y;j<=n;j+=lowbit(j))
        {
            c[i][j]+=v;
        }
    }
}
int sum(int x,int y)
{
    int ans=0;
    for(int i=x;i>0;i-=lowbit(i))
    {
        for(int j=y;j>0;j-=lowbit(j))
        {
            ans+=c[i][j];
        }
    }
    return ans;
}
int main()
{

    int op;
    while(scanf("%d",&op)!=EOF&&op!=3)
    {


    if(!op)
    {
        cin >> n;
        memset(c,0,sizeof(c));
    }
    else if(op==1)
    {
        int x,y,v;
        cin >> x >> y >> v;
        add(x+1,y+1,v);
    }
    else if(op==2)
    {
        int x1,x2,y1,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << sum(x2+1,y2+1)-sum(x1,y2+1)-sum(x2+1,y1)+sum(x1,y1) << endl;
    }
}

}

