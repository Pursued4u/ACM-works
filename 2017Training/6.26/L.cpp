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
int flag; 
bool check(int x1,int y1,int x2,int y2,int x3,int y3){
    if(x1==x2&&y1+y2==x3&&x1+y3==x3) return 1;
    if(x1==x2&&y1+y2==y3&&x1+x3==y3) return 1;
    if(y1==y2&&x1+x2==x3&&y1+y3==x3) return 1;
    if(y1==y2&&x1+x2==y3&&y1+x3==y3) return 1;
    if(x1==y2&&x2+y1==x3&&x1+y3==x3) return 1;
    if(x1==y2&&x2+y1==y3&&x1+x3==y3) return 1;
    if(x1==x2&&x2==x3&&(y1+y2+y3)==x1) return 1;
    if(x1==x2&&x2==y3&&(y1+y2+x3)==x1) return 1;
    if(x1==y2&&y2==y3&&(y1+x2+x3)==x1) return 1;
    if(y1==y2&&y2==y3&&(x2+x2+x3)==y1) return 1;
    if(x1==y2&&y2==x3&&(y2+x1+y3)==x1) return 1;
    if(y1==x2&&x2==y3&&(x1+y2+x3)==y1) return 1;
    return false;
}
int main()
{
    int x1,y1,x2,y2,x3,y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    flag = 0;
    if(!flag)flag = check(x1,y1,x2,y2,x3,y3);
    if(!flag)flag = check(x1,y1,x3,y3,x2,y2);
    if(!flag)flag = check(x2,y2,x3,y3,x1,y1);
    if(!flag)flag = check(x2,y2,x1,y1,x3,y3);
    if(!flag)flag = check(x3,y3,x1,y1,x2,y2);
    if(!flag)flag = check(x3,y3,x2,y2,x1,y1);
    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;
}
