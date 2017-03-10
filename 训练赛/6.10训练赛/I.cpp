#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,n;
    scanf("%d:%d",&m,&n);
    if(m<=1)
    {
        cout << "01:10" <<endl;
    }
    else if(m>=1 && m<2)
    {
        if(n<10)
        cout << "01:10" <<endl;
        else
        cout << "02:20" << endl;
    }
    else if(m>=2 && m<3)
    {
        if(n<20)
        cout << "02:20" <<endl;
        else
        cout << "03:30" << endl;
    }
    else if(m>=3 && m<4)
    {
        if(n<30)
        cout << "03:30" <<endl;
        else
        cout << "04:40" << endl;

    }
    else if(m>=4 && m<5)
    {
        if(n<40)
        cout << "04:40" <<endl;
        else
        cout << "05:50" << endl;

    }
    else if(m>=5 && m<6)
    {
        if(n<50)
        cout << "05:50" <<endl;
        else
        cout << "10:01" << endl;
    }
    else if(m>=6 &&m<10)
    {
        cout << "10:01" << endl;
        }
    else if(m>=10 && m<11)
    {
        if(n<1)
        cout << "10:01" <<endl;
        else
        cout << "11:11" << endl;

    }
    else if(m>=11 && m<12)
    {
        if(n<11)
        cout << "11:11" <<endl;
        else
        cout << "12:21" << endl;

    }
    else if(m>=12 && m<13)
    {
        if(n<21)
        cout << "12:21" <<endl;
        else
        cout << "13:31" << endl;
    }
    else if(m>=13 && m<14)
    {
        if(n<31)
        cout << "13:31" <<endl;
        else
        cout << "14:41" << endl;
    }
    else if(m>=14 && m<15)
    {
        if(n<41)
        cout << "14:41" <<endl;
        else
        cout << "15:51" << endl;
    }
    else if(m>=15 && m<16)
    {
        if(n<51)
        cout << "15:51" <<endl;
        else
        cout << "20:02" << endl;
    }
    else if(m>=16&&m<20)
    {
        cout << "20:02" <<endl;
    }
    else if(m>=20 && m<21)
    {
        if(n<2)
        cout << "20:02" <<endl;
        else
        cout << "21:12" << endl;
    }
    else if(m>=21 && m<22)
    {
        if(n<12)
        cout << "21:12" <<endl;
        else
        cout << "22:22" << endl;
    }
    else if(m>=22 && m<23)
    {
        if(n<22)
        cout << "22:22" <<endl;
        else
        cout << "23:32" << endl;
    }
    else if(m=23)
    {
        if(n<32)
        cout << "23:32" <<endl;
        else
        cout << "00:00" << endl;
    }

}
