#include<bits/stdc++.h>
using namespace std;
string mapp[105];
int vis[105];
int tmp,n;
string ans;
int flag=0;
void dfs(int t){
    if(flag==1)
    return;
    if(t==ans.length())
    {
        flag=1;
        return;
    }

    
    for(int i=0;i<n;i++)
    {
        if(vis[i])
        continue;
        for(int j=0;j<mapp[i].length();j++)
        {
            if(mapp[i][j]==ans[t])
            {
                vis[i]=1;
                dfs(t+1);
                vis[i]=0;
            }
        }
    }
    

}
int main()
{

    cin >> ans;
    cin >> n;
    string tmp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<12;j++)
        {
            char x=getchar();
            if(isalpha(x))
            mapp[i]+=x;
        }
    }
    dfs(0);
    if(flag)
    cout << "YES" << endl;
    else
    {
    cout << "NO" <<endl;
    }
}