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
#include<set>
#include<queue>
#define FILEIN freopen("in.txt", "r", stdin)
#define FILEOUT freopen("out.txt", "w", stdout)
#define CLOSEIO ios::sync_with_stdio(false)
#define PI acos(-1)
#define CLR(a)memset(a,0,sizeof(a))
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
set<int>st;
int main()
{
    int n=Read();
    int t=Read();
    string s;
    cin >> s;
    int p=0;
    rep(i,0,n) {if(s[i]=='.') {p=i;break;} }
    for(int i=p+1;i<n;i++)
    {
        if(s[i]>='5')
        st.insert(i);
    }
    int now = n;
    while(t--)
    {
        if(st.empty()||*st.begin()<p||*st.begin()>=now) break;
        int k=*st.begin();
        if(s[k-1]=='.') k--;
        if(++s[k-1]>='5') st.insert(k-1);
        now=k;
    }
    int flag=0;
    for(int i=p-1;i>=0;i--)
    {
        if(i)
        s[i-1]+=(s[i]-'0')/10;
        else if(s[i]>'9')
        flag=1;
        s[i]=(s[i]-'0')%10+'0';

    }
    if(flag)
    cout << 1;
    for(int i=0;i<now;i++)
    cout << s[i] ;
    cout <<endl;


}
