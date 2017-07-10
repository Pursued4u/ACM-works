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
#define maxn 200005
#define inf 2147483647
#define INF 9223372036854775807
typedef long long ll;
typedef double db;
#define PI acos(-1)
#define N 1010
int a[N][N];
int n;
int lowbit(int x)
{
    return x&(-x);
}
void add(int x,int y)
{
    for(int i=x;i<=n;i+=lowbit(i))
        for(int j=y;j<=n;j+=lowbit(j))
            a[i][j]+=1;

}
int sum(int x,int y)
{
    int ans=0;
    for(int i=x;i>0;i-=lowbit(i))
        for(int j=y;j>0;j-=lowbit(j))
        ans+=a[i][j];

    return ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(a,0,sizeof(a));
        int p;
        scanf("%d %d",&n,&p);
        while(p--)
        {
            char op[2];
            scanf("%s",op);
            if(op[0]=='C')
            {
                int x1,y1,x2,y2;
                scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
                add(x1,y1);

                add(x1,y2+1);
                add(x2+1,y1);
                add(x2+1,y2+1);
            }
            else
            {
                int x,y;
                scanf("%d %d",&x,&y);
                cout << sum(x,y)%2 << endl;
            }
        }
        if(t>0)
        cout << endl;

    }
}
