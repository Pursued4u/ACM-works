#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<set>
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
#define endl '\n'
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
inline ll Read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,k;
char s[maxn];
char a[maxn];
int sum[maxn];
int sp[maxn],sb[maxn],Rank[maxn],height[maxn];
int mark1[maxn],mark2[maxn];
#define ll long long
void beizeng()
{
    int j,p;
    memset(sum,0,sizeof(sum));
    for (int i=1;i<=n;i++)
        sum[a[i]]++;
    for (int i=1;i<=300;i++)
        sum[i]+=sum[i-1];
    for (int i=n;i>=1;i--)
    {
        sp[sum[a[i]]]=i;
        sum[a[i]]--;
    }
    p=1; Rank[sp[1]]=1;
    for (int i=2;i<=n;i++)
    {
        if (a[sp[i]]!=a[sp[i-1]]) p++;
        Rank[sp[i]]=p;
    }

    j=1;
    while (p<n)
    {
        for (int i=1;i<=n;i++) mark1[i]=Rank[i];
        for (int i=1;i<=n-j;i++) mark2[i]=Rank[i+j];
        for (int i=n-j+1;i<=n;i++) mark2[i]=0;
        for (int i=1;i<=n;i++) sb[i]=sp[i];
        memset(sum,0,sizeof(sum));
        for (int i=1;i<=n;i++) sum[mark1[i]]++;
        for (int i=1;i<=n;i++) sum[i]+=sum[i-1];
        for (int i=n;i>=1;i--)
            if (sb[i]>j)
            {
                sp[sum[mark1[sb[i]-j]]]=sb[i]-j;
                sum[mark1[sb[i]-j]]--;
            }
        for (int i=n;i>=n-j+1;i--)
        {
            sp[sum[mark1[i]]]=i;
            sum[mark1[i]]--;
        }
        p=1; Rank[sp[1]]=1;
        for (int i=2;i<=n;i++)
        {
            if (mark1[sp[i]]!=mark1[sp[i-1]]||mark2[sp[i]]!=mark2[sp[i-1]]) p++;
            Rank[sp[i]]=p;
        }
        j*=2;
    }
}

void cal_h()
{
    int p,j;
    p=0;
    for (int i=1;i<=n;i++)
    {
        if (Rank[i]==1) continue;
        j=sp[Rank[i]-1];
        while (i+p<=n&&j+p<=n&&a[i+p]==a[j+p]) p++;
        height[Rank[i]]=p;
        if (p>0) p--;
    }
}
void init()
{
    cin>>k;
    scanf("%s",s);
	//cout << 1 << endl;
    n = strlen(s);
    for (int i=1;i<=n;i++)
        a[i]=s[i-1];
    beizeng();
	cal_h();

}

int q[maxn],st,ed;
int get(int k,int len){
	len++;
    k--;
	ll ans = 0;
    height[len]=0;
    st=1;
    ed=0;
    for (int i=2;i<=k+1;i++)
    {
        while (st<=ed && height[q[ed]]>=height[i]) ed--;
        ed++;
        q[ed]=i;
    }
    for (int i=1;i+k+1<=len;i++)
    {
        int minn=height[q[st]];
        if (minn>height[i] && minn>height[i+k+1])
            ans+=minn-max(height[i],height[i+k+1]);
        while (st<=ed && q[st]<=i+1) st++;
        while (st<=ed && height[q[ed]]>=height[i+k+1]) ed--;
        ed++;
        q[ed]=i+k+1;
    }
	return ans;
}
void work()
{
	ll res = 0;
	if(k==1){
		ll tmp = n;
		res = tmp*(tmp+1)/2;
		for(int i=2;i<=n;i++){
			res -= get(i,n)*i;

		}
		cout << res <<  endl;
		return;
	}
    if (k>n)
    {
        cout<<0<<endl;
        return ;
    }
	cout << get(k,n) << endl;
}


int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        init();
        work();
    }
}
