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
const int maxn = 8e5+5;
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
int v[maxn],l[maxn],r[maxn],col[55];
int tot;
int ans;
int fg;
int y1,y2,X;
void update(int &t,int L,int R,int y,int x){
    if(!t){
        t = ++tot;
        v[t] = x;
    }
    if(v[t]>x) v[t] = x;
    if(L==R) return;
    int mid = L+R>>1;
    if(y<=mid) update(l[t],L,mid,y,x);
    else update(r[t],mid+1,R,y,x);
}
void query(int x,int L,int R){
    if(fg||!x) return;
    if(y1<=L&&R<=y2){
        if(v[x]<=X)fg = 1;
        return;
    }
    int mid = L+R>>1;
    if(y1<=mid) query(l[x],L,mid);
    if(y2> mid) query(r[x],mid+1,R);
}
void solve(){
    while(1){
        int op =Read();
        if(op==3) return;
        else if(!op){
            CLR(col);
            //dbg(sizeof(l));
            //dbg(tot);
            //CLR(r);
            for(int i=1;i<=tot;i++) l[i] = r[i] = 0;
            //MEM(v,0x3f3f3f);
            tot = 0;
        }
        else if(op==1){
            int x,y,c;
            x = Read();
            y = Read();
            c = Read();
            update(col[c],1,1000000,y,x);
        }
        else{
            X =Read();
            y1 = Read();
            y2 = Read();
            ans = 0;
            for(int i=0;i<=50;i++){
                fg = 0;
                query(col[i],1,1000000);
                //dbg(fg);
                ans+=fg;
            }
            cout << ans << endl;


        }

    }
}
int main(){
    //FILEIN;
    int t = 1;
    int ca = 1;
    while(t--) solve();
    return 0;
}
