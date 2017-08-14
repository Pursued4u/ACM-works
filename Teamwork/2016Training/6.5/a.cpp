#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define maxn 100005
map<string,int>mp;
int par[maxn*2];
int sum[maxn*2];
int n;
int Find(int x)
{
    int r=x;
    while(par[r]!=r) r=par[r];
    int i=x,j;
    while(par[i]!=r)
    {
        j=par[i];
        par[i]=r;
        i=j;
    }
    return r;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        scanf("%d",&n);
        int p=1;
        mp.clear();
        for(int i=1;i<=n*2;i++)
        {
        par[i]=i;
        sum[i]=1;
        }
        while(n--)
        {
            char a[25], b[25];
            scanf("%s%s",a,b);
            if(!mp[a])
            mp[a]=p++;
            if(!mp[b])
            mp[b]=p++;
            int fx=Find(mp[a]);
            int fy=Find(mp[b]);
            //cout << fx << " " << fy << endl;
            if(fx!=fy)
            {
                par[fy]=fx;
                sum[fx]+=sum[fy];
            }
            cout << sum[fx] << endl;
        }
    }
}
