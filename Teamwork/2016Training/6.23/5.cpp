#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<=n;i++)
    {
        for(int j=n;j>i;j--)
            cout << "  ";
        for(int j=0;j<=i;j++)
        {
            cout <<j;
            if(i!=0)
            cout << " ";
        }
        for(int j=i-1;j>=0;j--)
        {
            cout << j;
            if(j)
            cout << " ";
        }
        cout << endl;
    }
    for(int i=n-1;i>=0;i--)
    {
        for(int j=i;j<n;j++)
            cout << "  ";
        for(int j=0;j<=i;j++)
        {
            cout <<j;
            if(i)
            cout << " ";
        }
        for(int j=i-1;j>=0;j--)
        {

            cout << j ;
            if(j)
            cout << " ";
        }
        cout << endl;
    }
}
