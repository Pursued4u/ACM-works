#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 100005
#define db double

int m,n,i,j;

int main()
{
    string a;
    while(scanf("%d",&m)!=EOF&&m!=0)
    {


    getchar();
    cin >> a;
    int flag=0;
    string s;
    int n;
    n=a.length()/m;
    int k;
    char b[500][500];
    for(i=0; i<n; i++)
    {
        k=m*i;
        if(i%2==0)
        {
            //cout << k << endl;
            for(j=0; j<m; j++)
            {
                b[i][j]=a[k+j];

            }
        }
        else
        {
            //cout << k << endl;
            for(j=0; j<m; j++)
            {
                b[i][j]=a[k+m-j-1];
            }
        }
    }
    for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
            {
                cout << b[j][i];
            }

        }
        cout << endl;

    }

}
