#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<cstring>
#include<queue>
#include<set>
#include<string>
#include<map>
#define inf 9223372036854775807
#define INF 9e7+5
#define PI acos(-1)
using namespace std;
typedef long long ll;
typedef double db;
const int maxn = 1e2 + 5;
const int mod = 1e9 + 7;
const db eps = 1e-9;
int v, o, m;
int mapp[maxn][maxn];

vector<string> G[maxn*maxn];

int main(){
    //cin.sync_with_stdio(false);
   // freopen("tt.txt", "r", stdin);
    //freopen("isharp.out", "w", stdout);
    int v, o, m, cas = 1;

    while (cin >> v >> o >> m) {
        if (!v && !o && !m) break;
        memset(mapp, -1, sizeof(mapp));
        for (int i = 1; i <= v; i++)
            G[i].clear();
        for (int i = 1; i <= v; i++) {
            int x, y; scanf("%d%d", &x, &y);
            mapp[y][x] = i;
        }
        for (int i = 1; i <= o; i++) {
            int x, y; scanf("%d%d", &x, &y);
            mapp[y][x] = 0;
        }
        for (int i = 1; i <= m; i++) {
            char dir; cin >> dir;
            int tt;
            if (dir == 'E') tt = -2;
            if (dir == 'S') tt = -3;
            if (dir == 'W') tt = -4;
            if (dir == 'N') tt = -5;
            //cout << dir <<endl;
            int x1, y1, x2, y2; scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            if (x1 == x2) {
                for (int j = min(y1, y2); j <= max(y1,y2); j++) {
                    mapp[j][x1] = tt;
                }
            }
            else {
                for (int j = min(x1, x2); j <= max(x1, x2); j++)
                    mapp[y1][j] = tt;
            }
        }
     //   for (int i = 0; i < 10; i++) {
     //       for (int j = 0; j < 10; j++)
               // cout << mapp[i][j] << ' ';
          //  cout << endl;
      //  }
        for (int i = 0; i < 101; i++) {
            for (int j = 0; j < 101; j++) {
                if (mapp[i][j] >= -5 && mapp[i][j] <= -2) {
                    if (mapp[i][j] == -2) {
                        for (int k = j+1; k < 101; k++) {
                            int tmp = mapp[i][k];
                            if (tmp <= 0 && tmp != -1) break;
                            if (tmp > 0) {
                                G[tmp].push_back("west");
                            }
                        }
                    }
                    if (mapp[i][j] == -3) {
                        for (int k = i-1; k >= 0; k--) {
                            int tmp = mapp[k][j];
                            if (tmp <= 0 && tmp != -1) break;
                            if (tmp > 0) {
                                G[tmp].push_back("north");
                            }
                        }
                    }
                    if (mapp[i][j] == -4) {
                       // cout << "OK\n";
                        for (int k = j-1; k >= 0; k--) {
                            int tmp = mapp[i][k];
                            if (tmp <= 0 && tmp != -1) break;
                            if (tmp > 0) {
                              //  cout << tmp << endl;
                                G[tmp].push_back("east");
                            }
                        }
                    }
                    if (mapp[i][j] == -5) {
                        for (int k = i+1; k < 101; k++) {
                            int tmp = mapp[k][j];
                            if (tmp <= 0 && tmp != -1) break;
                            if (tmp > 0) {
                                G[tmp].push_back("south");
                            }
                        }
                    }
                }
            }
        }
        printf("Case %d:\n", cas++);
        int flag = 0;
        for (int i = 1; i <= v; i++) {
            if (G[i].size() == 0) continue;
            flag = 1;
            printf("vampire %d", i);
            string ans[4];
            for (int j = 0; j < G[i].size(); j++) {
               // cout << G[i][j] <<endl;
                ans[j] = G[i][j];
            }
            sort(ans, ans+G[i].size());
            for (int j = 0; j < G[i].size(); j++)
                cout << ' ' << ans[j];
            cout << endl;
        }
        if (flag == 0) cout << "none\n";
    }


    return 0;
}
