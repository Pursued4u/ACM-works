#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define maxn 105
int a[maxn];
int main()
{
    int m,n;
    cin >> m >> n;
    int i;
    int ans=0;
    for(i=1;i<=m;i++)    cin >> a[i];
    if(a[n])
    ans++;
    for(i=1;i<=min(n-1,m-n);i++)
    {
        if(a[n+i]&&a[n-i])
        ans+=2;
    }
    if(n-1<m-n)
    {
        for(i=2*n;i<=m;i++)
        {
            if(a[i])
            ans++;
        }
    }
    else
    {
        for(int i=2*n-m-1;i>=1;i--)
        {
            if(a[i])
            ans++;
        }
    }
    cout << ans << endl;

}
