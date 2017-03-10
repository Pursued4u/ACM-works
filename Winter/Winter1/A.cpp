#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans = 0;
    for(int i =0;i<n;i++)
    {
        int x;
        cin >> x;
        ans = max(ans,x);
    }
    cout << ans << endl;
}