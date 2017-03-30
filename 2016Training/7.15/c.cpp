#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    ll p,q;
    cin >> p >> q;
    long long i=1;
    while(p)
    {
        p*=i++;
        cout << (p/q) << " ";
        p%=q;
    }
    cout << endl;
    return 0;



}
