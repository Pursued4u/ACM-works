#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define maxn 1000006
int a[maxn];
#define ll long long
int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++) a[i]=-1;
    for(ll i=0;i<n;i++)
    {
        a[i*i%n]=i;
    }
    for(ll i=0;i<n;i++)
    {
        if(i!=n-1)
        cout << a[i] << " ";
        else
        cout << a[i] << endl;
    }
    
    
}