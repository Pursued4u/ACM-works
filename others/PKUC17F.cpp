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
const int maxn = 1e5+5;
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
struct Matrix{
    ll mat[3][3];

};
Matrix operator *(Matrix A,Matrix B){
    Matrix C; CLR(C.mat);
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                C.mat[j][i] = (C.mat[j][i]+(A.mat[j][k]*B.mat[k][i])%mod)%mod;
            }
        }
    }
    return C;
}
Matrix operator ^(Matrix A,ll b){
    Matrix c;CLR(c.mat);
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            c.mat[i][j] = (i==j);
        }
    }
    while(b){
        if(b&1){
            c = A * c;
        }
     b>>=1;
     A = A * A;
    }
    return c;
}
int main(){
    #ifdef ONLINE_JUDGE
    #else
        FILEIN;
    #endif
    int t;
    cin >> t;
    while(t--){
        Matrix res;
        Matrix tmp;
        CLR(res.mat);
        CLR(tmp.mat);
        res.mat[0][0]=7;
        res.mat[0][1]=12;
        res.mat[1][0]=4;
        res.mat[1][1]=7;
        int n = Read();
        if(!n) {cout << 1 << endl;continue;}
        tmp = res^n;
        ll ans = ((tmp.mat[0][0]*2)%mod-1+mod)%mod;
        cout << ans << endl;


    }
}
