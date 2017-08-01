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

int a[12][105][105];
int b[12][105][105];

int main()
{
    int n, q, c;
    scanf("%d%d%d", &n, &q, &c);
    c++;
    for(int i=0;i<n;i++)
     {
        int x, y, s;
        x = Read();
        y = Read();
        s = Read();
        a[i][x][y] = s;
        for (int i = 1; i < c; i++){
            a[i][x][y] = (a[i - 1][x][y] + 1) % c;
        }
    }
    for (int i = 0; i < c; i++){
        for (int j = 1; j <= 100; j++){
            for (int k = 1; k <= 100; k++) {
                b[i][j][k] = a[i][j][k] + b[i][j - 1][k] + b[i][j][k - 1] - b[i][j - 1][k - 1];
            }
        }
    }
    for(int i=0;i<q;i++)
    {
        int t, x1, y1, x2, y2;
        scanf("%d%d%d%d%d", &t, &x1, &y1, &x2, &y2);
        int k = t%c;
        int ans = b[k][x2][y2] - b[k][x2][y1 - 1] - b[k][x1 - 1][y2] + b[k][x1 - 1][y1 - 1];
        printf("%d\n", ans);
    }
    return 0;
}
