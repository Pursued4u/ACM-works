#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
struct group{
    int a,b;
};
bool cmp1(const group &a,const group &b)
{
    return a.b<b.b;
}
group p[200005];
int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> p[i].a >> p[i].b;
    }
    sort(p,p+n,cmp1);
    ll ans=0;
    ans = p[0].a;
    for(int i=1;i<n;i++)
    {
        ans+=p[i].a-(p[i-1].a-p[i-1].b);
    }
    cout << ans << endl;
}