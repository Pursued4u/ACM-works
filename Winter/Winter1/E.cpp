#include<cstdio>
#include<iostream>
using namespace std;
typedef pair<int,int>Pr;
#define maxn 200005
Pr p[maxn];

int main()
{
    int n;
    cin >> n;
    int x = 0;
    for(int i=0;i<n;i++)
    {
        cin >>p[i].first >> p[i].second;
        x = max(x,p[i].first);
    }
    int ans =0;
    for(int i=0;i<n;i++)
    {
        if(p[i].second>=x)
        ans++;
    }
    cout << ans << endl;
    
}