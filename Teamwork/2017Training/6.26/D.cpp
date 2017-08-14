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
#include<set>
#include<queue>
#define FILEIN freopen("in.txt", "r", stdin)
#define FILEOUT freopen("out.txt", "w", stdout)
#define CLOSEIO ios::sync_with_stdio(false)
#define PI acos(-1)
#define CLR(a) memset(a,0,sizeof(a))
#define MEM(a,x) memset(a,x,sizoef(a))
#define eps 1e-5
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
// C
int c[maxn];
void update(int x,int v){
    while(x<maxn){
        c[x]+=v;
        x+=lowbit(x);
    }
}
ll get(int x){
    int ans = 0;
    while(x>0){
        ans+=c[x];
        x-=lowbit(x);
    }
    return ans;
}
int a[maxn];
int main()
{
    int m,n,r;
    cin >> m >> n >> r;
    for(int i=1;i<=n;i++){
        int x = Read();
        a[x]=1;
        update(x,1);
    }
    int ans = 0;
    int num = get(r)-get(0);
    for(int i=r;i>0&&num<2;i--){
        if(!a[i]) {update(i,1);
        num++;
        ans++;
        a[i]=1;
        }
    }
    for(int i=r;i<=m;i++){
        int cnt = get(i)-get(i-r);
        if(cnt<2){
            ans++;
            update(i,1);
        }
    }
    cout << ans << endl;
}



