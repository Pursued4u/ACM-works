#include<bits/stdc++.h>
#define FILEIN freopen("in.txt", "r", stdin)
#define FILEOUT freopen("output.txt", "w", stdout)
#define CLOSEIO ios::sync_with_stdio(false)
#define PI acos(-1)
#define eps 1e-8
#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)
using namespace std;
const int maxn = 2e5+100;
typedef long long LL;
const int inf = ((1LL<<29)-10);
const LL mod = 1000000007;
int a[maxn];
int maxx[maxn];
int n,m;
int LIS(int *arr,int len)
{
    maxx[0]=arr[0];
    int l=1;
    for(int i=1; i<len; i++)
    {
        if(arr[i] > maxx[l-1])
        {
            maxx[l++]=arr[i];
        }
        else
        {
            int pos=lower_bound(maxx,maxx+l,arr[i])-maxx;
            maxx[pos]=arr[i];
        }
    }
    return l;
}
int main()
{

    int t;
    cin >> t;
    int ca=1;
    while(t--)
    {
        int flag=1;
        int p=0;
        int cnt=0;
        cin >> n;
        for(int i=0; i<n; i++)
        {
            int x;
            cin >> x;
            if(!x)
                cnt ++;
            else
            {
                x-=cnt;
                a[p++]=x;
                flag=0;
            }
        }
        int ans=LIS(a,p);
        if(flag)
            ans=0;
        printf("Case #%d: ", ca++);
        cout << ans+cnt << endl;
    }

}
