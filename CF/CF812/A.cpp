#include<bits/stdc++.h>
#define FILEIN freopen("in.txt", "r", stdin)
#define FILEOUT freopen("out.txt", "w", stdout)
#define CLOSEIO ios::sync_with_stdio(false)
#define PI acos(-1)
#define CLR(a) memset(a,0,sizeof(a))
#define MEM(a,x) memset(a,x,sizoef(a))
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
const int maxn = 2e4+5;
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
string a[25];
struct po{
    int l,r;
}p[25];
ll dp[30][2];
int main(){
    int m,n;
    cin >> m >> n;    
    for(int i=m-1;i>=0;i--){
        cin >> a[i];
    }
    int last = -1;
    for(int i=0;i<m;i++){
        p[i].l = n+1;
        p[i].r = 0;
        for(int j=1;j<=n;j++){
            if(a[i][j]=='1'){
                p[i].l = j;
                break;
            }
        }
        for(int j=n;j>=1;j--){
            if(a[i][j]=='1')
            {
                p[i].r = j;
                break;
            }
        }
        if(p[i].l<=p[i].r) {
            last = max(last,i);
        }
    }
    if(last==-1){
        cout << 0 << endl;
        return 0;
    }
    if(last==0){
        cout << p[0].r << endl;
        return 0;
    }
    dp[0][0] = 0;
    dp[0][1] = n+1;
    for(int i=0;i<last;i++){
        dp[i+1][0]  = min(dp[i][0]+2*p[i].r,dp[i][1]+n+1)+1;
        dp[i+1][1]  = min(dp[i][0]+n+1,dp[i][1]+2*(n+1-p[i].l))+1;
    }
    cout << min(dp[last][0]+p[last].r,dp[last][1]+n+1-p[last].l) << endl;
    

    
}