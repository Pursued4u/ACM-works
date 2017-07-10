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
const int maxn = 5e3 + 35;
const int mod = 1e9 + 7;
const db eps = 1e-9;

ll w[maxn], v[maxn];
ll dp[maxn];

ll maxx(ll a, ll b) {
    return a >= b ? a : b;
}

void solve() {
    int n;
    scanf("%d",&n);
    int tot=n-1;
    memset(dp,0,sizeof(dp));
    for(int i=1;i<n;i++)
    {
        scanf("%I64d",&v[i]);
        w[i]=i-1;
    }
    dp[0]=v[1]*(tot+2);
    for(int i=2;i<n;i++)
            for(int j=w[i];j<=tot;j++)
                dp[j]=max(dp[j-w[i]]+v[i]-v[1],dp[j]);
    cout << dp[tot]-1<< endl;

}
int main(){
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
