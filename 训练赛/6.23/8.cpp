#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
    string a;
    cin >> a;

    s="";
    for(int i=0;i<a.length();i++)
    {
        if(a[i]=='A'||a[i]=='O'||a[i]=='I'||a[i]=='U'||a[i]=='E'||a[i]=='Y'||a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='y'||a[i]=='u')
            continue;
        else
        {
            s+='.';
            s+=tolower(a[i]);
        }
    }
    cout << s <<endl;
}
