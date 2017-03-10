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
struct Game
{
     char name[35];
     char date[35];
     int pronum;
     int vis[50];
     int vis1[50];
}g[maxn];
int main()
{
    //FILEIN;
    int n;
    cin >> n;
    getchar();
    puts("+------------------------------+--------+-------------+");
    puts("|Contest name                  |Date    |ABCDEFGHIJKLM|");
    for(int i=0;i<n;i++)
    {
        

        gets(g[i].name);
        //getchar();
        gets(g[i].date);
        puts("+------------------------------+--------+-------------+");
        printf("|%-30s|",g[i].name);
        printf("%s|",g[i].date);
        int t;
        cin >> g[i].pronum >>t;
        getchar();
        for(int j=0;j<t;j++)
        {
            char ans[105];
            gets(ans);
            g[i].vis1[ans[0]-'A']=1;
            if(ans[2]=='A')
            g[i].vis[ans[0]-'A']=1;
            
        }
        /*for(int j=0;j<g[i].pronum;j++)
        {
            cout <<g[i].vis[j];
        }
        cout << endl;
        */
        for(int j=0;j<g[i].pronum;j++){
        if(g[i].vis[j])
        cout <<"o";
        else if(g[i].vis1[j])
        cout << "x";
        else
        cout << ".";
        
    }
    for(int j=0;j<13-g[i].pronum;j++)
    cout << " ";
    cout << "|\n";

    }
    
    
    puts("+------------------------------+--------+-------------+");
    
}
