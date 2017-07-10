#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<set>
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
ll a[15];
ll b[15];
map<ll,vector<ll> >mp;
map<ll,vector<ll> >::iterator it;
set<ll> tmp,ans;
int main()
{
    int m,n;
    cin >> m >> n;
    for(int i=1;i<=m;i++) cin >> a[i];
    for(int j=1;j<=n;j++) cin >> b[j];
    for(int i=0;i<(1<<n);i++){
        ll x = 0;
        for(int j=0;j<n;j++){
            if(i&(1<<j)) x+=b[j+1];
        }
        mp[x].push_back(i);
    }
    for(it=mp.begin();it!=mp.end();it++){
        int sz = it->second.size();
        if(sz<2) continue;
        int flag = 0;
        for(int i=0;i<sz&&!flag;i++){
            for(int j=i+1;j<sz&&!flag;j++){
                if((it->second[i]&it->second[j])==0){
                    tmp.insert(2ll*(it->first));
                    flag=1;
                }
            }
        }

    }
    tmp.insert(0);
    set<ll>::iterator sit;
    for(int i=1;i<=m;i++){
        for(sit=tmp.begin();sit!=tmp.end();sit++){
            ans.insert(a[i]+*sit);
        }
    }
    for(sit=ans.begin();sit!=ans.end();sit++){
        cout << *sit << endl;
    }
    


    
    
}
