#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 70
ll a[maxn];

int main()
{
    //freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    a[1]=1;
    a[2]=2;
    a[3]=4;
    a[4]=8;
    a[5]=16;
    int b[maxn];
    for(int i=6;i<=100;i++)
    {

        ll x=a[i-1]*2;
        int k=0;
        while(1)
        {
            if(!x)
            break;
            b[k++]=x%10;
            x/=10;
        }
    sort(b,b+k);
    for(int j=0;j<k;j++)
    {
        a[i]=a[i]*10+b[j];
    }

    }
    int n;
    cin >> n;
    if(n<=30)
        cout<< a[n] << endl;
    else
    {
        n-=30;
        n%=6;
        cout<< a[n+30] << endl;
    }
 for(int i=1;i<100;i++)
    {
        cout<<i << " " << a[i] << endl;
    }


}
