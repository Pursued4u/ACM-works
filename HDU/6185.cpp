#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<set>
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
#define endl '\n'
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
inline ll Read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
ll n,m;
struct Matrix{
    ll mat[5][5];
    void init(){
        CLR(mat);
    }
};
ll p = mod;
Matrix operator *(Matrix a,Matrix b){
    Matrix c; c.init();
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                c.mat[j][i] = c.mat[j][i]+a.mat[j][k]*b.mat[k][i]%p;
                c.mat[j][i]%=p;
            }
        }
    }
    return c;
}
Matrix operator ^(Matrix a,ll b){
    Matrix c;c.init();
    for(int i=0;i<4;i++)  c.mat[i][i] = 1;
    while(b){
        if(b&1) c = a*c;
        b>>=1;
        a = a * a;
    }
    return c;
}
void solve(){
    Matrix E; E.init();
    E.mat[0][0] = E.mat[0][2] = E.mat[1][0] = E.mat[2][1] = E.mat[3][2] = 1;
    E.mat[0][1] = 5;
    E.mat[0][3] = -1;
    Matrix F; F.init();
    F.mat[0][0] = 36;
    F.mat[1][0] = 11;
    F.mat[2][0] = 5;
    F.mat[3][0] = 1;
    if(n<=4){
        cout<< F.mat[4-n][0]%p << endl;
    }
    else{
        E = E^(n-4);
        F = E*F;
        cout << (F.mat[0][0]+p)%p << endl;
    }
}
int main(){
    int t = 1;
    int ca = 1;
    while(scanf("%I64d",&n)!=EOF) solve();
    return 0;
}
