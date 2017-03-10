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
#define MEM(a,x) memset(a,x,sizoef(a))
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
const int maxn = 1e4+5;
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

struct pos {
    ll x, y, w, h;
} q[maxn];
ll n, R, tot_are;


bool ok(int x, int fl) {
    ll are_l = 0, are_r = 0;
    for (int i = 1; i <= n; i++) {
        if (q[i].x < x) {
            if (q[i].x + q[i].w > x) {
                are_l += (x - q[i].x) * q[i].h;
                are_r += (q[i].x + q[i].w - x) * q[i].h;
            }
            else are_l += q[i].w * q[i].h;
        }
        else {
            are_r += q[i].w * q[i].h;
        }
    }
    if (fl == 1) return are_l <= (tot_are/2 + (tot_are & 1));
    else if (fl == 2) return are_l < are_r;
}

void solve() {
    cin >> R >> n; tot_are = 0;

    for (int i = 1; i <= n; i++) {
        scanf("%I64d%I64d%I64d%I64d", &q[i].x, &q[i].y, &q[i].w, &q[i].h);
        tot_are += q[i].w * q[i].h;
    }
    ll l = 0, r = R ,mid;
    while (l < r) {
         mid = (l+r+1) >> 1;
      //  dbg(mid);
        if (ok(mid, 1)) l = mid;
        else r = mid-1;
       //
    }
   // l -= 10000;
    while (ok(l, 2) && l < R) l++;
    //while (ok(l+1, 1) && l < R) l++;
    cout << l << endl;
}

int main()
{
    //freopen("tt.txt", "r", stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        solve();
    }
}
