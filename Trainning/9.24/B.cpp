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
const int maxn = 5e4+5;
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
map<string,int>mp;
string str[maxn];
string s;
int maxx=0;
int p=0;
int flag=0;
int flag1=0;
void init()
{
    mp.clear();
    for(int i=0;i<maxn;i++)
    str[i]="";
    s="";
    maxx=0;
    p=0;
    flag=0;
    flag1=0;

}
int main()
{

    s="";

    while(1)
    {
        char c=getchar();
        if(c==-1)
        break;
        if(c==' '||c==','||c=='.')
        {
            if(s!="")
            {
                str[p++]=s;
                s="";
            }
            if(c==' '&&flag==1)
            continue;
            else if(c!=' ')
            flag=0;
            s+=c;
            str[p++]=s;
            if(c==' ')
                flag=1;
            s="";
        }
        else if(c=='\n')
        {
            if(s!="")
            {
                str[p++]=s;
                s="";
            }
            s+='A';
            str[p++]=s;
            s="";

        }
        else
        {
            s+=c;
            flag=0;

            if(s=="####")
            {
                for(int i=0;i<p-2;i++)
                {
                    //cout << str[i] << endl;
                    if(str[i+1][0]==' '&&str[i][0]!=' '&&str[i][0]!='A'&&str[i][0]!='.'&&str[i][0]!=','&&str[i+2][0]!=' '&&str[i+2][0]!='#'&&str[i+2][0]!=','&&str[i+2][0]!='.')
                    {
                        string ans;
                        ans="";
                        ans+=str[i];
                        ans+=str[i+1];
                        ans+=str[i+2];
                        //cout << ans << endl;
                        mp[ans]++;
                        maxx=max(maxx,mp[ans]);
                    }
                }
        string ans;
        map<string,int>::iterator it;
        for(it=mp.begin();it!=mp.end();it++)
        {
            if(it->se==maxx)
            {
                if(ans==""||it->fi<ans)
                ans=it->fi;
            }
        }
        cout << ans << ":" << maxx <<endl;
        init();
            }
        }

    }
}
