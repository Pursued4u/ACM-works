#include<cstdio>
#include<iostream>

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
const int maxn = 1e5+5;
typedef long long ll;
typedef double db;
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
pair<ll,ll>pr1,pr2,pr3;
int main()
{
    ll n;
    while(cin >> n){
    cin >> pr1.fi >> pr1.se;
    cin >> pr2.fi >> pr2.se;
    cin >> pr3.fi >> pr3.se;
    ll ansr = 0;
    for(ll i=pr1.fi;i<=pr1.se;i++){
        ll minb = max(pr2.fi,n-i-pr3.se);
        minb = max(n/2-i+1,minb);
        minb = max(i,minb);
        ll maxb = min(pr2.se,n-i-pr3.fi);
        maxb = min((n-i)/2,maxb);
        maxb = 
        //cout << minb << " " << maxb << endl;
        if(maxb>=minb)
        ansr +=maxb-minb+1;
        //cout << maxb << minb << endl;

    }
    cout << ansr << endl;
    }
}
