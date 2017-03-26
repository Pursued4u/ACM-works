#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#define FILEIN freopen("in.txt", "r", stdin)
#define FILEOUT freopen("output.txt", "w", stdout)
#define CLOSEIO ios::sync_with_stdio(false)
#define PI acos(-1)
#define CLR(a) memset(a,0,sizeof(a))
#define MEM(a,x) memset(a,x,sizeof(a))
#define eps 1e-8
#define scf(x) scanf("%d",&x)
#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)
#define lowbit(x) x&(-x)
#define db double
#define rep(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define drep(a,b,c) for(int (a)=(b);(a)>(c);--(a))
#define dbg(x) cout << #x << "=" << x << endl


using namespace std;
const int maxn = 1e2+5;
typedef long long ll;
const int inf = ((1ll<<29)-10);
const ll mod = 1000000007;
int mul(int x,int y){return 1LL*x*y%mod;}
int qpow(int x , int y){int res=1;while(y){if(y&1) res=mul(res,x) ; y>>=1 ; x=mul(x,x);} return res;}
int Read() {
    int x = 0, F = 1; char C = getchar();
    while (C < '0' || C > '9') { if (C == '-') F = -F; C = getchar(); }
    while (C >= '0' && C <= '9') { x = x * 10 - '0' + C, C = getchar(); }
    return x * F;
}
int a[maxn], n;
int dp[maxn][2];

int abss(int x) {
    return x >= 0 ? x : -x;
}

int minn(int x, int y) {
    if (x >= 0 && y >= 0) return min(x, y);
    else if (x >= 0) {
        y = -y;
        if (x > y) return -y;
        else return x;
    }
    else if (y >= 0) {
        x = -x;
        if (x > y) return y;
        else return -x;
    }
    else return max(x, y);
}

void solve() {
    cin >> n;
    dp[0][0] = dp[0][1] = 0;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        dp[i][0] = minn(dp[i-1][0] + x, dp[i-1][1]+x);
        dp[i][1] = minn(dp[i-1][0] - x, dp[i-1][1] - x);
       // cout << i << ' ' << dp[i][0] << ' ' << dp[i][1] << endl;
    }
    cout << min(abss(dp[n][0]), abss(dp[n][1])) + 1 << endl;
}

int main()
{
    int t; cin >> t;

    while (t--) solve();

}
