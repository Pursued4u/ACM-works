#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[105];
int main()

{
    int n,m;
    cin >> m;
    ll temp=0;
    ll sum;
    for(int i=1;i<=m;i++)
    {
        scanf("%I64d",&a[i]);
        if(i>1)
        sum=(a[i]-1)*i+1;
        else
        sum=a[i];
        temp+=sum;
    }
    cout << temp << endl;
}
