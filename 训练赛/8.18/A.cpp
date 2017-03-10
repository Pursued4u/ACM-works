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
#define FILEIN freopen("1001.in", "r", stdin)
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
const int maxn = 3e6+5;
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
ll a[maxn], hhh;

void solve() {
    int n, m;

    cin >> n >> m;
    for (int i = 1; i <= n; i++) scanf("%I64d", &a[i]);
    while (m--) {
        db ans;
        int l1, l2, r1, r2; scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        if (l1 > l2) {
            swap(l1, l2);
        }
        if (r1 > r2) {
            swap(r1, r2);
        }
        cout << l1 << " " << r1 << l2 <<" " << r2 <<endl;
        int tot = (r1 - l1 + 1) + (r2 - l2 + 1);
        if (tot & 1) {
            if (r1 < l2) {
               // cout << "OK\n";
                if (r1 - l1 + 1 >= tot/2 + 1) ans = a[l1+tot/2];
                else {
                    ans = a[r2 - tot/2];
                }
            }
            else {
                int kk = l2;
                int mid = tot/2 + 1;
                if (l1 + mid - 1 < kk) ans = a[l1 + mid - 1];
                else if (mid <= l2 - l1 + (r1 - l2 + 1)*2) {
                    mid -= l2 - l1; mid++;
                  //  cout << mid << endl;
                    ans = a[mid/2 + l2 - 1];
                }
                else {
                    mid -= l2 - l1; mid -= (r1 - l2+1) * 2;
                    ans = a[mid + r1];
                }
            }
        }
        else {
            int mid = tot / 2; db xx, hh;
          //  cout << mid <<endl;
            if (r1 < l2) {
                if (mid + l1 - 1 <= r1) {
                    if (mid + l1 - 1 < r1) {
                        xx = a[mid + l1 - 1], hh = a[mid + l1];
                    }
                    else {
                        xx = a[r1], hh = a[l2];
                    }
                }
                else {
                    mid -= r1 - l1 + 1;
                    xx = a[mid + l2 - 1], hh = a[mid + l2];
                }
            }
            else {
                int kk = l2;
                if (l1 + mid - 1 < kk) {
                    xx = a[l1+mid-1], hh = a[l1+mid];
                }
                else if (mid <= l2 - l1 + (r1 - l2 + 1)*2) {
                    mid -= l2 - l1; mid++;
                    xx = a[mid/2 + l2 - 1]; mid++;
                    hh = a[mid/2 + l2 - 1];
                }
                else {
                   // cout << mid << endl;
                    mid -= l2 - l1; mid -= (r1 - l2+1) * 2;
                    xx = a[mid + r1], hh = a[mid + r1 + 1];
                }
            }
            ans = (xx+hh) / 2.0;
        }
        printf("%.1f\n",(db)ans);
    }
}

int main()
{

    int t; cin >> t;
    hhh = 1;

    while (t--) solve();

}
