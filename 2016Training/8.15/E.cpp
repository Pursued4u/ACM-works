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
const int maxn =2e2+5;
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
    string na;
    int num, ran, ord;
} q[maxn];

bool cmp(const pos &a, const pos &b) {
    if (a.num == b.num) return a.na < b.na;
    return a.num > b.num;
}

void solve() {
    int n;
    while (cin >> n && n) {
        for (int i = 1; i <= n; i++) {
            cin >> q[i].na >> q[i].num;
        }
        sort(q+1, q+1+n, cmp);
        int cnt = 1, ans = 1;
        q[0].num = -1;
        for (int i = 1; i <= n; i++) {
            if (q[i].num == q[i-1].num) {
                q[i].ord = ans-1;
                q[i].ran = ++cnt;
            }
            else {
                ans = ans + cnt - 1;
                q[i].ord = ans++;
                cnt = 1;
                q[i].ran = cnt;
            }
        }
        for (int i = 1; i <= n; i++)
            cout << q[i].na << ' ' << q[i].num << endl;
        int m;
        cin >> m;
        while (m--) {
            string a; cin >> a;
            for (int i = 1; i <= n; i++) {
                if (q[i].na == a) {
                    printf("%d", q[i].ord);
                    if (q[i].ran != 1) printf(" %d", q[i].ran);
                    cout << endl;
                    break;
                }
            }
        }
    }

}

int main()
{
    solve();

}
