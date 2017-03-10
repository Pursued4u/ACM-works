#include<bits/stdc++.h>
#define ll long long
#define maxn 1005
using namespace std;
string a[maxn];
int p[maxn][maxn];
int m,n;
int getnum(string s)
{
    int i;
    for(i=1;i<=m;i++)
    {
        if(a[i]==s)
            break;
    }
    cout << i << endl;
    return i;

}
int main()
{
    int i,j;
    cin >> m >> n;
    for(i=1;i<=m;i++)
    {
        cin >> a[i];
    }
    while(n--)
    {
        string x,y;
        cin >> x >> y;
        int x1,y1;
        x1=getnum(x);
        y1=getnum(y);
        cout << x1 << y1 << endl;
    }
}
