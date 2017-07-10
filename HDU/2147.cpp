#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    while(cin >> m >> n)
    {
        if(m==0)
        break;
        if((m*n)%2==0)
        cout << "Wonderful!" <<endl;
        else
        cout << "What a pity!"
    }
}
