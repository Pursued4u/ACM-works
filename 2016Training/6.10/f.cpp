#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,n;
    int s[105],r[105],h[105],c[105];
    int minn;
    cin >> m;
    for(int i=1;i<=m;i++)
    {
        cin >> s[i] >> r[i] >> h[i] >> c[i];

    }

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[j]<s[i]&&r[j]<r[i]&&h[j]<h[i])
            c[j]=1001;
        }
    }
    minn=1002;
    int p;
    for(int i=1;i<=m;i++)
    {
        if(c[i]<minn)
        {
            p=i;
            minn=c[i];
        }
    }
    cout << p << endl;
}
