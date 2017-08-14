#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    cin >> a;
    int cnt;
    cnt=0;
    int x;
    while(a.length()>1)
    {
        cnt++;
        x=0;
        for(int i=0; i<a.length(); i++)
        {
            x+=(a[i]-'0');
        }
        a="";

        while(x!=0)
        {
        a+=((x%10)+'0');
        x/=10;
        }
    }
    cout << cnt << endl;
}
