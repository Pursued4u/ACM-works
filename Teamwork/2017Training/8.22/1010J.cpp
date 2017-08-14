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
const int maxn = 3e3;
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
char a[maxn];
char b[maxn];
int dp[maxn][maxn];
void solve(){
    CLR(dp);
    scanf("%s",a+1);
    scanf("%s",b+1);
    int len1 = strlen(a+1);
    int len2 = strlen(b+1);
    dp[0][0] =1;
    //cout
    for(int i=1;i<=len1;i++){
        for(int j=1;j<=len2;j++){
            if(a[i]==b[j]){
                dp[i][j] = dp[i-1][j-1];

            }
            else if(b[j]=='.'){
                dp[i][j] = dp[i-1][j-1];
                //i++;j++;
            }
            else if(b[j]=='*'){
                if(dp[i-1][j-2])dp[i-1][j] = dp[i-1][j-2];
                if(dp[i][j-2]) dp[i][j] = dp[i][j-2];
                if(dp[i][j-1]) dp[i][j] = dp[i][j-1];
                if(dp[i-1][j-1]&&a[i]==a[i-1]) dp[i][j] = dp[i-1][j-1];
                if(dp[i-1][j]&&a[i]==a[i-1]) dp[i][j] = dp[i-1][j];
            }
            else dp[i][j] = 0;
            //cout << i << " " << j << " " <<dp[i][j] << endl;
        }
    }
    if(dp[len1][len2]) cout << "yes" << endl;
    else cout << "no" << endl;
}
int main(){
    //FILEIN;
    int t = Read();
    int ca = 1;
    while(t--) solve();
    return 0;
}
