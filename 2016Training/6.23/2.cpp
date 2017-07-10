#include<bits/stdc++.h>
using namespace std;
#define maxn 15
int main()
{
    char a[maxn][maxn];
    int m,n;
    cin >> m >> n;
    getchar();
    memset(a,'.',sizeof(a));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> a[i][j];
        }

    }
    int ans=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]=='W')
            {
                if(a[i][j-1]=='P')
                {
                    a[i][j-1]='.';
                    ans++;
                    continue;

                }
                if(a[i-1][j]=='P')
                {
                    a[i-1][j]='.';
                    ans++;
                    continue;

                }
                if(a[i+1][j]=='P')
                {
                    a[i+1][j]='.';
                    ans++;
                    continue;

                }

                if(a[i][j+1]=='P')
                {
                    a[i][j+1]='.';
                    ans++;
                    continue;
                }
            }
        }
    }
    cout << ans << endl;
}
