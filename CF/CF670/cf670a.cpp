#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b,i,m,mina,maxa;
    while(scanf("%d",&n)!=EOF)
    {
    a=n/7;
    b=n%7;
    a*=2;

    if(b<=5)
    {
        if(b<=2)
        {
            mina=a;
            maxa=a+b;
        }
        else
        {
             mina=a;
            maxa=a+2;

        }

    }
    else
    {
        mina=a+b-5;
        maxa=a+2;
    }
    printf("%d %d\n",mina,maxa);



    }
}
