#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll prime[100005];
ll numm[1005];
int a[1005];
int cal(int x)
{
    int sum=0;
    for(int i=2;i>0;i++)
    {

        if(x<i)
        break;
        if(x%i==0) sum++;
        while(x%i==0)
        x/=i;

    }
    return sum;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int cnt=1;
        int n;
        cin >> n;
        for(int i=30;i>0;i++)
        {
            if(cal(i)>=3)
            a[cnt++]=i;
            if(cnt==1005)
            break;
        }
        cout << a[n] << endl;
    }
}
