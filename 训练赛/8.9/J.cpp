#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include<stack>
#include<vector>
#include<queue>
#define FILEIN freopen("in.txt", "r", stdin)
#define FILEOUT freopen("output.txt", "w", stdout)
#define CLOSEIO ios::sync_with_stdio(false)
#define PI acos(-1)
#define CLR(a) memset(a,0,sizeof(a))
#define MEM(a,x) memset(a,x,sizoef(a))
#define eps 1e-8
#define scf(x) scanf("%d",&x)
#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)
#define lowbit(x) x&(-x)
#define db double
#define rep(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define drep(a,b,c) for(int (a)=(b);(a)>(c);--(a))
#define dbg(x) cout << #x << "=" << x << endl


using namespace std;
const int maxn = 5e4+5;
typedef long long ll;
const int inf = ((1ll<<29)-10);
const ll mod = 1000000007;
int mul(int x,int y){return 1LL*x*y%mod;}
int qpow(int x , int y){int res=1;while(y){if(y&1) res=mul(res,x) ; y>>=1 ; x=mul(x,x);} return res;}
int Read() {
    int x = 0, F = 1; char C = getchar();
    while (C < '0' || C > '9') { if (C == '-') F = -F; C = getchar(); }
    while (C >= '0' && C <= '9') { x = x * 10 - '0' + C, C = getchar(); }
    return x * F;
}
struct pos
{
    int v;
    int id;
};
int main()
{
    //FILEIN;
    //FILEOUT;
    //CLOSEIO;
    int n;
    int ca=1;
    while(cin >> n&&n!=0)
    {
        printf("Case #%d:\n",ca++);
        stack<pos>a,b,c,d;
        for(int i=1;i<=n;i++)
        {
            char op[10];
            scanf("%s",op);
            if(op[1]=='u')
            {
                char x;
                int y;
                getchar();
                scanf("%c %d",&x,&y);
                pos cnt;
                cnt.v=y;
                cnt.id=i;
                if(x=='A')
                {
                    a.push(cnt);
                }
                else
                {
                    b.push(cnt);
                }
            }
            else if(op[1]=='o')
            {
                char x;
                getchar();
                scanf("%c",&x);
                pos cnt;
                if(x=='A')
                {
                    if(!a.empty()) {cnt=a.top(); a.pop();}
                    else {cnt=d.top(); d.pop();}
                }
                else
                {
                    if(!b.empty()) {cnt=b.top(); b.pop();}
                    else {cnt = d.top(); d.pop();}

                }
                cout << cnt.v << endl;
            }
            else
            {

                char xx[20];
                gets(xx);

                while(!a.empty()&&!b.empty())
                {
                    int aid=a.top().id;
                    int bid=b.top().id;
                    if(aid>bid)
                    {
                        pos cnt=a.top();
                        c.push(cnt);
                        a.pop();
                    }
                    else
                    {
                        pos cnt = b.top();
                        c.push(cnt);
                        b.pop();
                    }
                }
                    while(!a.empty())
                    {
                        pos cnt = a.top();
                        c.push(cnt);
                        a.pop();
                    }
                    while(!b.empty())
                    {
                        pos cnt = b.top();
                        c.push(cnt);
                        b.pop();
                    }
                    while(!c.empty())
                    {
                    pos cnt = c.top();
                    d.push(cnt);
                    c.pop();
                    }

            }

        }

    }


}
