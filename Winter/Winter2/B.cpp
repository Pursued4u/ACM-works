#include<cstdio>
#include<iostream>
using namespace std;
#define ll long long
int main()
{
    int n,m;
    cin >> n >> m;
    int cur = 1;
    ll ans = 0;
    for(int i=0;i<m;i++)
    {
        int x;
        cin >> x;
        if(x==cur) continue;
        if(x>cur) ans += x-cur;
        else ans += n+x-cur;
        cur = x;   
    }
    cout << ans << endl;
}