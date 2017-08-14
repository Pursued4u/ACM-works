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
const int maxn = 1e6+5;
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
int hhh;
int a[maxn];
void solve() {
    int n, m;

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    db b[maxn];
    while (m--) {
        int l1, l2, r1, r2; cin >> l1 >> r1 >> l2 >> r2;
        int p = 1;
        for (int i = l1; i <= r1; i++)
            b[p++] = a[i];
        for (int i = l2; i <= r2; i++)
            b[p++] = a[i];
        sort(b+1, b+p);
        int tot = r1 - l1 + 1 + r2 - l2 + 1;
        cout << hhh++ <<" ";
        if (tot & 1) {
            printf("%.1f\n", b[tot/2 + 1]);
        }
        else {
            printf("%.1f\n", (b[tot/2] + b[tot/2+1])/2.0);
        }
    }
}

int main()
{
    FILEIN; hhh = 1;
  //  FILEOUT;
    int t; cin >> t;
    while (t--) solve();
}
