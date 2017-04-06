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
const int maxn = 5e3+5;
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
struct node{
    db x;
    db v;
    db last;
    node (int xx,int vv) {
        x = xx;
        v = vv; 
    }
    node () {}
};
bool cmp(node a,node b){
    if(a.x==b.x) return a.v < b.v;
    else return a.x < b.x;
}
stack<node>st;
node l[maxn],rl[maxn];
int main()
{
    FILEIN;
    int t; cin >> t;
    while(t--){
        while(st.size()) st.pop();
        int k = 0;
        int n; cin >> n;
        for(int i=0;i<n;i++){
            db xx,vv; scanf("%lf %lf",&xx,&vv);
            l[k++] = node(xx,vv);
        }
    sort(l,l+k,cmp);   
    int num = 0;
    for(int i=0;i<n-1;i++){
        if(l[i].x==l[i+1].x);
        else rl[num++] = l[i];
    }
    rl[num++] = l[n-1];
    if(num<2){
        cout << num << endl;
        continue;
    }
    else{
        rl[0].last = -inf;
        int cur = 1;
        st.push(rl[0]);
        while(!st.empty()){
            cout << st.size() << endl;
            if(cur>=num) break;
            node nl = rl[cur];
            node dl = st.top();
            double np = (nl.v-dl.v)/(dl.x-nl.x);
           // cout << np << " " << dl.last << endl;
            if(dl.last+eps>=np){
                st.pop();
                continue;
            }
            else{
                nl.last = np;
                st.push(nl);
                cur++;
            }
        }
    cout << st.size() << "\n";
    }
    }
}



