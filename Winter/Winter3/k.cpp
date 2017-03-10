
#include<cstdio>
#include<string>
#include<set>
#include<iostream>
using namespace std;
#define in insert
#define ll long long
const int maxn = 10005;
const int maxm = 10000005; 
set<ll>st;
ll num[maxn];
void init(){
    num[1]=1;
    for(int i=2;i<20;i++) num[i] = num[i-1]*i;
    st.insert(1);

    
}
void dfs(ll x,ll t) 
{
    
    for(int i=t;i<20;i++)
    {
        if(1e18/x<num[i]) return ;
        st.insert(x*num[i]);
        dfs(x*num[i],i);
    }
}

int main()
{
    int n;    
    init();
    dfs(1,2);
    cin >> n;
    while(n--){
        ll x;
        cin >> x;
        if(st.find(x)!=st.end())
        cout << "YES" << endl;
        else
        cout << "NO" << endl;
    }
}