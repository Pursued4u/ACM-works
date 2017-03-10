#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    int a[55];
    for(int i=0;i<m;i++)
    cin >> a[i];
    sort(a,a+m);
    int minn = 100000005;
    int k=0;
    for(int i=n-1;i<m;i++)
    {
        minn =min(a[i]-a[k++],minn);
    }
    cout << minn << endl;
}