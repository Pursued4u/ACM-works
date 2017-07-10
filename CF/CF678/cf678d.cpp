#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9+7;
int main()
{
    ll a,b,n,x;

    cin >> a >> b >> n >> x;
    ll ans=x;
    if(!n)
    cout << x << endl;
    else
    {
    for(int i=1;i<=n;i++)
    {
        ans*=a;
        ans+=b;
        ans%=mod;
    }
    cout << ans << endl;
    }
}
