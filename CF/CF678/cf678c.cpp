#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    if(!b)
    return a;
    else
    return gcd(b,a%b);

}

int main()
{
    long long n,a,b,q,p;
    long long ans;
    ans=0;
    cin >> n >> a >> b >> p >> q;
    ans+=n/a*p;
    ans+=n/b*q;
    ans-=n/(a*b/gcd(a,b))*min(p,q);
    cout << ans  << endl;
}
