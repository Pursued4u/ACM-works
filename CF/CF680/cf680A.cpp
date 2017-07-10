#include<bits/stdc++.h>
using namespace std;
int a[10];
map<int,int>mp;
int sum=0;
int main()
{
    for(int i=0;i<5;i++)
    {
        int x;
        cin >>x;
        sum+=x;
        mp[x]++;
    }
    map<int,int>::iterator it;
    int maxx=0;
    int ans=0;
    for(it=mp.begin();it!=mp.end();it++)
    {
        if(it->second>=2&&it->second<=3)
        ans=it->first * it->second;
        else if(it->second>3)
        ans=it->first*3;
        maxx=max(ans,maxx);
    }
    cout << sum-maxx << endl;
}
