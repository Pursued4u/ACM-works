#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int m;
    int a[100050];
    int b[100050];
    memset(b, 0, sizeof(b));
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&a[i]);
        b[a[i]]=b[a[i]-1]+1;
    }

    sort(b+1,b+m+1);
    printf("%d\n",m-b[m]);

}
