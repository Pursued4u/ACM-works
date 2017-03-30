#include<cstdio>
#include<vector>
#include<stack>
#include<climits>
#include<iostream>
#include<algorithm>
#include<cstring>
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
const int maxn = 2e5+5;
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
int n, a[maxn], b[maxn], c[maxn], hh[2*maxn], vis1[maxn], vis2[maxn];
void Next(const int p[], int nnext[])
{
    int q, k;
    int m = 1000;
    nnext[0] = 0;
    for(q = 1, k = 0; q<m; q++)
    {
        while(k>0 && p[q] != p[k])
            k = nnext[k-1];
        if(p[q] == p[k])
            k++;
        nnext[q] = k;
    }
}
int kmp(const int T[], const int P[], int nnext[])
{
    int k, m;
    int i, q;
    k = 2000;
    m = 1000;
    Next(P, nnext);
    for(i=0, q=0; i<k; i++)
    {
        while(q>0 && P[q] != T[i])
            q = nnext[q-1];
        if(P[q] == T[i])
            q++;
        if(q == m)
            return 1;
    }
    return 0;
}
int main()
{
    while(cin >> n)
    {
        for (int i = 1; i <= n; i++) {
            a[i]=Read();
        }
        for (int i = 1; i <= n; i++) {
            b[i]=Read();
        }
        memset(vis1, 0, sizeof(vis1)); memset(vis2, 0, sizeof(vis2));
        for (int i = 1; i <= n; i++) {
            vis1[a[i]]++;
            vis2[b[i]]++;
        }
        if (kmp(vis1, vis2, hh)) cout << "possible\n";
        else cout << "impossible\n";
    }
}
/*
3
340 20 60
70 110 150
*/
