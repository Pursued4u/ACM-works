#include<bits/stdc++.h>
#define ll long long
#define maxn 1005
using namespace std;
int main()
{
    ll n,m;
    scanf("%I64d %I64d",&n,&m);
    int k=0;
    ll sum=n;
    while(1)
    {
        if(sum>m)
        {
            cout << "NO" <<endl;
            break;
        }
        else if(sum<m)
        {
            sum*=n;
            k++;
        }
        else
        {

        cout << "YES" <<endl;
        cout << k << endl;
        break;
        }

    }



}

