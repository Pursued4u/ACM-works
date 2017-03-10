#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
struct group{
    ll a,b,c;
};
bool cmp1(const group &a,const group &b)
{
    return a.c>b.c;
}
group p[200005];
int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        scanf("%lld%lld",&p[i].a,&p[i].b);
        p[i].c= p[i].a-p[i].b;
    }
    sort(p,p+n,cmp1);
    ll ans=0;
    ll tmp=0;
    for(int i=0;i<n;i++)
    {
        if(tmp>=p[i].a)
        tmp-=p[i].b;
        else
        {
            ans+=p[i].a-tmp;
            tmp = p[i].c;
        }
    }
    cout << ans << endl;
}