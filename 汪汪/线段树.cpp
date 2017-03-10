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
int Node[2*maxn];
int n,m;
void init(int n){
    m = 1;
    while(m<n) m=m<<1; // 为了简单起见 把元素个数变成2的幂个
    for(int i=0;i<2*m-1;i++) Node[i] = inf;

}
// 插入更新操作
void Update(int x,int v){
    x += m-1; //找到叶子节点
    Node[x] = v;
    while(x>0){
        x = (x-1)/2.0;
        Node[x] = min(Node[x*2+1],Node[x*2+2]);
    }
}
// 询问[l,r)的最值
// 外部调用时候 应该用query(l-1,r,0,m,0)
// a,b为你想查找的区间 l,r为当前搜索的区间
int query(int a,int b,int l,int r,int k){
    if(r<=a||l>=b) return inf; //如果两个区间没有交集 返回一个最大值
    if(l>=a&&r<=b) return Node[k]; //如果当前搜索的区间包含在你想搜索的区间中 返回当前节点的值
    else{ //如果有交集 继续往深一层搜索
        int vl = query(a,b,l,(l+r)/2,k*2+1);
        int vr = query(a,b,(l+r)/2,r,k*2+2);
        return min(vl,vr);
    }
}
int main()
{
    cin >> n;
    init(n);
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        Update(i,x);
        
    }
    
    int q; cin >> q;
    for(int i=0;i<q;i++){
        int l,r;
        cin >> l >> r;
        int minn = query(l-1,r,0,m,0);
        cout << minn << endl;
    }
    
}



