#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include<vector>
#include<stack>
#include<climits>
#include<ctime>
#include<queue>
#define FILEIN freopen("in.txt", "r", stdin)
#define FILEOUT freopen("out.txt", "w", stdout)
#define CLOSEIO ios::sync_with_stdio(false)
#define PI acos(-1)
#define CLR(a) memset(a,0,sizeof(a))
#define MEM(a,x) memset(a,x,sizoef(a))
#define eps 1e-8
#define sf(x) scanf("%d",&x)
#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)
#define lowbit(x) x&(-x)
#define fi first
#define se second
#define rep(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define drep(a,b,c) for(int (a)=(b);(a)>(c);--(a))
#define dbg(x) cout << #x << "=" << x << endl
using namespace std;
const int N = 1e5+5;
typedef long long ll;
typedef double db;
const int inf = INT_MAX;
const ll INF = LLONG_MAX;
const ll mod = 1e9 + 7;
ll mul(ll x,ll y){return x*y%mod;}
ll q_mul(ll a, ll b){ ll ans = 0;while(b){if(b & 1){ans=(ans+a)%mod;} b>>=1;a=(a+a) % mod;}return ans;}
ll q_pow(ll x , ll y){ll res=1;while(y){if(y&1) res=q_mul(res,x) ; y>>=1 ; x=q_mul(x,x);} return res;}
ll inv(ll x) { return q_pow(x, mod-2); }
int Read() {
    int x = 0, F = 1; char C = getchar();
    while (C < '0' || C > '9') { if (C == '-') F = -F; C = getchar(); }
    while (C >= '0' && C <= '9') { x = x * 10 - '0' + C, C = getchar(); }
    return x * F;
}
int a[N];       //a[i] 原始数据
int d[N];       //d[i] 长度为i的递增子序列的最小值
int b[N];



int  LIS(int a[], int op)
{
    vector<int> v;
    int ans=0;
    for (int i = 1; i <= op; i++)
    {
        int si = v.size();
        int p1 = upper_bound(v.begin(), v.end(), a[i]) - v.begin();
        if (p1 == si) v.push_back(a[i]);
        else v[p1] = a[i];
        ans = max(ans, p1+1);
    }
    return ans;
}

int main()
{
    int t;
    int p;
    scanf("%d",&t);
    while(t--)
    {

        scanf("%d",&p);
        for(int i = 1; i <= p; i++)
        {
            scanf("%d",&a[i]);
            b[p-i+1]=a[i];
        }
        int ans1=max(LIS(a,p),LIS(b,p));
        if(ans1>=p-1)
        cout << "YES" << endl;
        else
        cout << "NO" << endl;
    }
    return 0;
}
