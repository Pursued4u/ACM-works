#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a[100005];
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    int flag=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(a[i]<a[j]&&a[i]*2>a[j])
            {
                flag=1;
                break;
            }
        }
    }

    if(flag)
        cout << "YES" <<endl;
    else
        cout << "NO" <<endl;
}
