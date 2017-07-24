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
int num[maxn];
int js[10];
int tot[10];
void get(int x){
    while(x){
        js[x%10]++;
        x/=10;
    }
}
int main()
{
    int t = Read();
    while(t--){
        CLR(js);
        CLR(tot);
        int a,b,c;
        a = Read();
        b = Read();
        c = Read();

        int cnt = 0;
        for(int i=1;i*i*a+i*b<=c;i++){
            num[cnt++] = i*i*a+i*b;
        }
        if(cnt==0){
            cout << -1 << endl;
            continue;
        }
        for(int i=0;i<cnt;i++){
            CLR(js);
            get(num[i]);
            int maxx = -1;
            for(int i=0;i<10;i++){
                maxx = max(maxx,js[i]);
            }
            for(int i=0;i<10;i++){
                if(js[i]==maxx)
                tot[i]++;
            }
        }
        int maxxx=-1;
        for(int i=0;i<10;i++){
            maxxx = max(maxxx,tot[i]);
        }
        for(int i=0;i<10;i++){
            if(tot[i]==maxxx)
            {
                cout << i << endl;
                break;
            }
        }
    }
}
