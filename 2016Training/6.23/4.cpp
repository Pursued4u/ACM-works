#include<bits/stdc++.h>
using namespace std;
int fa[2005];
int main()
{
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> fa[i];
    }
    int t;
    int minn=0;
    for(int i=1;i<=n;i++)
    {
        int ans=0;
        for(int j=i;j<=n&&j!=-1;j=fa[j])
        {
            ans++;
        }
        cout << ans << endl;
        minn=max(ans,minn);
    }
    cout << minn << endl;
}
