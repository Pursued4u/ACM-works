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
#include<queue>
#define FILEIN freopen("in.txt", "r", stdin)
#define FILEOUT freopen("output.txt", "w", stdout)
#define CLOSEIO ios::sync_with_stdio(false)
#define PI acos(-1)
#define CLR(a) memset(a,0,sizeof(a))
#define MEM(a,x) memset(a,x,sizoef(a))
#define eps 1e-8
#define sf(x) scanf("%d",&x)
#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)
#define lowbit(x) x&(-x)
#define db double
#define rep(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define drep(a,b,c) for(int (a)=(b);(a)>(c);--(a))
#define dbg(x) cout << #x << "=" << x << endl
using namespace std;
const int maxn = 5e4+5;
typedef long long ll;
const int inf = INT_MAX;
const ll INF = LLONG_MAX;
const ll mod = 5 + 7;
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

void solve() {
    ll x =-1, y = -1, op, k = 1, n = 1, flag1 = 0, flag2 = 0;
    ll tmp = 0;
    cout << 0 << ' ' << 0 << endl;
    cin >> op; cout.flush();
    ll l = 0, r = mod-7;
    while (1) {
        ll mid = (l+r) >> 1;
        flag1 = flag2 = 0;
        cout << mid << ' ' << 0 << endl;
        cin >> op; cout.flush();
        cout << mid + 1 << ' ' << 0 << endl;
        cin >> op; cout.flush();
        if (op == 1) flag1=  1;
        cout << mid << ' ' << 0 << endl;
        cin >> op; cout.flush();
        cout << mid - 1 << ' ' << 0 << endl;
        cin >> op; cout.flush();
        if (op == 1) flag2 = 1;
        if (flag1 && !flag2) l = mid;
        else if (!flag1 && flag2) r = mid;
        else {
            x = mid; break;
        }
    }
    if (x == -1) x = l;
    l = 0, r = mod-7;
    while (1) {
        ll mid = (l+r) >> 1;
        flag1 = flag2 = 0;
        cout << x << ' ' << mid << endl;
        cin >> op; cout.flush();
        cout << x << ' ' << mid+1 << endl;
        cin >> op; cout.flush();
        if (op == 1) flag1=  1;
        cout << x << ' ' << mid << endl;
        cin >> op; cout.flush();
        cout << x << ' ' << mid-1 << endl;
        cin >> op; cout.flush();
        if (op == 1) flag2 = 1;
        if (flag1 && !flag2) l = mid;
        else if (!flag1 && flag2) r = mid;
        else {
            y = mid; break;
        }
    }
    if (y == -1) y = l;
    cout << 'A' << ' ' << x << ' ' << y << endl;
}

int main()
{
    solve();

}
