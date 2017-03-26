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
#define PI acos(-1)
using namespace std;
typedef long long ll;
typedef double db;
const int maxn = 1e3 + 5;
const int mod = 1e9 + 7;
const db eps = 1e-9;
db dis(int x1,int y1,int x2,int y2)
{
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}
  int a[maxn];
    int b[maxn];
    db c[maxn][maxn];
int main(){
    //cin.sync_with_stdio(false);
    //freopen("tt.txt", "r", stdin);
    //freopen("isharp.out", "w", stdout);

    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);


        for(int i=0;i<n;i++)
        {
            scanf("%d %d",&a[i],&b[i]);
        }
        if(n!=4)
        {
            cout << "NO" <<endl;
            continue;
        }
        db minn=mod;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                c[i][j]=dis(a[i],b[i],a[j],b[j]);
                minn=min(minn,c[i][j]);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(c[i][j]==minn)
                ans++;
            }
        }
        if(ans==n)
        cout << "YES" << endl;
        else
        cout << "NO" <<endl;

    }

    return 0;

}
