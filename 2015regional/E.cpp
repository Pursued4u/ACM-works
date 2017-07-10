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
const int maxn = 2e3+5;
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
int n[2005];
void getnext(char *s2)
{
    int i=0,j=-1,l=strlen(s2);
    n[0]=-1;
    while(i<l)
    {
        if(j==-1||s2[i]==s2[j])
        {
            i++;j++;
            if(s2[i]==s2[j])
                n[i]=n[j];
            else
                n[i]=j;
        }
        else
            j=n[j];
    }
}
int kmp(char *s,char *s2)
{
    memset(n,0,sizeof(n));
    getnext(s2);
    int i=0,j=0,k=0,len=strlen(s),l=strlen(s2);
    while(i<len)
    {
        if(j==-1||s[i]==s2[j])
            i++,j++;
        else
            j=n[j];
        if(j==l)
            k++,j=n[j];
    }
    return k;
}
int vis[505];
int main()
{
    int t=Read();
    int ca=1;
    while(t--)
    {
        CLR(vis);
        char s[505][2005];
        int n=Read();
        for(int i=1;i<=n;i++) scanf("%s",s[i]);
        int p=inf;
        int flag=0;
        for(int i=2;i<=n;i++)
        {
            if(kmp(s[i],s[i-1]))
            vis[i-1]=1;
        }
        for(int i=n;i>=1;i--)
        {
            for(int j=i-1;j>=1;j--)
            {
                if(!vis[j])
                {
                    if(!kmp(s[i],s[j]))
                    {
                        flag=1;
                        break;
                    }

                }
            }
            if(flag)
            {
               p=i;
               break;
            }
        }
        printf("Case #%d: ",ca++);
        if(p==inf)
        cout << -1 << endl;
        else
        cout << p <<endl;
    }
}
