#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int n;
    cin >> n;
    cin >> s;
    int num[10];
    memset(num,0,sizeof(num));
    for(int i=0;i<s.length();i++)
    {
        num[s[i]-'0']++;
    }
    int flag=0;
    if(num[0]&&(num[1]||num[2]||num[3]))
    flag=1;
    else if(num[1]&&num[9])
    flag=1;
    else if(num[3]&&num[7])
    flag=1;
    else if(num[2]&&num[9]&&(num[5]||num[6]||num[4]))
    flag=1;
    if(flag)
    cout <<"YES"<<endl;
    else
        cout << "NO" <<endl;



}
