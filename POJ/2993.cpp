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
char str1[100] = {"+---+---+---+---+---+---+---+---+"};
char str2[100] = {"|:::|...|:::|...|:::|...|:::|...|"};
char str3[100] = {"|...|:::|...|:::|...|:::|...|:::|"};

char mapp[100][100];
void pos(int x,int y, char xx){
    mapp[(8-y)*2+1][4*x+2] = xx;
}
void solve(){
    for(int i=0;i<17;i++){
        if(i%4==1)  strcpy(mapp[i],str3);
        else if(i%4==3) strcpy(mapp[i],str2);
        else strcpy(mapp[i],str1);
    }
    char str[100];
    scanf("%s",str);
    scanf("%s",str);
    for(int i=0;i<strlen(str);){
        if(str[i]>64&&str[i]<91&&str[i]!='W'){
            int x = str[i+1]-'a';
            int y = str[i+2]-'0';
            char xx = str[i];
            pos(x,y,xx);
        }
        else if(str[i]>96&&str[i]<123&&str[i-1]==','){
            int x = str[i]-'a';
            int y = str[i+1]-'0';
            char xx = 'P';
            pos(x,y,xx);
        }
        i++;
    }
    scanf("%s",str);
    scanf("%s",str);
    for(int i=0;i<strlen(str);){
        if(str[i]>64&&str[i]<91&&str[i]!='W'){
            int x = str[i+1]-'a';
            int y = str[i+2]-'0';
            char xx = str[i]+32;
            pos(x,y,xx);

        }
        else if(str[i]>96&&str[i]<123&&str[i-1]==','){
            int x = str[i]-'a';
            int y = str[i+1]-'0';
            char xx = 'p';
            pos(x,y,xx);
        }
        i++;
    }
    for(int i=0;i<17;i++) puts(mapp[i]);
}
int main(){
    int t = 1;
    int ca = 1;
    while(t--) solve();
    return 0;
}
