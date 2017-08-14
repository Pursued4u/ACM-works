#include<bits/stdc++.h>
using namespace std;
map<char,int>mp;


int main()
{
mp['6']=0;
mp['7']=1;
mp['8']=2;
mp['9']=3;
mp['T']=4;
mp['J']=5;
mp['Q']=6;
mp['K']=7;
mp['A']=8;
mp['S']=1;
mp['H']=2;
mp['D']=3;
mp['C']=4;

    char a[5];
    char b[5];
    char x;
    cin >> x;
    getchar ();
    scanf("%s %s",a,b);
    if(a[1]==x&&b[1]!=x)
    cout << "YES" <<endl;
    else if(a[1]!=x&&b[1]==x)
    cout << "NO" <<endl;
    else if(a[1]==b[1])
    {
        if(mp[a[0]]>mp[b[0]])
            cout<< "YES" <<endl;
        else
            cout << "NO" <<endl;
    }
    else
    cout << "NO" <<endl;


}
