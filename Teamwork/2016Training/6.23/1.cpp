#include<bits/stdc++.h>
using namespace std;
int main()
{
    int l[155],r[155];
    int m,n;
    cin >> m >> n;
    char a[155][155];
    for(int i=0;i<m;i++)
    {
        cin >> a[i];
    }
    /*for(int i=0;i<m;i++)
    {
        cout << a[i] << endl;
    }*/
    int ans=0;
    int x,y;
    x=y=0;
    int flag;
    for(int i=0;i<m;i++)
    {
        int j;
        if(i%2==0)
        j=0;
        else
        j=n-1;
        flag=0;
    //cout<< i << " " << j <<endl;
        //cout << a[i][j] <<endl;
        for(;j<n&&j>=0;)
        {
            if(a[i][j]=='W')
            {

                ans+=(abs(j-y)+abs(i-x));
                x=i;
                y=j;
            }
            //cout << ans << endl;
            if(i%2==0)
                j++;
            else
                j--;
        }
//cout <<ans <<endl;
    }
    cout << ans << endl;
}
