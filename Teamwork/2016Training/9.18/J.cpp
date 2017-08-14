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
const int maxn = 1e5+5;
#define MAXN 100
#define MAXM 100010
#define MAXP 666666
#define MAX 1000001
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

int dp[MAXN][MAXM];
unsigned int ar[(MAX >> 6) + 5] = {0};
int len = 0, primes[MAXP], counter[MAX];
bool cb(unsigned int ar[],int i)
{
    return (((ar[(i) >> 6]) & (1 << (((i) >> 1) & 31))));
}
void sb(unsigned int ar[],int i)
{
    (((ar[(i) >> 6]) |= (1 << (((i) >> 1) & 31))));
}
bool isprime(ll x)
{
    return (( (x) && ((x)&1) && (!cb(ar, (x)))) || ((x) == 2));
}

void Sieve()
{
    sb(ar, 0), sb(ar, 1);
    for (int i = 3; (i * i) < MAX; i++, i++)
    {
        if (!cb(ar, i))
        {
            int k = i << 1;
            for (int j = (i * i); j < MAX; j += k) sb(ar, j);
        }
    }

    for (int i = 1; i < MAX; i++)
    {
        counter[i] = counter[i - 1];
        if (isprime(i)) primes[len++] = i, counter[i]++;
    }
}

void init()
{
    Sieve();
    for (int n = 0; n < MAXN; n++)
    {
        for (int m = 0; m < MAXM; m++)
        {
            if (!n) dp[n][m] = m;
            else dp[n][m] = dp[n - 1][m] - dp[n - 1][m / primes[n - 1]];
        }
    }
}

long long phi(long long m, int n)
{
    if (n == 0) return m;
    if (primes[n - 1] >= m) return 1;
    if (m < MAXM && n < MAXN) return dp[n][m];
    return phi(m, n - 1) - phi(m / primes[n - 1], n - 1);
}

long long Lehmer(long long m)
{
    if (m < MAX) return counter[m];

    long long w, res = 0;
    int i, a, s, c, x, y;
    s = sqrt(0.9 + m), y = c = cbrt(0.9 + m);
    a = counter[y], res = phi(m, a) + a - 1;
    for (i = a; primes[i] <= s; i++) res = res - Lehmer(m / primes[i]) + Lehmer(primes[i]) - 1;
    return res;
}
int main()
{
    init();
    ll n;
    while(scanf("%I64d",&n)!=EOF)
    {


    ll ans=Lehmer(n);
    printf("%I64d\n",ans);
    }
}
