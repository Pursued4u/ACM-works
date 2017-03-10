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
const int maxn = 5e2+5;
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
int dirx[] = {0, -1, 0, 1}, diry[] = {1, 0, -1, 0};
int mapp[1005][1005], vis[maxn];
bool viss[maxn][maxn];

vector<int> X[maxn], Y[maxn];
//queue<pos> q;

bool safe(int x, int y, int fl) {
    return !viss[x][y] && mapp[x][y] == fl;
}

void dfs(int x, int y, int num) {
    X[num].push_back(x);
    Y[num].push_back(y);
    for (int i = 0; i < 4; i++) {
        int xx = x + dirx[i];
        int yy = y + diry[i];
        if (safe(xx, yy, num)) {
            viss[xx][yy] = 1;
            dfs(xx, yy, num);
        }
    }
}


int main()
{
    int n;
   while ( scanf("%d",&n) != EOF) {
    if(n<=5)
    {
    if(n==1)
    {
        cout << "1 1" << endl;
        cout << "1 1" << endl;
    }
    if(n==2)
    {
        cout << "1 3" << endl;
        cout << "1 1" << endl;
        cout << "1 2 1 3" << endl;
    }
    if(n==3)
    {
        cout << "2 3" << endl;
        cout << "1 2" << endl;
        cout << "1 3 2 3" << endl;
        cout << "1 1 2 1 2 2" << endl;
    }
    if(n==4)
    {
        cout << "2 5" << endl;
        cout << "1 4" << endl;
        cout << "1 5 2 5" << endl;
        cout << "1 1 2 1 2 2" << endl;
        cout << "1 2 1 3 2 3 2 4" << endl;

    }
    if(n==5)
    {
        cout <<"3 5" << endl;
        cout <<"3 4" << endl;
        cout << "1 4 1 5" << endl;
        cout << "2 4 2 5 3 5" << endl;
        cout << "2 2 2 3 3 3 3 2" <<endl;
        cout << "3 1 2 1 1 1 1 2 1 3" <<endl;
    }
    }
    else
    {
        for (int i = 6; i <= n; i++) {
            X[i].clear(); Y[i].clear();
        }
       // while (!q.empty()) q.pop();
        memset(mapp, 0, sizeof(mapp));
        memset(viss, 0, sizeof(viss));
        int h[3][5] = {{5,5,5,2,2}, {5,4,4,3,3}, {5,4,4,1,3}};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 5; j++)
                mapp[i+1][j+1] = h[i][j];
        }
        int l = 6, d = 3;
        for (int i = 6; i <= n; i++) {
            if (i & 1) {
                d++;
                for (int j = 1; j <= l - 1; j++)
                    mapp[d][j] = i;
                mapp[d][l-1] = i - 1;
                mapp[d-1][l-2] = i;
            }
            else {
                for (int j = l; j <= l + 1; j++) {
                    for (int k = 1; k <= d; k++)
                        mapp[k][j] = i;
                }
                l += 2;
            }
        }
        memset(vis, 0, sizeof(vis));
       for (int i = 1; i <= d; i++) {
            for (int j = 1; j <= l-1; j++)
                cout << mapp[i][j] << ' ';
            cout << endl;
        }
        if (n &1) {for (int i = d; i >= 1; i--) {
            for (int j = 1; j <= l-1; j++) {
                if (!vis[mapp[i][j]]) {
                  //  pos tmp; tmp.x = i, tmp.y = j, tmp.num = mapp[i][j];
                   // q.push(tmp);
                    viss[i][j] = 1;
                    dfs(i, j, mapp[i][j]);
                    vis[mapp[i][j]] = 1;
                }
            }
        }
        }
        else {
          for (int i = d; i >= 1; i--) {
            for (int j = l-1; j >= 1; j--) {
                if (!vis[mapp[i][j]]) {
                    int ttmp = mapp[i][j];
                    if (mapp[i][j] & 1) {
                        if (mapp[i-1][j] == ttmp || mapp[i][j-1] == ttmp || mapp[i][j+1] == ttmp) continue;
                    }
                  //  pos tmp; tmp.x = i, tmp.y = j, tmp.num = mapp[i][j];
                   // q.push(tmp);
                    viss[i][j] = 1;
                    dfs(i, j, mapp[i][j]);
                    vis[mapp[i][j]] = 1;
                }
            }
          }
        }
        cout << d << ' ' << l - 1 << endl;
        cout << "3 4" << endl;
        cout << "1 4 1 5" << endl;
        cout << "2 4 2 5 3 5" << endl;
        cout << "2 2 2 3 3 3 3 2" <<endl;
        cout << "3 1 2 1 1 1 1 2 1 3" <<endl;
        for (int i = 6; i <= n; i++) {
            for (int j = 0; j < X[i].size(); j++) {
                printf("%d %d", X[i][j], Y[i][j]);
                if (j != X[i].size() - 1) putchar(' ');
            }
            puts("");
        }
    }
   }
}
