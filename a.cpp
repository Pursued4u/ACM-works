#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int a[2000000];
int ans[30];
int main()
{
    int n;
    ans[0] = 0;
    int x = 2;
    for (int i = 1; i < 25; i++)
    {
        ans[i] = ans[i - 1] + x;
        x *= 2;
    }
    while (cin >> n)
    {
        int x;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            if (!i)
                x = a[i];
        }
        sort(a, a + n);
        int po = upper_bound(a, a + n, x) - a - 1;
        cout << lower_bound(ans, ans + 25, po) - ans << endl;
    }
}