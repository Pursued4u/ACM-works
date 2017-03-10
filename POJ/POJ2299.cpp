#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int n;
#define ll long long
struct Node
{
    int val;
    int id;
};
Node a[500001];
ll c[500001];
int cp[500001];
int lowbit(int x)
{
    return x&(-x);
}
bool cmp(const Node &a,const Node &b)
{
    return a.val<b.val;
}
void update(int t)
{
    int i;
    for(i = t ; i<=n;)
    {
        c[i]+=1;
        i+=lowbit(i);
    }
}
ll getsum(int x)
{
    int i;
    ll ans =0;
    for(i =x ; i>=1;)
    {
        ans+=c[i];
        i-=lowbit(i);
    }
    return ans;
}

int main()
{
    int i,j;
    while(scanf("%d",&n)!=EOF&&n)
    {
        for(int i=1; i<=n; i++)        {
            scanf("%d",&a[i].val);
            a[i].id=i;
        }
        sort(a+1,a+n+1,cmp);
        for(int i=1; i<=n; i++)
        {
            cp[a[i].id]=i;
        }
        memset(c,0,sizeof(c));
        ll ansr=0;
        for(int i=1; i<=n; i++)
        {
            update(cp[i]);
            ansr+=(i-getsum(cp[i]));
        }
        cout << ansr << endl;
    }

}



