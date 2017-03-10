#include<cstdio>
#include<iostream>
using namespace std;
#define maxn (int)1e5+5
#define ll long long
const ll inf = 1e9;
int ans[maxn];
int main()
{
    int n;
    cout << "YES" << endl;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        ll x1,y1,x2,y2;
        scanf("%I64d");
        x1+=inf; y1+=inf;
        if(x1&1&&y1&1) cout << 1 << endl;
        else if(x1&1) cout << 2 << endl;
        else if(y1&1) cout << 3 << endl;
        else cout << 4 << endl;
    }
}