#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define maxn 200005
#define lowbit(x) x&(-x)
#define ll long long
int c[maxn];
int a[maxn],b[maxn],d[maxn];
int n;
#define CLR(x) memset(x,0,sizeof(x))

void init()
{
    CLR(c);
    CLR(b);
    CLR(d);
}
int getsum(int x)
{
    int ans = 0;
    while(x>0)
    {
        ans += c[x];
        x-=lowbit(x);
    }
    return ans;
}
void update(int x)
{
    while(x<=maxn)
    {
        c[x]+=1;
        x+=lowbit(x);
    }
}
void solve(){
    init();
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        update(a[i]);
        b[i]=getsum(a[i]-1);
        
    } 
    CLR(c);
    for(int i=n;i>0;i--)
    {
        update(a[i]);
        d[i]=getsum(a[i]-1);
    }
    ll ansr = 0;
    for(int i=2;i<n;i++)
    {
        ansr += (ll)b[i]*(ll)(n-i-d[i])+(ll)d[i]*(ll)(i-1-b[i]);
    }
    cout << ansr << endl;

    
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--) solve();
}