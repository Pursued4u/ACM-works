#include<bits/stdc++.h>
#define FILEIN freopen("in.txt", "r", stdin)
#define FILEOUT freopen("output.txt", "w", stdout)
#define CLOSEIO ios::sync_with_stdio(false)
#define PI acos(-1)
#define eps 1e-8
#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)
#define mem(a,x) memset(a,x,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))

using namespace std;
const int maxn = 2e5+100;
typedef long long LL;
const int inf = ((1LL<<29)-10);
const LL mod = 1000000007;

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
    #ifdef LOCAL
    FILEIN;
    FILEOUT;
    CLOSEIO;
    #endif
    int n,m;


}

