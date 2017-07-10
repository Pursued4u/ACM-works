#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<math.h>
#include<cstring>
#include<queue>
#include<algorithm>
const int maxn = 1e4;
using namespace std;
#define ll long long
struct node{
    int from, to;
    ll v;
};
vector<node>ve;
int m,n;
int fa[maxn];
ll ans = 0;
int Find(int x){
    return fa[x]==x?x:fa[x]=Find(fa[x]);
}
bool cmp(node a,node b){
    return a.v < b.v;
}
void init(){
    ve.clear();
    for(int i=0;i<=m;i++) fa[i]=i;
    ans = 0;
}
int main()
{
    int t;
    cin >> t;
    while(t--){
        scanf("%d %d",&m,&n);
        init();
        for(int i=0;i<n;i++){
        int u,v;
        ll x;
        scanf("%d %d %I64d",&u,&v,&x);
        node tmp;
        tmp .from = u;
        tmp .to= v;
        tmp .v = x;
        ve.push_back(tmp);
        }
        sort(ve.begin(),ve.end(),cmp);
        for(int i=0;i<n;i++){

            int faa = Find(ve[i].from);
            int fab = Find(ve[i].to);
            //cout <<faa <<fab << endl;
            if(faa!=fab){
                fa[fab] = faa;
                ans+=ve[i].v;
            }
        }
        cout << ans << "\n";
    }


}