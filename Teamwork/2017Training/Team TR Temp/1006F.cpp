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
const int maxn = 3e5+5;
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
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define rep(a,b,c) for(int (a)=(b); (a)<(c); ++(a))
#define drep(a,b,c) for(int (a)=(b); (a)>(c); --(a))
#define sf scanf
#define pf printf
typedef long long ll;
using namespace std;
const int MAXN = 3e5+1e3;
struct state {
    int len, pre, ch[27];
};
struct SAM {
    int sz, last;
    state st[maxn*2];
    state& operator[] (int x) {
        return st[x];
    }
    void init() {
        sz=1, last=0;
        st[0].len=0, st[0].pre=-1;
        CLR(st[0].ch);
    }
    void add(int c) {
        int cur=sz++, p;
        st[cur].len=st[last].len+1;
        CLR(st[cur].ch);
        for(p=last; p!=-1&&!st[p].ch[c]; p=st[p].pre)
            st[p].ch[c]=cur;
        if(p==-1) st[cur].pre=0;
        else {
            int q=st[p].ch[c];
            if(st[q].len==st[p].len+1)
                st[cur].pre=q;
            else {
                int clone=sz++;
                st[clone]=st[q];
                st[clone].len=st[p].len+1;
                st[cur].pre=st[q].pre=clone;
                for(; p!=-1&&st[p].ch[c]==q; p=st[p].pre)
                    st[p].ch[c]=clone;
            }
        }
        last=cur;
    }
} sam;
char s[maxn], t[maxn];
bool cmp(int al, int ar, int l, int r) {
    if(al==-1) return true;
    int ed=min(ar-al, r-l)+1;
    for(int i=0; i<ed; ++i) {
        if(s[i+al]<s[i+l]) return false;
        if(s[i+al]>s[i+l]) return true;
    }
    if(r-l<ar-al) return true;
    return false;
}
void solve(){
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    sam.init();
    for(int i=1; i<n; ++i) {
        scanf("%s", t);
        for(char* p=t; *p; ++p)
            sam.add(*p-'a');
        sam.add(26);
    }
    int l=0, al=-1, ar=-1;
    int u=0;
    for(int r=0; s[r]; ++r) {
        while(l<=r&&sam[u].ch[s[r]-'a']==0) {
            if(cmp(al, ar, l, r))
                al = l, ar=r;
            u=sam[u].pre;
            l=r-sam[u].len+1;
        }
        u=sam[u].ch[s[r]-'a'];
    }
    if(al==-1) puts("Impossible");
    else {
        s[ar+1]='\0';
        puts(s+al);
    }
}
int main(){
    int t = Read();
    int ca = 0;
    while(t--) {
        printf("Case #%d: ", ++ca);
        solve();
    }
    return 0;
}
