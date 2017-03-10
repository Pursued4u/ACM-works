#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<cstring>
#include<queue>
#include<set>
#include<string>
#include<map>
#define inf 9223372036854775807
#define INF 9e7+5
#define PI acos(-1.0)
using namespace std;
typedef long long ll;
typedef double db;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
const db eps = 1e-9;
int cas = 1;
int a[maxn];
int sum[maxn];
int sum1[maxn];
int abs(int x)
{
    return x>=0?x:-x;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int maxx=0;
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
        }
        int p=1;
        for(int i=1; i<n; i++)
        {
            sum[i]=abs(a[i+1]-a[i]);
            if(sum[i]>maxx)
            {
                maxx=sum[i];
                p=i;
            }
            sum1[i]=sum[i];
        }
        sort(sum+1,sum+n);
        ll ans=0;
        for(int i=1; i<=n; i++)
        {
            if(i==1)
            {
                if(sum1[i]==maxx)
                {
                    ans+=sum[n-2];
                }
                else
                {
                    ans+=maxx;
                }
            }
            else if(i==n)
            {
                if(sum1[i-1]==maxx)
                ans+=sum[n-2];
                else
                ans+=maxx;
            }
            else
            {
                if(sum1[i]==maxx||sum1[i-1]==maxx)
                {
                    ans+=max(abs(a[i+1]-a[i-1]),sum[n-2]);
                }
                else
                {
                    ans+=maxx;
                }
            }
            cout << ans << endl;

        }
        cout << ans << endl;

    }
}

