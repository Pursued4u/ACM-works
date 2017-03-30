#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int t;
    cin >> t;
while(t--)
    {
    s="";
    cin >> s;
    int flag;
    flag=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='D')
        {
            flag=1;
            break;
        }
    }
    if(flag)
    cout << "You shall not pass!" <<endl;
    else
        cout << "Possible" << endl;
}
}
