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
#define sf scanf
#define pf printf
#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)
#define lowbit(x) x&(-x)
#define fi first
#define se second
#define rep(a,b,c) for(int (a)=(b);(a)<(c);++(a))
#define drep(a,b,c) for(int (a)=(b);(a)>(c);--(a))
#define dbg(x)
#define _ixvii0iv
using namespace std;
const int maxn = 1e5+5;
const int maxk = 128;
typedef long long ll;
typedef double db;
const int inf = INT_MAX;
const ll INF = LLONG_MAX;
const ll mod = 1e9 + 7;
ll mul(ll x,ll y)
{
    return x*y%mod;
}
ll q_mul(ll a, ll b)
{
    ll ans = 0;
    while(b)
    {
        if(b & 1)
        {
            ans=(ans+a)%mod;
        }
        b>>=1;
        a=(a+a) % mod;
    }
    return ans;
}
ll q_pow(ll x, ll y)
{
    ll res=1;
    while(y)
    {
        if(y&1) res=q_mul(res,x) ;
        y>>=1 ;
        x=q_mul(x,x);
    }
    return res;
}
int Read()
{
    int x = 0, F = 1;
    char C = getchar();
    while (C < '0' || C > '9')
    {
        if (C == '-') F = -F;
        C = getchar();
    }
    while (C >= '0' && C <= '9')
    {
        x = x * 10 - '0' + C, C = getchar();
    }
    return x * F;

}
int n, k;
char s[maxn];
ll ans[maxn][maxk], fact[maxk], ifact[maxk];
ll temp[maxk], inv[maxk], ss[10][maxk];
int rev(int x, int n) {
    int ret=0;
    while(n>1) {
        ret =ret<<1|(x&1);
        n>>=1;
        x>>=1;
    }
    return ret;
}
void ntt(long double* a, int n, int t) {
    rep(i, 0, n) {
        int rv = rev(i,n);
        if(i<rv) swap(a[i], a[rv]);
    }
    if(t==1) g=3;
    else g=inv[3];
    for(int m=2; m<n+1; m<<=1) {
        ll wm= mypow(g, (MOD-1)/m);
        int mid=m>>1;
        for(ll *p=a; p<a+n; p+=m) {
            ll w=1;
            ll *a1=p, *a2=p+mid;
            rep(i, 0, mid) {
                ll t=w*(*a2);
                *a2 = (*a1-t)%MOD;
                *a1 = (*a1+t)%MOD;
                w = w*wm%MOD;
                ++a1, ++a2;
            }
        }
    }
}
void FFT(ll *a, ll* b, ll* c) {
    int tn=MAXK;
    while(tn/4>k) tn>>=1;
    static long double wa[MAXK], wb[MAXK];
    rep(i, 0, k+1) {
    	wa[i]=a[i];
    	wb[i]=b[i];
    }
    ntt(wa, tn, 1);
    ntt(wb, tn, 1);
    rep(i, 0, tn)
        a[i] = a[i]*b[i];
    ntt(a, tn, -1);
    rep(i, 0, tn)
        a[i]=a[i]*inv[tn]%MOD;
}
void solve()
{
    sf("%d%d%s", &n, &k, s);
    rep(i, 0, n)
    {
        s[i] -= '0';
        ll *a=ans[i];
        a[0]=1;
        memcpy(a, ss[s[i]], sizeof(temp));
        rep(i, k+1, maxk)
			a[i] = 0;
        if(i)
        {
            memcpy(temp, a, sizeof(temp));
            ll* c=ans[i-1];
            FFT(temp, c, a);
            putchar(' ');
        }
        ll res = a[k]*fact[k]%mod;
        pf("%lld", res);
    }
    putchar('\n');
}
void init()
{
	ifact[0]=ifact[1]=1;
    fact[1]=fact[0]=inv[1]=1;
    rep(i, 2, maxk)
    {
        inv[i] = -(mod/i)*inv[mod%i]%mod;
        if(inv[i]<0) inv[i] += mod;
        fact[i] = fact[i-1]*i%mod;
        ifact[i] = inv[i]*ifact[i-1];
    }
    ss[0][0]=1;
    rep(i, 1, 10) {
    	ss[i][0]=1;
    	rep(j, 1, maxk)
            ss[i][j]=ss[i][j-1]*i*inv[j]%mod;
    }
}
int main()
{
	FILEIN;
	//FILEOUT;
    int t;
    sf("%d", &t);
    init();
    while(t--)
    {
        solve();
    }
    return 0;
}
