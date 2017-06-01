#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
#define ll long long
ll cc(ll x,ll y)
{
    ll ans=1;
    ll ans2=1;
    for(ll i=x;i>=1;i--)
    {
        ans*=y--;
        ans2*=i;
    }
    return ans/ans2;
}
ll abss(ll x)
{
    return x>0?x:-x;
}
int main()
{
    ll a[55];
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        ll ans1=0;
        ll ans2=0;
        for(ll i=1;i<=n;i++)
        {
            cin >> a[i];
            ans1+=a[i];
        }
        sort(a+1,a+1+n);
        cout << a[n] << endl;



    }

}
