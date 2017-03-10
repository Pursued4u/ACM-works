#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn (int)1e5+6
#define ll long long
ll a[maxn];
int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)cin >> a[i];
    sort(a,a+n);
    int flag=0;
    for(int i=1;i<n-1;i++)
    {
        if(a[i]+a[i-1]>a[i+1])
        flag=1;
    }
    if(flag)
    cout << "YES" << endl;
    else
    cout << "NO" << endl;
    
}