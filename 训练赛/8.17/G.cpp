#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include<vector>
#include<stack>
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

struct Q
{
    int a, b;
}A, B, C, D;

bool check(Q a, Q b, Q c)
{
    int sum;
    if(a.a==b.a)
    {
        sum = a.b+b.b;
        if(sum==c.a || sum==c.b)return true;
    }
    if(a.a==b.b)
    {
        sum = a.b+b.a;
        if(sum==c.a || sum==c.b)return true;
    }
    if(a.b==b.a)
    {
        sum = a.a+b.b;
        if(sum==c.a || sum==c.b)return true;
    }
    if(a.b==b.b)
    {
        sum = a.a+b.a;
        if(sum==c.a || sum==c.b)return true;
    }
    return false;
}


void solve()
{
    int flag = 0;
    map<int ,int>mp;
    cin >> A.a >> A.b;
    if(A.a > A.b)
    {
        swap(A.a, A.b);
        mp[A.a]++;
        mp[A.b]++;
        if(mp[A.a]>=3 || mp[A.b]>=3)flag = 1;
    }
    else if(A.a == A.b)
    {
        mp[A.b]++;
        if(mp[A.b]>=3)flag = 1;
    }
    else
    {
        mp[A.a]++;
        mp[A.b]++;
        if(mp[A.a]>=3 || mp[A.b]>=3)flag = 1;
    }
    //cout << flag << endl;
    cin >> B.a >> B.b;
    if(B.a > B.b)
    {
        swap(B.a, B.b);
        mp[B.a]++;
        mp[B.b]++;
        if(mp[B.a]>=3 || mp[B.b]>=3)flag = 1;
    }
    else if(B.a == B.b)
    {
        mp[B.b]++;
        if(mp[B.b]>=3)flag = 1;
    }
    else
    {
        mp[B.a]++;
        mp[B.b]++;
        if(mp[B.a]>=3 || mp[B.b]>=3)flag = 1;
    }
    //cout << flag << endl;
    cin >> C.a >> C.b;
    if(C.a > C.b)
    {
        swap(C.a, C.b);
        mp[C.a]++;
        mp[C.b]++;
        if(mp[C.a]>=3 || mp[C.b]>=3)flag = 1;
    }
    else if(C.a == C.b)
    {
        mp[C.b]++;
        if(mp[C.b]>=3)flag = 1;
    }
    else
    {
        mp[C.a]++;
        mp[C.b]++;
        if(mp[C.a]>=3 || mp[C.b]>=3)flag = 1;
    }
    //cout << flag << endl;
    cin >> D.a >> D.b;
    if(D.a > D.b)
    {
        swap(D.a, D.b);
        mp[D.a]++;
        mp[D.b]++;
        if(mp[D.a]>=3 || mp[D.b]>=3)flag = 1;
    }
    else if(D.a == D.b)
    {
        mp[D.b]++;
        if(mp[D.b]>=3)flag = 1;
    }
    else
    {
        mp[D.a]++;
        mp[D.b]++;
        if(mp[D.a]>=3 || mp[D.b]>=3)flag = 1;
    }
    //cout << flag << endl;
    if(flag)
    {
        puts("Yes");
        return;
    }
   // cout << "**"<<endl;
    flag = check(A,B,C);
    if(flag)
    {
        puts("Yes");
        return;
    }
    flag = check(A,B,D);
    if(flag)
    {
        puts("Yes");
        return;
    }
    flag = check(A,C,B);
    if(flag)
    {
        puts("Yes");
        return;
    }
    flag = check(A,C,D);
    if(flag)
    {
        puts("Yes");
        return;
    }
    flag = check(A,D,B);
    if(flag)
    {
        puts("Yes");
        return;
    }
    flag = check(A,D,C);
    if(flag)
    {
        puts("Yes");
        return;
    }
    flag = check(B,C,D);
    if(flag)
    {
        puts("Yes");
        return;
    }
    flag = check(B,C,A);
    if(flag)
    {
        puts("Yes");
        return;
    }
    flag = check(B,D,A);
    if(flag)
    {
        puts("Yes");
        return;
    }
    flag = check(B,D,C);
    if(flag)
    {
        puts("Yes");
        return;
    }
    flag = check(C,D,A);
    if(flag)
    {
        puts("Yes");
        return;
    }
    flag = check(C,D,B);
    if(flag)
    {
        puts("Yes");
        return;
    }
    puts("No");
}
int main()
{
    int t;
    cin >> t;
    while(t--)
        solve();

}
