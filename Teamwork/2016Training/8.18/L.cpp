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
const int maxn = 5e4+5;
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
int p[maxn];

void init() {
    p[1] = p[2] = p[6] = p[10] = 3;
    p[3] = p[7] = p[8] = 5;
    p[4] = p[5] = p[9]= 4;
    p[11] = p[12] = p[20] = 6;
    p[13] = p[14] = p[19] = p[18] = 8;
    p[15] = p[16] = 7;
    p[17] =  9;
    p[30] = p[80] = p[90] = 6;
    p[40] = p[50] = p[60] = 5;
    p[70] = 7;
    for (int i = 2; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            p[i*10+j] = p[i*10] + p[j];
        }
    }
    p[100] = 10; int hun = 7;
    for (int i = 1; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= 9; k++) {
                p[i*100+j*10+k] = hun + p[i];
                if (j == 0 && k == 0) continue;
                p[i*100+j*10+k] += 3 + p[j*10+k];
            }
        }
    }
    p[1000] = 11;
   // for (int i = 1; i <= 1000; i++)
      //  cout << i << ' ' << p[i] << endl;
}

void solve() {
    int n; ll ans = 0;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        ans += p[i];
    }
    cout << ans << endl;
}

int main()
{
    init();
    int t; cin >> t;
    while (t--) solve();
}
