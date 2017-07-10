#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int flag=0;
        for(int i=0;i<n;i++)
        {   int a;
            cin >> a;
            int ans=(int )sqrt(a);
            if(ans*ans!=a)
            flag=1;
        }
        if(flag)
        cout << "No" << endl;
        else
            cout << "Yes" << endl;

    }

}
