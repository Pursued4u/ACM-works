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
#define FILEIN freopen("dictionary.in", "r", stdin)
#define FILEOUT freopen("dictionary.out", "w", stdout)
#define CLOSEIO ios::sync_with_stdio(false)
#define PI acos(-1)
#define CLR(a) memset(a,0,sizeof(a))
#define MEM(a,x) memset(a,x,sizoef(a))
#define eps 1e-5
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
const int maxn = 4e5+5e4;
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
// C
int vis[26];
struct Trie{
    int ch[400001][26];
    int val[400001];
    int num[26];
    int sz = 0;
    Trie() {memset(ch[0],0,sizeof(ch[0]));for(int i=0;i<26;i++) num[i]=0;}
    int idx(char c) {return c-'a';}
    void insert(char *s,int v){
        int u = 0, n = strlen(s);
        for(int i=0;i<n;i++){
            int c = idx(s[i]);
            if(!ch[u][c]){
                if(!i) cout << s[i] << endl;
                memset(ch[sz],0,sizeof(ch[sz]));
                val[sz] = 0;
                ch[u][c] = ++sz;
                if(i)num[c]++;

            }
            u = ch[u][c];
        }
        val[u] = v;
    }
};
Trie fro,bak;
int main()
{
    //FILEIN;
    //FILEOUT;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        char s[50];
        scanf("%s",s);
        int len = strlen(s);
        fro.insert(s,len);
        reverse(s,s+len);
        bak.insert(s,len);
        if(len==1) vis[s[0]-'a']=1;
        //cout <<s << endl;
            //cout << fro.sz << " " << endl; //bak.sz << endl;

    }
    ll ans = 0;

    ans += ll(fro.sz)*ll(bak.sz);
    //cout << ans << endl;
    for(int i=0;i<26;i++){
    ans+=vis[i];
   // cout << fro.num[i] << " " << bak.num[i] << endl;
    ans-= ll(fro.num[i]) *ll(bak.num[i]);
    }
    cout << ans << endl;
}


