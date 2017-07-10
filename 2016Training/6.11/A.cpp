#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 100005
#define double double
int m,n,i;

int main()
{
    string a;
    int dp[maxn];
    while(cin >> a&&a!="0")
    {
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        dp[1]=1;
        n=a.length();
        for(i=1;i<a.length();i++)
        {
            if(a[i]!='0') dp[i+1]=dp[i];
            if(a[i-1]=='1'||a[i-1]=='2'&&a[i]<'7') dp[i+1]+=dp[i-1];

        }
        cout << dp[n] << endl;
    }
}
