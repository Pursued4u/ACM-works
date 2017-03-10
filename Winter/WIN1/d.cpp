#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[20];
int vis[20];
int main()
{
    int n;
    cin >> n;
    int ans=0;
    if(n<3)
    {
        cout << "0"  << endl;
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        if(vis[i]) continue;
        for(int j=i+1;j<n;j++)
        {
            if(vis[i]) break;
            if(vis[j]) continue;
            for(int k=j+1;k<n;k++)
            {
                if(vis[i]||vis[j]) break;
                if(vis[k]) continue;
                
                if(a[i]+a[j]>a[k])
                {
                    ans++;
                    vis[i] = vis[j] = vis[k]=1;
                }
            }
        }

    }
    cout << ans << endl;
}
