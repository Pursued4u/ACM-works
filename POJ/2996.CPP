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
#define _ixvii0iv
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
inline ll Read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
char a[100][100];
char str[100];
int vis[100][100];
vector<string>v1,v2;
string search(int pos,char x){
    string s="";
    if(pos == 7){
        for(int i=pos;i>=0;i--){
            int len = strlen(a[i]);
            for(int j=0;j<len;j++){
                if(a[i][j]==x&&!vis[i][j]){
                    if(x!='P')s+=x;
                    s+=(j/4+'a');
                    s+=(8-i+'0');
                    vis[i][j] = 1;
                    return s;
                }
            }
        }
    }
    else{
        for(int i=0;i<8;i++){
            int len = strlen(a[i]);
            for(int j=0;j<len;j++){
                if(a[i][j]==x&&!vis[i][j]){
                    if(x!='p') s+=(x-32);
                    s+=(j/4+'a');
                    s+=(8-i+'0');
                    vis[i][j] = 1;
                    return s;
                }
            }
        }
    }
    return s;
}
void solve(){
    int cnt = 0;
    for(int i=0;i<17;i++){
        scanf("%s",str);
        if(str[0]!='+')
        strcpy(a[cnt++],str);
    }
    string ans = "KQRRBBNNPPPPPPPP";
    int len = ans.size();
    for(int i=0;i<len;i++){
        string s = search(7,ans[i]);
        if(s!="")v1.PB(s);
    }
    for(int i=0;i<len;i++){
        string s = search(0,ans[i]+32) ;
        if(s!="") v2.PB(s);
    }

    cout << "White: ";
    for(int i=0;i<v1.size();i++)
    {
        if(i!=v1.size()-1)cout << v1[i] << ",";
        else cout << v1[i] << endl;
    }

    cout << "Black: ";
    for(int i=0;i<v2.size();i++)
    {
        if(i!=v2.size()-1)cout << v2[i] << ",";
        else cout << v2[i] << endl;
    }



    /*show me your code*/
}
int main(){
    int t = 1;
    int ca = 1;
    while(t--) solve();
    return 0;
}
