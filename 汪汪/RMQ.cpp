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
int c[maxn];
int a[maxn];
int maxx[maxn][30];
int main()
{
    while(1){
        int n,q;
        scanf("%d",&n);
        if(n==0)
        break;
        scanf("%d",&q);
        for(int i=1;i<=n;i++){ scanf("%d",&a[i]);}
        c[1]=1;
        for(int i=2;i<=n;i++){
            if(a[i]==a[i-1])
            c[i]=c[i-1]+1;
            else
            c[i]=1;        
        }

    for(int i=1;i<=n;i++){
        maxx[i][0] = c[i]; 
    }
    for(int j=1;(1<<j)<=n;j++){
        for(int i=1;i+(1<<j)<=n+1;i++){
            maxx[i][j] = max(maxx[i][j-1],maxx[i+(1<<(j-1))][j-1]); 
        }
    }
    int l,r;
    while(q--){
    scanf("%d %d",&l,&r);
    if(c[r]-c[l]+1==r-l+1)
    cout << r-l+1 << endl;
    else if(c[l]!=1)
    {
       // cout << "***" <<endl;
        int k;
        for(int i=l;;i++){
            if(c[i]!=c[i-1]+1)
            {
                k=i;
                break;
            }
        }
        k--;
       
        int maxxx = k-l+1;
        int tmp = r-k;
        int x = 1;
    while((1<<x)<=tmp) x++;
    cout <<max(maxxx, max(maxx[k+1][x-1],maxx[r-(1<<(x-1))+1][x-1])) << endl;
    }
    else{
      //  cout << "***" << endl;
    int tmp = r-l+1;
    int x = 1;
    while((1<<x)<=tmp) x++;
    cout << max(maxx[l][x-1],maxx[r-(1<<(x-1))+1][x-1]) << endl;

    }

}
}


}