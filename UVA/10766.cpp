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
const int maxn = 50+5;
typedef long long ll;
typedef double db;
const int inf = INT_MAX;
const ll INF = LLONG_MAX;
const ll mod = 1e9 + 7;
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
        rep(i,0,n)rep(j,0,n){
            mat[i][j] = (i!=j);
        }
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
                        mat[x][k] -= mat[y][k]*t;
                    }
                    swap(x,y);
                }
                if(x!=i){
                    for(int k=0;k<n;k++){
                        swap(mat[x][k],mat[i][k]);
                    }
                }
            }
            if(!mat[i][i]) return 0;
            res*=mat[i][i];
        }
    return res<0?-res:res;
    }

};


Matrix operator-(Matrix a,Matrix b){
    Matrix c;CLR(c.mat);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            c.mat[i][j] =a.mat[i][j]-b.mat[i][j];
        }
    }
    return c;
}
int main(){
    #ifdef ONLINE_JUDGE
    #else
        FILEIN;
    #endif
    while(~scanf("%d %d %d",&n,&m,&k)){
        Matrix D,A;
        A.init();
        D.init1();
        for(int i=0;i<m;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            x--;
            y--;
            A.mat[x][y] = 0;
            A.mat[y][x] = 0;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(A.mat[i][j]){
                    D.mat[i][i]++;
                    D.mat[j][j]++;
                }
            }
        }
        Matrix c = D-A;
        ll ans = c.getsum(n-1);
        printf("%lld\n",ans);
    }

}
