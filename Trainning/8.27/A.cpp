#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include<vector>
#include<stack>
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
const int maxn = 2e2+5;
typedef long long ll;
const int inf = ((1ll<<29)-10);
const ll mod = 1000000007;
int mul(int x,int y){return 1LL*x*y%mod;}
int qpow(int x , int y){int res=1;while(y){if(y&1) res=mul(res,x) ; y>>=1 ; x=mul(x,x);} return res;}
int Read() {
    int x = 0, F = 1; char C = getchar();
    while (C < '0' || C > '9') { if (C == '-') F = -F; C = getchar(); }
    while (C >= '0' && C <= '9') { x = x * 10 - '0' + C, C = getchar(); }
    return x * F;
}
int a[maxn];
int abss(int x)
{
    return x>=0?x:-x;
}
int mp[maxn];
int mp1[maxn];
int main()
{
    int t;
scf(t);
    while(t--)
    {
        string s1,s2;
        cin >> s1 ;
        cin >> s2;
        memset(mp, 0, sizeof(mp));
        CLR(mp1);
        for(int i=0;i<s2.length();i++)
        {
            mp[s2[i]]++;
        }
        ll ans = 0;
        for(int i=0;i<s1.length();i++)
        {
            mp1[s1[i]]++;
        }
        for(int i=0;i<=200;i++)
        {
            ans+=abss(mp1[i]-mp[i]);
        }
        cout << ans << endl;
    }


}
