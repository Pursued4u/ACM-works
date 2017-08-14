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
const int maxn = 30+5;
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
    int x, y;
} q[maxn];

bool check(int x, int y, int x1, int y1, int x2, int y2)
{
    if(x1<=x && x<=x2 && y1<=y && y<=y2) return 1;
    return 0;
}

void solve() {
    int n;
    bool mapp[205][205];
    while (cin >> n && n) {
        memset(mapp, 0, sizeof(mapp));
        for (int i = 1; i <= n; i++) {
            int x, y; scanf("%d%d", &x, &y);
            q[i].x = x, q[i].y = y;
            mapp[x][y] = 1;
        }
        int dr[205][205], dd[205][205];
        for (int i = 0; i <= 200; i++) {
            int k = -1, p = -1;
            for (int j = 200; j >= 0; j--) {
                if (mapp[i][j]) {
                    dr[i][j] = k;
                    k = j;
                }
                if (mapp[j][i]) {
                    dd[j][i] = p;
                    p = j;
                }
            }
        }
        /*for (int i = 0; i <= 3; i++) {
            for (int j = 0; j <= 3; j++)
                cout << i << ' ' << j << ' ' << dr[i][j] << ' ' << dd[i][j] << endl;
        }*/
        int ans = -1;
        for (int i = 1; i <= n; i++) {
            int x = q[i].x, y = q[i].y;
            int tmp = dr[x][y];
            while (tmp != -1) {
               // cout << "tmp: " << tmp << endl;
                int tp = dd[x][tmp];
                while (tp != -1) {
                  //  cout << "tp: " << tp << endl;
                    if (mapp[tp][y]) {
                        int are1 = (tmp - y) * (tp - x);
                        for (int j = 1; j <= n; j++) {
                            int xx = q[j].x, yy = q[j].y;
                            if (xx >= x && xx <= tp && yy >= y && yy <= tmp) continue;
                            int tt = dr[xx][yy];
                            //cout << xx << ' ' << yy << endl;
                            //cout << "hh" << endl;
                            //if (tt >= y && tt <= tmp && xx >= x && xx <= tp) continue;
                            while (tt != -1) {
                                int ttp = dd[xx][tt];
                                //if (ttp >= x && ttp <= tp && tt >= y && tt <= tmp) break;
                                while (ttp != -1) {
                                    if (mapp[ttp][yy]) {
                                        if (xx > x && xx < tp && yy > y && yy < tmp)
                                            if (xx > x && xx < tp && tt > y && tt < tmp)
                                                if (ttp > x && ttp < tp && tt > y && tt < tmp)
                                                    if (ttp > x && ttp < tp && yy > y && yy < tmp) {
                                                        int are2 = (ttp - xx) * (tt - yy);
                                                           //cout << x << ' ' << y << ' ' << tp << ' ' << tmp << endl;
                                                          // cout << xx << ' ' << yy << ' ' << ttp << ' ' << tt << endl;
                                                        ans = max(ans, max(are1, are2));
                                                        ttp = dd[ttp][tt];
                                                        continue;
                                                    }
                                        if (x > xx && x < ttp && y > yy && y < tt)
                                            if (x > xx && x < ttp && tmp > yy && tmp < tt)
                                                if (tp > xx && tp < ttp && tmp > yy && tmp < tt)
                                                    if (tp > xx && tp < ttp && y > yy && y < tt) {
                                                    //       cout << x << ' ' << y << ' ' << tp << ' ' << tmp << endl;
                                                     //      cout << xx << ' ' << yy << ' ' << ttp << ' ' << tt << endl;
                                                        int are2 = (ttp - xx) * (tt - yy);
                                                        ans = max(ans, max(are1, are2));
                                                        ttp = dd[ttp][tt];
                                                        continue;
                                                    }
                                        if (check(xx, yy, x, y, tp, tmp)) {
                                            ttp = dd[ttp][tt];
                                            continue;
                                        }
                                        if (check(xx, tt, x, y, tp, tmp)) {
                                            ttp = dd[ttp][tt];
                                            continue;
                                        }
                                        if (check(ttp, yy, x, y, tp, tmp)) {
                                            ttp = dd[ttp][tt];
                                            continue;
                                        }
                                        if (check(ttp, tt, x, y, tp, tmp)) {
                                            ttp = dd[ttp][tt];
                                            continue;
                                        }
                                        if (check(x, y, xx, yy, ttp, tt)) {
                                            ttp = dd[ttp][tt];
                                            continue;
                                        }
                                        if (check(x, tmp, xx, yy, ttp, tt)) {
                                            ttp = dd[ttp][tt];
                                            continue;
                                        }
                                        if (check(tp, tmp, xx, yy, ttp, tt)) {
                                            ttp = dd[ttp][tt];
                                            continue;
                                        }
                                        if (check(tp, y, xx, yy, ttp, tt)) {
                                            ttp = dd[ttp][tt];
                                            continue;
                                        }
                                        if((xx <x && ttp >tp  ) || (yy < y && tt >tmp ))
                                        {
                                            ttp = dd[ttp][tt];
                                            continue;
                                        }
                                        int are2 = (ttp - xx) * (tt - yy);
                                        if (ans < are1 + are2) {
                                           // cout << x << ' ' << y << ' ' << tp << ' ' << tmp << endl;
                                        //    cout << xx << ' ' << yy << ' ' << ttp << ' ' << tt << endl;
                                            ans = are1 + are2;
                                        }
                                       // ans = max(ans, are1 + are2);
                                    }
                                    ttp = dd[ttp][tt];
                                   // cout << ttp << endl;
                                }
                                tt = dr[xx][tt];
                            }
                        }
                    }
                    tp = dd[tp][tmp];
                }
                tmp = dr[x][tmp];
            }
        }
        if (ans == -1) cout << "imp\n";
        else cout << ans << endl;
    }
}

int main()
{
    freopen("tt.txt", "r", stdin);
    solve();

}
