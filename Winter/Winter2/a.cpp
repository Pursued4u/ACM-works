#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int a,b,c;
    a=b=c=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='1') a++;
        if(s[i]=='2') b++;
        if(s[i]=='3') c++;
    }
    if((a+b+c)==1)
    {
        while(a) {cout <<'1'<< endl; a--;}
        while(b) {cout <<'2'<< endl; b--;}
        while(c) {cout <<'3'<< endl; c--;}
    }
    for(int i=0;i<(a+b+c);i++)
    {
        if(i<a)
        cout <<"1";
        if(i>=a&&i<a+b)
        cout << "2"; 
        if(i>=a+b&&i<a+b+c)
        cout << "3";
        if(i==a+b+c-1)
        cout << endl;
        else
        cout << "+";
    }
}
