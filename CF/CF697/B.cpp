#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    string c;
    string a;
    string b;
    int flag=0;
    cin >> s;
    int d=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='.')
        flag=1;
        if(s[i]=='e')
        flag=2;
        if(!flag)
        a+=s[i];
        else if(flag==1)
        {
            if(s[i]!='.')
            c+=s[i];
        }
        else
        {
            if(s[i]!='e')
            {
                d*=10;
                d+=s[i]-'0';

            }
        }
    }
    //cout << a << endl;
   // cout << d << endl;
   for(int i=0;i<d;i++)
   {
       if(i<c.length())
        a+=c[i];
       else
        a+='0';
   }
   int po=0;
   while(a[po]=='0'&&po<a.length()-1)
    po++;
//cout << po << endl;
    for(int i=po;i<a.length();i++)
    cout << a[i];
    int l=c.length();
    if(c.length()==1&&c[0]=='0')
    {
        cout << endl;
        return 0;
    }


        if(d<l)
    cout << ".";
        for(int i=d;i<c.length();i++)
        {
            cout << c[i];
        }

    cout << endl;
}
