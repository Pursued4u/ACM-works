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
const int maxn = 5e3+5;
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

int cnt[maxn],ans[maxn][maxn];
int vis[maxn][maxn];
bool ispal[maxn][maxn];
string s;
int len;
int dfs(int l,int r)
{
    if (!ispal[l][r]) return 0;
    if (vis[l][r]) return ans[l][r];
    vis[l][r]=1;
    int mid=(l+r)>>1;
    if ((r-l)%2) ans[l][r]=min(dfs(l,mid),dfs(mid+1,r))+1;
    else ans[l][r]=min(dfs(l,mid-1),dfs(mid+1,r))+1;
    return ans[l][r];
}

void init()
{
    int l,r;
    CLR(ispal);
    for(int i=0;i<len;i++)
    {
        l=i;
        r=i;
        while ((l>=0)&&(r<len))
        {
            if (s[l]!=s[r]) break;
            ispal[l][r]=1;
            l--;
            r++;
        }
        l=i;
        r=i+1;
        while((l>=0)&&(r<len))
        {
            if (s[l]!=s[r]) break;
            ispal[l][r]=1;
            l--;
            r++;
        }
    }
}
void init1(){
    for(int i=0;i<len;i++){
        vis[i][i]= 1;
        ans[i][i]= 1;
    }
}
int main()
{
    cin >> s;
    len = s.length();
    init();
    init1();
    /*for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
            cout << ispal[i][j] << endl;
        }
    }*/
    for(int i=0;i<len;i++){
        for(int j=i;j<len;j++)
        {
            if (!vis[i][j]) dfs(i,j);
        }
    }
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++)
            ++cnt[ans[i][j]];
    }
    for(int i=len-1;i>=1;i--) cnt[i]+=cnt[i+1];
    for(int i=1;i<=len;i++){
        if(i==1) cout << cnt[i];
        else cout << " "<< cnt[i];
    }
    cout <<"\n";
}

