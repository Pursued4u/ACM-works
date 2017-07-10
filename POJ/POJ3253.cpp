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
int a[maxn];
int main()
{
    int n,i;
    scanf("%d",&n);
    priority_queue<int, vector<int>, greater<int> >que;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        que.push(a[i]);
    }
    ll ans = 0;
    while(que.size()>1)
    {
        int l1,l2;
        l1 = que.top();
        que.pop();
        l2 = que.top();
        que.pop();
        ans+=l1+l2;
        que.push(l1+l2);
    }
    printf("%lld",ans);
}
