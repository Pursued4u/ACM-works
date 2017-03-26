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

ll a[maxn];
ll n;

int main(){
    //cin.sync_with_stdio(false);
    freopen("tt.txt", "r", stdin);
    //freopen("isharp.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        ll ans = 0;
        scanf("%I64d", &n);
        ll w1 = 0, w2 = 0;
        for(int i = 1; i <= n; i++)
        {
            scanf("%I64d",&a[i]);
            a[i] = a[i] >= 0 ? a[i] : - a[i];
            ans += a[i];
            w2 += a[i];
            w1 += a[i]*a[i];
        }
        w1 *= n;
        w2 *= w2;
        w1 -= w2;
        w1 = w1 >= 0 ? w1 : -w1;
        ll gd = __gcd(w1, n);
        printf("%I64d/%I64d\n", w1/gd, n/gd);
        /*
        ll q = n;
        ll gd = __gcd(ans, q);
        ans /= gd,  q /= gd;

        ll p = 0, mo = q;

        for (int i = 1; i <= n; i++) {
            ll lcm = mo / __gcd(mo, q*q) * q*q ;
            ll hh = p * (lcm/mo), kk = (a[i]*q - ans)*(a[i]*q - ans) * (lcm/q/q);
            p = hh + kk;
            gd = __gcd(p, lcm);
            p /= gd, mo = lcm / gd;
        }
        printf("%I64d/%I64d\n", p, mo);*/
    }

    return 0;
}
