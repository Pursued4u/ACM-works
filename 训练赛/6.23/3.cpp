#include<bits/stdc++.h>
using namespace std;
int main()
{
    int maxx=0;
    int n;
    int x,y;
    cin >> n;
    int maxxx;
    maxxx=0;
    while(n--)
    {
        cin >> x >> y;
        maxx-=x;
        maxx+=y;
        maxxx=max(maxxx,maxx);
    }
    cout << maxxx << endl;
}
