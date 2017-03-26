#include<bits/stdc++.h>
#define ll long long
#define maxn 1005
using namespace std;
int main()
{
    ll m,n,k;
    cin >> k >> m >> n;
    n-=(k-1);
    m-=(k-1);
    if(n<=0)
    cout << "-1" << endl;
    else
    {

    ll t;
    int flag=0;
    //cout << m << n << endl;
    for(int i=1;i<=n;i++)
    {
        t=i;
       /* if(t>n)
        {
            //cout <<"-1" <<endl;
            return 0;
        }*/
        if(t*t>=m)
        {
            flag=1;
            break;
        }

    }
    if(!flag)
    cout <<"-1" <<endl;
    else
    {
        for(int i=1;i<k;i++)
        {
            cout << "1" << endl;
        }
        cout << t << endl;
    }


    }

}
