#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[105][105];
int main()
{
    int n;
    cin >> n;
    ll ans = 0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {cin >> a[i][j];
        ans +=a[i][j];}
    ll sum = ans/(n-1);
    for(int i=0;i<n;i++)
    {
        ll tmp = 0;
        for(int j=0;j<n;j++)
        {
            if(j==i)
            continue;
            tmp += a[i][j];
        }
        a[i][i] = sum-tmp;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j!=n-1)
            cout << a[i][j] << " " ;
            else
            cout << a[i][j];
        }
        cout << endl;
    }
}