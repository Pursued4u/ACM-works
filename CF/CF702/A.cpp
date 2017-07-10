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
int a[maxn];
int maxx[maxn];
int main()
{
    int n;
    cin >> n;
    int ans=0;
    int maxx=0;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);

            if(a[i]>maxx)
            {
                maxx=a[i];
                cnt++;
            }
            else
            {

                ans=max(ans,cnt);
                cnt=1;
                maxx=a[i];
            }

    }

    cout << max(ans,cnt)<< endl;

}

