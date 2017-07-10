#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
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

#define rep(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define drep(a,b,c) for(int (a)=(b);(a)>(c);--(a))
#define dbg(x) cout << #x << "=" << x << endl
using namespace std;
const int maxn = 1e5+5;
typedef long long ll;
typedef double db;

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
char a[105];
char b[105];
char c[1000005];
struct Node
{
    int fi, se;
}pr[1000005];
bool cmp(Node a,Node b)

{return a.se<b.se;}
int Next[50005];
int t=0;
void getnext(char s[]) {
	int i=0,j=-1;
	int len=strlen(s);
	Next[0]=-1;
	while(i<len) {
		if(j==-1 || s[i]==s[j]) {
			i++; j++;
			Next[i] = j;
		}
		else j=Next[j];
	}
}

void kmp(char s[],char s1[]) {
	int i=0,j=0;
	getnext(s1);
	int len=strlen(s);
    int len1=strlen(s1);
	while(i<len) {
		if(j==-1||s[i]==s1[j]) {
			i++; j++;
		}
		else j=Next[j];
		if(j==len1) {
			pr[t].fi=i-len1+1;
            pr[t++].se = i;
		}
	}
}
int main()
{
    while(gets(c)){
    int n;
    t=0;
    CLR(pr);
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        gets(b);
        CLR(Next);
        kmp(c,b);
    }
    int ans = 0;
    int tmp = 0;
    
    if(!t)
    {
        cout << strlen(c) << endl;
    }
    else
    {
    /*for(int i=0;i<t;i++){
        cout << pr[i].fi << " " << pr[i].se << endl;
    }*/
    sort(pr,pr+t,cmp);
    int maxx = 0;
    for(int i=0;i<t;i++){
        //out << tmp  << " " << pr[i].se << endl;
        ans = max(ans,pr[i].se-tmp-1);
        tmp = pr[i].fi;
        maxx = max(maxx,tmp);

    }
    int len = strlen(c);
    ans = max(len-maxx,ans);
    //cout << len-tmp << endl;
    cout << ans << endl;
    }
    //getchar();
}
}