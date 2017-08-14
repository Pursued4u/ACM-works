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
const int MAXL=1e5+1e3;
struct BigNum{
    int d[MAXL], l;
    void clear() {
        memset(d, 0, sizeof(d));
        l=0;
    }
    void add(int pos) {
        d[pos]++;
        if(d[pos]>=26) {
            d[pos+1] += d[pos]/26;
            d[pos] %=26;
            ++pos;
        }
        if(pos>l) l=pos;
    }
    int pare (BigNum& b) {
        if(l!=b.l) return l-b.l;
        for(int i=l; i>=0; --i) {
            if(d[i]!=b.d[i])
                return d[i]-b.d[i];
        }
        return 0;
    }
    ll val() {
        ll ret=0, tot=1;
        for(int i=0; i<=l; ++i) {
            ret = (ret+d[i]*tot)%mod;
            tot = tot*26%mod;
        }
        return ret;
    }

}cnt[26];
int sa[26], rk[26];
bool not0[26];
char line[MAXL];
int DBG = 0;
bool cmp(int a, int b) {
    int ret=cnt[a].pare(cnt[b]);
    if(ret==0) ret = a-b;
    return ret<0;
}
ll cal() {
    ll ret=0;
    for(int i=0; i<26; ++i)
        rk[sa[i]] = i;
    for(int i=0; i<26; ++i) {
        if(DBG) printf("%c %d\n", 'a'+i, rk[i]);
        ret += rk[i]*cnt[i].val()%mod;
    }
    return ret%mod;
}
int main()
{
    int n, ca=1;
    while(scanf("%d",&n)!=EOF){
        for(int i=0; i<26; ++i) {
            cnt[i].clear();
            sa[i] = i;
        }
        memset(not0, false, sizeof(not0));
        while(n--) {
            scanf("%s", line);
            int l=strlen(line);
            if(l>1) {
                not0[line[0]-'a'] = true;
            }
            for(int i=0; i<l; ++i)
                cnt[line[i]-'a'].add(l-i-1);
        }
        if(DBG) puts("dfae");
        sort(sa, sa+26, cmp);
        if(DBG) puts("dfaefe");
        if(not0[sa[0]]) {
            int j;
            for(j=1; j<26; ++j)
                if(!not0[sa[j]]) break;
            //printf("%d\n", j);
            int temp = sa[j];
            for(int k=j; k>0; --k)
                sa[k]=sa[k-1];
            sa[0] = temp;
        }

        printf("Case #%d: ",ca++);
        printf("%d\n", cal());
    }
}
