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
#include<cctype>
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
const int maxn = 2e5+1e3;
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
int s[maxn],e[maxn],h[maxn],d[maxn];
int c1[maxn];
int c2[maxn];
int st[maxn];
int ed[maxn];
int n;
int q;
db mid;
namespace IO {
    const static int maxm = 1e7+1e3;
    static char buf[maxm], *pbuf = buf, *End;
    void init() {
        int c = fread(buf, 1, maxm, stdin);
        End = buf + c;
    }
    int &readint() {
        static int ans;
        ans = 0;
        while (pbuf != End && !isdigit(*pbuf)) pbuf ++;
        while (pbuf != End && isdigit(*pbuf)) {
            ans = ans * 10 + *pbuf - '0';
            pbuf ++;
        }
        return ans;
    }
}
using namespace IO;
inline int Query(int *array, int pos)
{
    int temp = 0ll;
    while(pos > 0)
    {
        temp += array[pos];
        pos -= lowbit(pos);
    }
    return temp;
}

inline void Update(int *array, int pos, int x)
{
    while(pos <= maxn)
    {
        array[pos] += x;
        pos += lowbit(pos);
    }
}

void solve(){
    /*show me your code*/
    CLR(c1);
    CLR(c2);;
    int n= readint();
    for(int i = 0;i < n;++i){
        s[i] = readint();
        e[i] = readint();
    }
    for(int i = 0,j=0;i < n;++i){h[j++] = s[i];h[j++] = e[i];}
    sort(h,h+n*2);
    int p = unique(h,h+n*2)-h;
    for(int i = 0;i < n;++i) s[i] = lower_bound(h,h+p,s[i])-h+1,e[i] = lower_bound(h,h+p,e[i])-h+1;
    for(int i = 0;i < n;++i){
        int l = s[i], r = e[i], x = 1;
            Update(c1, l, x);
            Update(c1, r+1, -x);
            Update(c2, l, x * l);
            Update(c2, r+1, -x * (r+1));
    }
    for(int i = 1;i <=p;++i){
        int l =i;
        int r =i;
        int suml = l * Query(c1, l - 1) - Query(c2, l - 1);
        int sumr = (r + 1) * Query(c1, r) - Query(c2, r);
        d[i] = sumr-suml;
    }
    int ans = 0;
    for(int i=1;i<=p;i++){
        ans = max(ans,d[i]);
        cout << d[i] << " ";
    }
    cout << endl;
    for(int i=0;i<=ans+10;i++){
        st[i] = inf;
        ed[i] = -inf;
    }
    for(int i =1 ;i <=p;++i){
        st[d[i]] = min(st[d[i]],i);
        ed[d[i]+1] = max(ed[d[i]+1],i);
    }


     for(int i=1;i<=ans;i++){
         cout << st[i] << " " << ed[i] << endl;
     }

    ll res = 0;
    ll k = 1;
    for(int i =1;i<=ans;i++){
        if(ed[i]!=-inf&&st[i]!=inf&&ed[i] > st[i]){
            res+=k*(1ll*(h[ed[i]-1]-h[st[i]-1]));
            k=1;
        }
        else{
            k++;
        }
    }
    cout << ans << " " << res << "\n";

}
int main(){
    IO:init();
    int t = readint();
    int ca = 1;
    while(t--) solve();
    return 0;
}
