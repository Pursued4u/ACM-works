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
typedef long long ll;
const int inf = ((1ll<<29)-10);
const ll mod = 1000000007;
map<int ,int>mp;
int a[maxn];
vector<int> ve;
void init()
{
    int cnt=1;
    while(cnt<1e9)
    {
        cnt*=2;
        ve.PB(cnt);
    }
}
int main()
{
    init();
    int n;
    cin >>n;
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++)
    {
        int cnt=1;
        for(int j=0;j<ve.size();j++)
        {
            ans+=mp[ve[j]-a[i]];
        }
        mp[a[i]]++;
    }
    cout << ans << endl;
}
