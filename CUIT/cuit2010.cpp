#include<cstdio>
#include<stack>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstring>
#include<string>
#include<map>
#define maxn 1005
#define ll long long
#define db double
using namespace std;
#define  mod 1e9+7
#define inf 2147483647
#define INF 9223372036854775807
#define PI acos(-1)
int m,n;
int str[maxn];
int i;
int gcd(int a,int b)
{
    if(a<b)
    swap(a,b);
    if(b==0)
        return a;
    else
        return gcd(b,a%b);

}
int main()
{
    cin >> n;

        for(i=0;i<n;i++)
        {
            cin >> str[i];
        }
        int temp=str[0];
        for(i=1;i<n;i++)
        {
                temp=gcd(temp,str[i]);
        }
        int k=1;
        for(i=0;i<n;i++)
        {
            str[i]/=temp;
            while(str[i]%2==0)
            str[i]/=2;
            while(str[i]%3==0)
            str[i]/=3;
            if(str[i]!=1)
            {
                k=0;
                break;
            }


        }
        if(k==0)
        cout << "No" <<endl;
        else
        cout << "Yes" <<endl;

    }
