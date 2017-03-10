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
const ll INF = (ll)1e12;
const ll mod = 1e9 + 7;
ll mul(ll x,ll y){return x*y%mod;}
ll q_mul(ll a, ll b){ ll ans = 0;while(b){if(b & 1){ans=(ans+a);} b>>=1;a=(a+a);}return ans;}
ll q_pow(ll x , ll y){ll res=1;while(y){if(y&1) res=q_mul(res,x) ; y>>=1 ; x=q_mul(x,x);} return res;}
ll inv(ll x) { return q_pow(x, mod-2); }
int Read() {
    int x = 0, F = 1; char C = getchar();
    while (C < '0' || C > '9') { if (C == '-') F = -F; C = getchar(); }
    while (C >= '0' && C <= '9') { x = x * 10 - '0' + C, C = getchar(); }
    return x * F;
}
int n=1100000;  
bool visit[10100000];  
ll prime[5000000];  
ll ispr[5000000];
  
void init_prim()  
{  
    memset(visit, true, sizeof(visit));  
    int num = 0;  
    for (ll i = 2; i <= n; ++i)  
    {  
        if (visit[i] == true)  
        {  
            num++;  
            prime[num] = i;  
        }  
        for (int j = 1; ((j <= num) && (i * prime[j] <= n));  ++j)  
        {  
            visit[i * prime[j]] = false;  
            if (i % prime[j] == 0) break; //点睛之笔  
        }  
    }  
}  
map<ll,int>mp;
ll cal(ll x)
{
    int ans = 0;
    int tmp=0;
    for(int i=1;;i++)
    {
        if(prime[i]*prime[i]>x) break;
        for(int j=2;;j++) {
            //dbg(q_pow(prime[i],j));
            if(q_pow(prime[i],j)>x){
                tmp=j;
                break;
            } 
        }
        for(int j=2;j<tmp;j++){
            if(ispr[j+1])
            ans++;
        }
        
            
    }
    //cout << ans << endl;
    return x-ans;
}
int main()  
{  
    memset(prime, 0, sizeof(prime));  
    init_prim(); 
    for(int i=1;i<=100000;i++)ispr[prime[i]]=1;
    ll l,r;
    cin >> l >> r; 
    cout << cal(r) - cal(l-1) << endl;
    //cout << cal(r) - cal(l-1) << endl;
    //cout << cal(7) << endl;
    
}

    
