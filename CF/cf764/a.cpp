#include<cstdio>
#include<iostream>
using namespace std;
int vis[10005];
int main()
{
    int n,m,z;
    cin >> n >> m >> z;
    for(int i=0;i<=z;i+=n) vis[i]=1;
    int ans=0;
    for(int i=0;i<=z;i+=m)
    if(vis[i]) ans ++;
    cout << ans-1 << endl;
}