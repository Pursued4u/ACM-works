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
#define _ixvii0iv
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
int n,m,k;
int mp[100][100];
int a[100];

bool ismax(int x,int y){
    for(int i = 1;i <= n;++i){
        if(mp[i][y] >= mp[x][y] && i!=x) return false;
    }
    for(int i = 1;i <= m;++i)
        if(mp[x][i] >= mp[x][y] && i!= y) return false;
    return true;
}

void chk(){
    int g = 0;
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= m;++j){
            if(ismax(i,j)) g++;
            //cout << mp[i][j] << " ";
        }
        //cout << endl;
    }
    a[g]++;
    //cout << "*******************" << endl;
}

void DFS(int x,int y){
    if(x == n+1){
        chk();return;
    }
    for(int i = 1;i <= k;++i){
        mp[x][y] = i;
        if(y == m)  DFS(x+1,1);
        else DFS(x,y+1);
    }
}

void brunte(){
    char c=' ';
    cout << n << c<< m <<c<< k<<endl;
    memset(a,0,sizeof(a));
    DFS(1,1);
    ll ans=0;
    for(int i =  0;i < 10;++i) ans += (i+1)*a[i];
    cout <<ans<<endl;
}

int main(){
    for(k=2; k<60; ++k)
        for(n=1; n<2; ++n)
            for(m=1; m<2; ++m)
                brunte();
}
