#include<bits/stdc++.h>
using namespace std;

bool judge(int x)
{
    return x%400==0||x%4==0&&x%100!=0;
}

int main()
{
    int n;
    cin >> n;
    int ans=0;
    int j = judge(n);
    for(;;)
    {
        if(judge(n))
        ans+=2;
        else
        ans+=1;
        n++;
        ans%=7;
        if(ans==0&&judge(n)==j)
        break;
    }
    cout  << n << endl;
}

