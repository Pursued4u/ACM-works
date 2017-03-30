#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if(n<4)
    {
        cout << "NO" << endl;

    }
    else
    {
        cout << "YES" << endl;
        if((n%2)!=0)
        {
            cout << "3 + 4 = 7" << endl;
            cout << "7 + 5 = 12" << endl;
            cout << "12 * 2 = 24" << endl;

        }
        else
        {
            cout << "1 * 2 = 2" << endl;
            cout << "2 * 3 = 6" << endl;
            cout << "6 * 4 = 24" << endl;
        }
        for(int i=n;i>5;i-=2)
        {
            cout << i <<" - "<< i-1 <<" = " << "1" << endl;
            cout << "24 * 1 = 24" << endl;
        }

    }
}
