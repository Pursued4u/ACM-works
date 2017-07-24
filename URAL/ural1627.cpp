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
#include<ctime>
#include<queue>
#define FILEIN freopen("in.txt", "r", stdin)
#define FILEOUT freopen("out.txt", "w", stdout)
#define CLOSEIO ios::sync_with_stdio(false)
#define PI acos(-1)
#define CLR(a) memset(a,0,sizeof(a))
#define MEM(a,x) memset(a,x,sizeof(a))
#define eps 1e-8
#define sf(x) scanf("%d",&x)
#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)
#define lowbit(x) x&(-x)
#define fi first
#define se second
#define rep(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define drep(a,b,c) for(int (a)=(b);(a)>(c);--(a))
#define dbg(x) cout << #x << "=" << x << endl
using namespace std;
const int maxn = 100+5;
typedef long long ll;
typedef double db;
const int inf = INT_MAX;
const ll INF = LLONG_MAX;
const ll mod = 1e9;
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
int n,m,k;
struct Matrix{
    ll mat[maxn][maxn];
    void init(){
        CLR(mat);
    }
    void init1(){
        CLR(mat);
    }
    ll getsum(int n){
        ll res = 1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x = i, y = j;
                while(mat[y][i]){
                    ll t = mat[x][i]/mat[y][i];
                    for(int k=0;k<n;k++){
                        mat[x][k] -=mat[y][k]*t;
                        mat[x][k]%=mod;

                    }
                    swap(x,y);
                }
                if(x!=i){
                    for(int k=0;k<n;k++){
                        swap(mat[x][k],mat[i][k]);
                    }
                    res*=-1;
                }
            }
            if(!mat[i][i]) return 0;
            res*=mat[i][i];
            res%=mod;
        }
    return (res+mod)%mod;
    }

};
int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};
int cnt;
Matrix operator-(Matrix a,Matrix b){
    Matrix c;CLR(c.mat);
    for(int i=0;i<cnt;i++){
        for(int j=0;j<cnt;j++){
            c.mat[i][j] =a.mat[i][j]-b.mat[i][j];
        }
    }
    return c;
}
char mapp[10][10];
int a[10][10];
int main(){
        Matrix D,A;
        A.init();
        D.init1();
        CLR(a);
        scanf("%d %d",&n,&m);
        cnt = 0;
        for(int i=0;i<n;i++) scanf("%s",mapp[i]);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mapp[i][j]=='.'){
                    a[i][j] = cnt++;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mapp[i][j]=='.'){
                    int u = a[i][j];
                    for(int k=0;k<4;k++){
                        int nx = i+dx[k];
                        int ny = j+dy[k];
                        if(nx>=0&&nx<n&&ny>=0&&ny<m&&mapp[nx][ny]=='.')
                        {
                            int v = a[nx][ny];
                            A.mat[u][v] = 1;
                            A.mat[v][u] = 1;
                        }
                    }
                }
            }
        }
        for(int i=0;i<cnt;i++){
            for(int j=i+1;j<cnt;j++){
                if(A.mat[i][j]){
                    D.mat[i][i]++;
                    D.mat[j][j]++;
                }
            }
        }

        Matrix c = D-A;
        ll ans = c.getsum(cnt-1);
        printf("%I64d\n",ans);
}

