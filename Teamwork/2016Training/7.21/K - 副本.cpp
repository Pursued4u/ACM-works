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

bool cmp(const int &a,const int &b)
{
    return a>b;
}
priority_queue<int>q;
int a[maxn];
ll sum;
int main()
{
    //cin.sync_with_stdio(false);
    //freopen("tt.txt", "r", stdin);
    //freopen("isharp.out", "w", stdout);
    int a = 4, b = 0;

    int gd = __gcd(b, a);
    cout <<gd << endl;

    return 0;
}
