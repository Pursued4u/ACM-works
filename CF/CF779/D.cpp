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
const int maxn = 2e5+5;
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
int vis[maxn];
int op[maxn];
int m,n;
string s,a;
bool check(int x){
    CLR(vis);
    for(int i=1;i<=x;i++)  vis[op[i]-1]=1;  
    int tmp = 0;
    int k = 0;
    int flag=0;
    while(tmp<m&&k<n){
        if(!vis[tmp]&&s[tmp]==a[k]){
            k++;
        }
        tmp++;
        if(k==n) {
            flag=1;
            break;
        }
    }

    if(flag)
    return true;
    return false;
    
}
int main()
{
   cin >> s >> a;
   m = s.length();
   n = a.length();
   for(int i=1;i<=m;i++) scanf("%d",&op[i]);
   int l = 0;
   int r = m;
   int ans=0;
   while(l<=r)
   {
       
       int mid = (l+r)>>1;
       if(check(mid)) {l = mid+1;  ans = max(ans,mid);}
       else r = mid-1;
   }
   cout << ans << endl;
}
