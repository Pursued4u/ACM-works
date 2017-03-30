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
#define ll long long
#define inf 2147483647
#define INF 9223372036854775807
int i,m,n;
char a[maxn], b[maxn];

int main()
{

    int n;

    while (cin >> n) {
        scanf("%s", a);
        scanf("%s", b);
        ll ans = 0, tmp = 0;
        for (int i = 0; i < n; i++)
            {
            if (a[i] != b[i]) tmp++;
            else
            {
                if (tmp)
                {
                    ans++;
                }
                tmp = 0;
            }
        }
        if (tmp) ans++;
        printf("%d\n",ans);
    }
}

