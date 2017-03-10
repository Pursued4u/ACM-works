#include<iostream>
#include<string>
using namespace std;
int yyy(int x){
    if(x<=0)
    return -x;
    else
    return x;
}
int main()
{
    string a,b;
    cin >> a >> b;
    for(int i=0;i<a.length();i++)
    {
        a[i] = yyy((a[i]-'0')-(b[i]-'0'))+'0';
    }
    int flag=0;
    for(int i=0;i<a.length();i++){
        if(!flag&&a[i]!='0')
        flag=1;
        if(flag==1)
        cout << a[i];
    }
    if(!flag)
    cout <<0;
    cout << endl;
}