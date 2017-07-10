#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
using namespace std;
#define ll long long
#define db double
#define maxn 105000

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
    char a[maxn];
    int po=5;
    scanf("%s",a+po);
    while(1)
    {
        int len=strlen(a+po);
        int car=1;
        for(int i=len+po-1;i>=po;i--)
        {
            int cnt=a[i]-'0';
            cnt+=car;
            a[i]=cnt%10+'0';
            car=cnt/10;

            if(cnt<10)
            break;

        }
        if(car)
        {
            while(car!=0)
        {
            a[--po]=car%10+'0';
            car/=10;

        }
        }
        int ans=0;
        for(int i=len+po-1;i>=po;i--)
        {
            ans+=a[i]-'0';
        }
        if(ans%10==0)
        break;

    }
    cout << a+po << endl;


    }
}
