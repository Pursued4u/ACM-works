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
#define maxn 10005
#define MAXN 1000005
#define ll long long
#define inf 2147483647
#define INF 9223372036854775807
int i,j,m,n;
int a[maxn],b[MAXN],Next[maxn];

void anext(int n)
{
    i=0;j=-1;
    Next[0]=-1;
    while(i<n)
    {
        if(a[i]==a[j]||j==-1)
        {
            i++;
            j++;
        if(a[i]!=a[j]) Next[i]=j;
        else Next[i]=Next[j];
        }
        else j=Next[j];
    }
}
void kmp(int m,int n)
{
    i=j=0;
    while(i<m && j<n)
    {
        if(b[i]==a[j]||j==-1) i++,j++;
        else j=Next[j];
    }
    if(j==n)
    printf("%d\n",i-n+1);
    else printf("-1\n");

}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(Next,0,sizeof(Next));
        cin >> m >> n;
        for(i=0;i<m;i++) cin >> b[i];
        for(i=0;i<n;i++) cin >> a[i];
        if(m<n) printf("-1\n");
        else
        {
            anext(n);
            kmp(m,n);
        }
    }
}


