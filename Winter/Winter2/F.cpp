#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;
#define ll long long
int main()
{
    int a,b,c,d;
    cin >> a >> b >> c >>d;
    if(b*c==a*d)
    {
        cout << "0/1" << endl;
        return 0;
    }
    int ans1 = b*c;
    int ans2 = a*d;
    int tmp = __gcd(ans1,ans2);
    ans1/=tmp;
    ans2/=tmp;
    cout << max(ans1,ans2)-min(ans1,ans2) <<"/"<< max(ans1,ans2) << endl;
}