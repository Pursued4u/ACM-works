#include<cstdio>
#include<iostream>
using namespace std;
int a[200005];
int main()
{
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n/2;i++)
    {
        if(i%2)
        swap(a[i],a[n-i+1]);
    }
    for(int i=1;i<=n;i++)
    {
        if(i!=n)
        cout << a[i] << " ";
        else
        cout << a[i] << endl;
    }
}