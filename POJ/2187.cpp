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
struct point{
    ll x,y;
    point(){}
    point(int _x,int _y){
        x = _x;
        y = _y;
    }
    point operator -(const point &b){
        return point(x-b.x,y-b.y);
    }
    ll operator ^(const point &b){
        return 	(x*b.y-y*b.x);
    }
    ll operator *(const point &b){
        return	(x*b.x+y*b.y);
    }
};
ll Dis(point a,point b){
    return (a-b)*(a-b);
}
point p[maxn];
int st[maxn],top;
bool cmp(point a,point b){
    ll tmp = (a-p[0])^(b-p[0]);
    if(tmp>0) return true;
    else if(!tmp&&Dis(a,p[0])<=Dis(b,p[0])) return true;
    else return false;
}
void Graham(int n){
    point cur;
    int k = 0;
    cur = p[0];
    for(int i=1;i<n;i++){
        if(cur.y>p[i].y||(cur.y==p[i].y&&cur.x>p[i].x)){
            cur = p[i];
            k = i;
        }
    }
    swap(p[k],p[0]);
    sort(p+1,p+n,cmp);
    if(n==1){
        top = 1;
        st[0] = 0;
        return;
    }
    if(n==2){
        top = 2;
        st[0] = 0;
        st[1] = 1;
        return;
    }
	st[0] = 0;
	st[1] = 1;
	top = 2;
    for(int i=2;i<n;i++){
        while(top>1&&((p[st[top-1]]-p[st[top-2]])^(p[i]-p[st[top-2]]))<=0) top--;
        st[top++] = i;
    }
}

ll Max_trangle_area(point p[],int n){
    ll ans =  0;
    point v;
    for(int i=0;i<n;i++){
        int j = (i+1)%n;
        int k = (j+1)%n;
        while(j!=i&&k!=i){
            ans = max(ans,abs((p[j]-p[i])^(p[k]-p[j])));
            while( ((p[i]-p[j])^(p[k+1%n]-p[k])) < 0){
                k = (k+1)%n;
            }
            j = (j+1)%n;
        }
    }
    return ans;
}
ll Max_Dis_Twopoints(point p[],int n){
	ll ans = 0;
	point v;
	int cur = 1;
	for(int i=0;i<n;i++){
		v = p[i]-p[(i+1)%n];
		while((v^(p[(cur+1)%n]-p[cur]))<0)
			cur = (cur+1)%n;
		ans = max(ans,max(Dis(p[i],p[cur]),Dis(p[(i+1)%n],p[(cur+1)%n])));

	}
	return ans;
}

int main(){

    int n;
    while(scanf("%d",&n)!=EOF){
		top = 0;
		for(int i=0;i<n;i++){
			int x = Read();
			int y = Read();
			p[i] = {x,y};
    }
    Graham(n);
    for(int i=0;i<top;i++) p[i] = p[st[i]];
    ll ans = Max_Dis_Twopoints(p,top);
    cout << ans << endl;
    }
}
