#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
vector<int>G[105];
int main()
{
    int n;
    cin >> n;
    int num=n*n;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n*n/2;j+=n)
        {
            G[i].push_back(j);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=n*n-i+1;j>n*n/2;j-=n)
        {
            G[i].push_back(j);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<G[i].size();j++)
        {
            if(j!=G[i].size()-1)
            cout << G[i][j] << " ";
            else
            cout << G[i][j] << endl;
        }
    }
    
}