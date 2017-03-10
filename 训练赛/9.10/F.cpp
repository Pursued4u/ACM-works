#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define N 1000000000
#define inf 1<<29
#define MOD 9973
#define LL long long
using namespace std;
int main()
{
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    int maxn=m/n;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(k%i>maxn)
        {
            ans++;
        }
        maxn=k%i;
    }
    cout << ans <<endl;

}
