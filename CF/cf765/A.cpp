#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    string a;
    a= s;
    for(int i=0;i<n;i++)
    {
        string tmp;
        string tmp1 ,tmp2;
        cin >> tmp;
        tmp1=tmp2 ="";
        for(int j=0;j<3;j++)
        tmp1+=tmp[j];
        for(int j=5;j<tmp.length();j++)
        tmp2+=tmp[j];
        if(tmp1==s) s= tmp2;
    }
  
    if(a==s)
    cout << "home" << endl;
    else
    cout << "contest" << endl;
}