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
int ans1,ans2,ans;
int c[maxn];
pair<int,int>a[maxn],b[maxn];
void update(int x,int v){
    while(x<maxn){
        c[x] = max(c[x],v);
        x+=lowbit(x);
    }
}
int getsum(int x){
    int res = 0;
    while(x>0){
        res = max(res,c[x]);
        x-=lowbit(x);
    }
    return res;
}
int main()
{
    int n,tota,totb;
    cin >>n >> tota >> totb;
    int num1,num2;
    num1 = num2 = 0;
    for(int i=1;i<=n;i++){
        char op[10];
        int v,co;
        scanf("%d %d %s",&v,&co,&op);
        if(op[0]=='C')  a[num1++] = make_pair(co,v);
        else b[num2++] =make_pair(co,v); 
    }
    sort(a,a+num1);
    sort(b,b+num2);
    //cd
    for(int i=0;i<num1;i++) if(a[i].fi<=tota) ans1 = max(ans1,a[i].se);
    for(int i=0;i<num2;i++) if(b[i].fi<=totb) ans2 = max(ans2,b[i].se); 
    if(ans1&&ans2) ans = ans1+ans2;
    //cc
    CLR(c);
    for(int i=0;i<num1;i++){
        if(a[i].fi>tota) break;
        if(i){
            int cnt = getsum(tota-a[i].fi); 
            if(cnt)ans = max(ans,cnt+a[i].se);
        } 
        update(a[i].fi,a[i].se);
    }
    CLR(c);
    for(int i=0;i<num2;i++){
        if(b[i].fi>totb) break;
        if(i){
            int cnt = getsum(totb-b[i].fi);
            if(cnt)ans = max(ans,cnt+b[i].se);
        }
        update(b[i].fi,b[i].se);
    }
    cout << ans << endl;

    
}
