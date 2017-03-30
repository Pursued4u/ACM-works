#include<bits/stdc++.h>
using namespace std;
int n;
#define CLR(a) memset(a,0,sizeof(a))
#define MEM(a,x) memset(a,x,sizeof(a))
#define maxn 100005
int a[maxn];
int c[maxn];
int r[maxn];
int ans[maxn];
int abss(int x)
{
    return x>0?x:-x;
}
int lowbit(int x)
{
    return x&(-x);
}
int getsum(int k)
{
    int ans=0;
    while(k>0)
    {
        ans+=c[k];
        k-=lowbit(k);
    }
    return ans;
}
void update(int k,int v)
{
    while(k<=maxn)
    {
        c[k]+=v;
        k+=lowbit(k);
    }
}

int main()
{
    int t;
    int ca=1;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        CLR(c);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=n;i>=1;i--)
        {
            r[i]=i+getsum(a[i]);
            update(a[i],1);
            ans[a[i]]=abss(r[i]-min(i,a[i]));

        }
        printf("Case #%d:",ca++);
        for(int i=1;i<=n;i++)
        {
            printf(" %d",ans[i]);
        }
        cout << endl;
    }
}
