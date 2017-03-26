#include<bits/stdc++.h>
#define ll long long
#define maxn 1005
using namespace std;
int main()
{
    int n,i,j;
    int a[maxn];
    char b[maxn];
    char c[maxn];
    scanf("%s",b);
    getchar();
    scanf("%s",c);
    int len=strlen(b);
    for(i=0;i<len;i++)
    {
        b[i]=tolower(b[i]);
        c[i]=tolower(c[i]);
    }
    cout << strcmp(b,c) << endl;
}
