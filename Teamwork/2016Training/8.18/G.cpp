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
#include<ctime>
#include<stdlib.h>
#define FILEIN freopen("in.txt", "r", stdin)
#define FILEOUT freopen("in.txt", "w", stdout)
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
int main()
{
    FILEOUT;
    cout << 10 << endl;
    int n, m, a[maxn];
    srand(time(0));
    for (int t = 1; t <= 10; t++) {
        n = rand()%19 + 1;
        m = rand()%19 + 1;
        cout << n << ' ' << m <<endl;
        for (int i = 1; i <= n; i++)
            a[i] = rand()%19 + 1;
        sort(a+1, a+1+n);
        for (int i = 1; i <= n; i++) {
            cout << a[i];
            if (i != n) cout << ' ';
        }
        cout << endl;
        while (m--) {
            int f[10];
            f[1] = rand()%n + 1;
            f[2] = rand()%n + 1;
            f[3] = rand()%n + 1;
            cout << 1 << ' ';
            cout << f[1] << ' ' << min(f[2], f[3]) << ' ' << max(f[2], f[3]) << endl;
        }
    }

}
