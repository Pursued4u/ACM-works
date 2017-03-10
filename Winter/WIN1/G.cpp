#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int ans1,ans2;
    ans1=ans2=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='0') ans1++;
        else ans2 ++;
    }
    cout << min(ans1,ans2) << endl;
}