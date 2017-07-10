#include<bits/stdc++.h>
using namespace std;
#define maxn 10000005
#define ll long long
ll i,a[maxn],b[maxn],n;
void pre()
{

    b[0]=0;
    for(i=1;i<=n;i++)
    {
        b[i]=b[i-1]+i;
    }
}
int main()
{
    ll s,m,mina,maxa,k;
    while(scanf("%I64d %I64d",&n,&k)!=EOF)
    {
        pre();
        for(i=1;i<=n;i++)
        {
            scanf("%I64d",&a[i]);
        }

        for(i=1;i<=n;i++)
        {
            if(b[i]>=k)
            {
                s=i-1;
                break;
            }
        }

        ll x=k-b[s];
        printf("%I64d\n",a[x]);




    }
}
