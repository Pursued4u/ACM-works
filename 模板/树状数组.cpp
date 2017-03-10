#include<cstdio>
#include<iostream>
#include<cmath>
#include<string>
#include<cstring>
#define ll long long
using namespace std;
int c[50005];

int n;

int lowbit(int x)
{
    return x&(-x);
}
void ins(int t,int d)
{
    while(t<=n)
    {
        c[t]+=d;

        t+=lowbit(t);

    }
}
ll getsum(int t)
{
    ll sum=0;
    while(t>0)
    {
        sum+=c[t];
        cout << t << endl;
        t-=lowbit(t);
    }
    return sum;
}
int main()
{
    int t,i,h,k,T;
    cin >> T;
    t=0;
    while(T--)
    {
        memset(c,0,sizeof(c));
        cin >> n;
        for(i=1;i<=n;i++)
        {
            cin >> k;
            ins(i,k);
        }
        string s;
        printf("Case %d:\n",++t);
        cin >> s;
        while(s!="End")
        {
            int x,y;
            cin >> x >> y;
            if(s=="Query")
            printf("%I64d\n",getsum(y)-getsum(x-1));
            else if(s=="Add") ins(x,y);
            else if(s=="Sub") ins(x,(-1)*y);
            cin >> s;
        }
    }

}
