#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include<vector>
#include<queue>
#define FILEIN freopen("in.txt", "r", stdin)
#define FILEOUT freopen("output.txt", "w", stdout)
#define CLOSEIO ios::sync_with_stdio(false)
#define PI acos(-1)
#define CLR(a) memset(a,0,sizeof(a))
#define MEM(a,x) memset(a,x,sizoef(a))
#define eps 1e-8
#define scf(x) scanf("%d",&x)
#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)
#define lowbit(x) x&(-x)
#define db double
#define rep(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define drep(a,b,c) for(int (a)=(b);(a)>(c);--(a))
#define dbg(x) cout << #x << "=" << x << endl

using namespace std;
const int maxn = 5e4+5;
typedef long long ll;
const int inf = ((1ll<<29)-10);
const ll mod = 1000000007;
int mul(int x,int y){return 1LL*x*y%mod;}
int qpow(int x , int y){int res=1;while(y){if(y&1) res=mul(res,x) ; y>>=1 ; x=mul(x,x);} return res;}

int l1[maxn],l2[maxn],r1[maxn],r2[maxn];
int a[maxn];
int d[maxn];
vector<int>ve;
map<int ,int >mp;
int n;
void add(int x)
{
    while(x<=maxn)
    {
        d[x]+=1;
        x+=lowbit(x);
    }

}
ll getsum(int x)
{
    ll ans=0;
    while(x>0)
    {
        ans+=d[x];
        x-=lowbit(x);
    }
    return ans;
}

int main()
{
    while(cin >> n)
    {
        CLR(a);
        CLR(l1);
        CLR(l2);
        CLR(r1);
        CLR(r2);
        ve.clear();
        mp.clear();
        rep(i,1,n+1)
        {
            scf(a[i]);
            ve.PB(a[i]);
        }
        sort(ve.begin(),ve.end());
        ve.erase(unique(ve.begin(),ve.end()),ve.end());
        rep(i,0,ve.size())    mp[ve[i]]=i+1;
        rep(i,1,n+1) a[i]=mp[a[i]];
        ll ans1,ans2,ans3;
        ans1=ans2=ans3=0;
        CLR(d);
        rep(i,1,n+1)
        {
            l1[i]=getsum(a[i]-1);
            l2[i]=getsum(maxn-1)-getsum(a[i]);
            add(a[i]);
        }
        CLR(d);
        drep(i,n,0)
        {
            r1[i]=getsum(a[i]-1);
            r2[i]=getsum(maxn-1)-getsum(a[i]);
            add(a[i]);
        }
        rep(i,1,n+1)
        {
            ans3+=l1[i]*r1[i];
            ans3+=l2[i]*r2[i];
            ans3+=l1[i]*l2[i];
            ans3+=r1[i]*r2[i];
            ans1+=l1[i];
            ans2+=r1[i];

        }
        cout << ans2 * ans1-ans3 << endl;


    }
}
