#include<cstdio>
#include<iostream>
using namespace std;
int abs(int x)
{
    return x>0?x:-x;
}
int main()
{
    int n,m;
    while(cin >> n >> m)
    {


    int k=abs(n-m);
    int a=n<m?n:m;
    int b=(k*(1+sqrt(5))/2);
    printf("%d\n",a!=b);
    }
}
