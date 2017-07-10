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


int main()
{
    #ifdef LOCAL
    FILEIN;
    FILEOUT;
    CLOSEIO;
    #endif
    int t;
    int ans;
    int sum;
    int k;
    int minn;
    cin >>t;
    while(t--)
    {
        k=0;sum=0;
        ans=0;
        minn=100000;
        int n;
        cin >> n;
        while(n--)
        {
            int x;
            cin >> x;
            sum+=x/2;
            if(x%2)
            {
                k++;
            }
        }
        if(!k)
        cout << sum*2 << endl;
        else
            cout << sum/k*2+1 << endl;

    }


}
