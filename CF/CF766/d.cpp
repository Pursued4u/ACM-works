#include<iostream>
#include<cstdio>
#include<string>
#include<map>
using namespace std;
int fa[200005];
map<string,int>mp;
void init(int N){
    for(int i=0;i<=2*N;i++)
    fa[i] = i;
}
int Find(int x)
{
    return fa[x]==x?x:fa[x]=Find(fa[x]);
}
int main()
{
    int m,n,q;   
    cin >> m >> n >> q;
    init(m);
    for(int i=1;i<=m;i++)
    {
        string s;
        cin >> s;
        mp[s]=i;
    }
    for(int i = 0; i< n; i++){
        int x;
        cin >> x;
        string a,b;
        cin >> a >> b;
        if(x==1)
        {
            if(Find(mp[a])==Find(mp[b]+m))
            cout << "NO" <<endl;
            else
            {
                cout << "YES" << endl;
                fa[Find(mp[a])]=fa[Find(mp[b])];
                fa[Find(mp[a]+m)]=fa[Find(mp[b]+m)];
                
            }

        }
        else
        {
            if(Find(mp[a])==Find(mp[b]))
            cout << "NO" << endl;
            else
            {
                cout << "YES" << endl;
                fa[Find(mp[a])] = fa[Find(mp[b]+m)];
                fa[Find(mp[a]+m)] = fa[Find(mp[b])];
            }
        }
    }
    for(int i=0;i<q;i++){
        string a,b;
        cin >> a >> b;
        if(Find(mp[a])==Find(mp[b]))
        cout << 1 << endl;
        else if(Find(mp[a]+m)==Find(mp[b]))
        cout << 2 <<endl;
        else 
        cout << 3 <<endl;
        
    }
}