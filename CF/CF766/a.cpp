#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    string a;
    cin >> s >> a;
    if(s==a)
    cout << -1 << endl;
    else
    cout << max(a.size(),s.size()) << endl;

}
