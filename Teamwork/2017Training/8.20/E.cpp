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
#define _ixvii0iv
using namespace std;
const int maxn = 1e4+7;
typedef long long ll;
typedef double db;
const int inf = INT_MAX;
const ll INF = LLONG_MAX;
const ll mod = 1e8 + 7;
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
int num[maxn];
int dp[maxn];
void solve(){
    scanf("%s",a);
    num[0] = 0;
    dp[0] = 0;
    int len = strlen(a);
    for(int i=1;i<=len;i++){
        num[i] = a[i-1]-'0';
    }
    ll ans = 0;
    for(int i=0;i<=min(2,num[1]);i++){
        dp[1] = i;
        ll res = 1;
        int fg = 0;
        for(int j=2;j<=len;j++){
            dp[j] = num[j-1]-dp[j-1]-dp[j-2];
            if(dp[j]>2||dp[j]<0) {fg = 1; break;}
        }
        if(dp[len-1]+dp[len]!=num[len]) fg = 1;
        if(!fg){
            for(int j=1;j<=len;j++){
                if(dp[j]==1){res*=2;res%=mod;}
            }
            //cout << res <<endl;
            ans+=res;
            ans%=mod;
        }

    }
    cout << ans << endl;
}
int main(){
    int t = Read();
    int ca = 1;
    while(t--) solve();
    return 0;
}
