#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<cstring>
#include<queue>
#include<set>
#include<string>
#include<map>
#define inf 9223372036854775807
#define INF 9e7+5
#define PI acos(-1)
#define   mem(x,v)      memset(x,v,sizeof(x))
using namespace std;
typedef long long ll;
typedef long long LL;
typedef double db;
const int MAX = 1e3 + 5;
const int mod = 1e9 + 7;
const db eps = 1e-9;
// D
int ch[32*MAX][2];
LL val[32*MAX];
int num[32*MAX];
int sz;
LL b[MAX];

void init(){
    mem(ch[0],0);
    sz=1;
}

void inser(LL a){
    int u=0;
    for(int i=32;i>=0;i--){
        int c=((a>>i)&1);
        if(!ch[u][c]){
            mem(ch[sz],0);
            val[sz]=0;
            num[sz]=0;
            ch[u][c]=sz++;
        }
        u=ch[u][c];
        num[u]++;
    }
    val[u]=a;
}
void update(LL a,int d){
    int u=0;
    for(int i=32;i>=0;i--){
        int c=((a>>i)&1);
        u=ch[u][c];
        num[u]+=d;
    }
}
LL query(LL a){
    int u=0;
    for(int i=32;i>=0;i--){
        int c=((a>>i)&1);
        if(ch[u][c^1]&&num[ch[u][c^1]]) u=ch[u][c^1];
        else u=ch[u][c];
    }
    return a^val[u];
}
void solve() {
    int n, p[MAX]; scanf("%d", &n);

    init();

    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
        inser(p[i]);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        update(p[i], -1);
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            update(p[j], -1);
            ans = max(ans, query(p[i]+p[j]));
            update(p[j], 1);
        }
        update(p[i], 1);
    }
    printf("%I64d\n", ans);
}

int main() {
    //cin.sync_with_stdio(false);
    //freopen("tt.txt", "r", stdin);
    //freopen("isharp.out", "w", stdout);
    int t; cin >> t;
    while (t--)
        solve();

    return 0;
}
