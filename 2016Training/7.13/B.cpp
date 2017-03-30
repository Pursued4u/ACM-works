#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 1005
char a[maxn][maxn];

int main()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    int m,n;
    cin >> m >> n;
    int ans=0;
    for(int i=0;i<m;i++)
    {
        cin >> a[i];
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
                if(a[i][j]=='+')
                {
                if(a[i-1][j]=='-'||a[i+1][j]=='-'||a[i][j-1]=='-'||a[i][j+1]=='-')
                ans++;



                }
        }
    }

    cout << ans << endl;
}
