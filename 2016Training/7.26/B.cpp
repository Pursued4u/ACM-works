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
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
const db eps = 1e-9;

int main(){
    //cin.sync_with_stdio(false);
    freopen("tt.txt", "r", stdin);
    //freopen("isharp.out", "w", stdout);
    int a[1000];
    for(int i=0;i<840;i++)
    cin >> a[i];
    int ans=0;
    for(int i=1;i<839;i++)
    {
        if(a[i]==2&&a[i]>a[i+1]&&a[i]>a[i-1])
            ans++;
    }
    cout << ans <<endl;
}
