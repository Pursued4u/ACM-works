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
const int maxn = 3e5+5;
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
ll c[maxn];
int d[maxn*10];
struct cmp{
    bool operator()(int a,int b){
        return c[b]>c[a];
    }
};
priority_queue<int,vector<int>,cmp>q;
void solve(){
    ll n,k;
    n = Read();
    k = Read();
    ll res=0;
    for(int i=1;i<=n;i++){
        c[i] = Read();
    }
    for(int i=1;i<=k+1;i++)   q.push(i);
    int ans=1;
    int cnt=k+1;
    while(q.size()){
        int p=q.top();
        cout << p << endl;
        d[p]=ans+k;
        ans++;
        q.pop();
        cnt++;
        dbg(q.top());
        if(cnt<=n){
            q.push(cnt);
        }
        dbg(q.top());
    }
    for(int i=1;i<=n;i++){
        res+=(d[i]-i)*c[i];
    }
    cout<<res<<endl;
    for(int i=1;i<=n;i++){
        cout<<d[i];
        if(i!=n) cout<<" ";
    }
    cout<<endl;
}
int main(){
    int t = 1;
    int ca = 1;
    while(t--) solve();
    return 0;
}
