#include<cstdio>
#include<malloc.h>
#include<iostream>
#include<stdlib.h>
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
const int maxn = 1e6+5;
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

struct Q
{
    char a;
    Q *next = NULL, *last = NULL;
};
Q *first, *last;

char str[maxn];
void solve()
{
    scanf("%s", str);
    int len = strlen(str);
    Q *q, *p, *temp = NULL;
    Q *jj;
    q = p = first = last = NULL;
    for(int i=0; i<len; i++)
    {
        //printf("%p\n", jj);
        //cout << str[i] <<endl;
        if(str[i]=='<')
        {
            if(first==NULL)
            {
                jj = q;
               // printf("%p\n", jj);
                continue;
            }
            else if(q == q->last)
            {
                first = NULL;
                temp = q;
                jj = q;
            }
            else
            {
                q = q->last;
                temp = q->next;

            }
            //cout << q->a<<endl;
        }
        else if(str[i]=='>')
        {
            if(first==NULL)first = q;
            if(q->next==NULL)continue;
            q = q->next;
            temp = q->next;
        }
        else if(str[i]=='-')
        {

            if(q==q->last)
            {
                if(first==NULL)continue;
                first = NULL;
                //printf("%p\n", q->next);
                if(q->next==NULL) continue;
                //cout <<"------"<<endl;
                temp->last = temp;
                temp = temp->last;
                continue;
            }
            //cout <<"___"<<endl;
            q = q->last;
            delete q->next;
            q->next = temp;
            //printf("%p\n", temp);
        }
        else
        {
            p = (Q*)new (Q);
            p->next = temp;
            p->a = str[i];
            if(first == NULL)
            {
                first = p;
                //printf("%p\n", first);
                first->last = p;
            }
            else
            {
                p->last = q;
                q->next = p;
            }
            if(q==last) last = p;
            q = p;
        }
    }
    //cout << "---"<<endl;
    q = first;
    if(q==NULL)
        q=temp;


    while(q!=NULL)
    {
        //printf("%p\n", q);
        cout << q->a;
        q = q->next;
    }
    cout << endl;
}

int main()
{
    //FILEIN;
    int t;cin >> t;
    while(t--) solve();
    return 0;
}
