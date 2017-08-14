#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+7;
const int maxe = 2853725;
const int maxq = 1e4+7;
const int maxp = 1024;
typedef long long ll;
typedef double db;
#define rep(a, b, c) for(int a=b; a<c; ++a)
const ll mod = 1e9 + 7;
bool vis[maxp];
int p[maxp], psz;
int f[maxn];
int b[30];
inline int myceil(int a, int b) {
    int ret=a/b;
    if(a%b) ++ret;
    return ret;
}
void init() {
    rep(i, 2, 32)
        if(!vis[i]) {
        for(int j=i*i; j<maxp; j+=i)
            vis[j]=true;
        }
    psz=0;
    rep(i, 2, maxp)
        if(!vis[i]) p[psz++] = i;
}
void calg(int x) {
    int m=0;
    for(int p=head[x]; p; p=p->nxt)
        b[m++]=p->v;
    int maxst=1<<m;
    for(int st=0; st<maxst; ++st) {
        int tmp=1;
        int selsz=0;
        for(int j=0; j<m; ++j)
            if(st>>j&1) {
                tmp = tmp*b[j];
                ++selsz;
            }
        int r=x/tmp;
        if(selsz&1) g[x] -= f[r];
        else g[x] += f[r];
        g[x] %= mod;
    }
}
void cal(int x) {
    f[x] = x+1;
    int m=int(sqrt(x+0.5));
    int y=myceil(x, m);
    int minm = min(m,y);
    int maxm = max(m, y);
    for(int i=1; i<minm; ++i) {
        f[x] += myceil(x,i)*2;
        if(f[x]>mod) f[x]-=mod;
    }
    for(int i=minm; i<maxm; ++i) {
        f[x] += myceil(x, i);
        if(f[x]>mod) f[x]-=mod;
    }
    f[x] -= m*myceil(x, m);
    f[x] %= mod;
    calg(x);
}
int main(){
    init();
    for(int i=1; i<maxn; ++i) {
        cal(i);
        ans[i] = (g[i]+ans[i-1])%mod;
        if(ans[i]<0) ans[i] += mod;
    }
    int x;
    while (~scanf("%d", &x))
        printf("%d\n", ans[x]);

    return 0;
}
