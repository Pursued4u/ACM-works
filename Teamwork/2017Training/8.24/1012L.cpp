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
int w1[3]  = {3,1,0};
int w2[3]  = {0,1,3};
int dp[20][20][20][20];
void init(){
    for(int ab=0;ab<3;ab++){
        for(int ac=0;ac<3;ac++){
            for(int ad = 0;ad<3;ad++){
                for(int bc=0;bc<3;bc++){
                    for(int bd=0;bd<3;bd++){
                        for(int cd = 0;cd<3;cd++){
                            int a = w1[ab]+w1[ac]+w1[ad];
                            int b = w2[ab]+w1[bc]+w1[bd];
                            int c = w2[ac]+w1[cd]+w2[bc];
                            int d = w2[ad]+w2[cd]+w2[bd];
                            cout << a << b << c << d << endl;
                            dp[a][b][c][d]++;
                        }
                    }
                }
            }
        }

    }
}
int ca = 1;
void solve(){
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    printf("Case #%d: ",ca++);
    if(!dp[a][b][c][d]) cout << "Wrong Scoreboard" << endl;
    else if(dp[a][b][c][d]==1) cout <<"Yes" << endl;
    else cout << "No" << endl;
}
int main(){
    int t = Read();
    init();
    while(t--) solve();
    return 0;
}
