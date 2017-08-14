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
#define _ixvii0iv
using namespace std;
const int maxn = 5e2+5;
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

bool is_prime[500];
int prime[500];
int num;
void sieve(){
    num=0;
    int n = 500;
    for(int i=1;i<=n;i++) is_prime[i]=true; is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++){ if(is_prime[i]){ prime[num++]=i; for(int j=2*i;j<=n;j+=i) is_prime[j]=false; } } }
int mat[maxn][maxn];
int rank(int a[][],int m,int n){
    int i=0,j=0;k,r,u;
    while(i<m&&j<n){
        r = i;
        for(k=i;k<m;k++){
            if(A[k][j]){r = k; break;}
        }
        if(mat[r][j]){
            if(r!=i)for(k=0;k<=n;k++){
                swap(mat[r][k],mat[i][k]);
            }
            for(u=i+1;u<m;u++) if(mat[u][j])
                for(k=i;k<=n;k++) mat[u][k] ^= mat[i][k];
            i++;   
       }
       j++;
    }
    return i;
}
int main(){
    int t  = Read();
    while(t--){
        int n,k;
        n = Read();
        k = Read();

    }

}
