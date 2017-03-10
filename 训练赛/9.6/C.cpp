#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
/*
* 完全大数模板
* 输出cin>>a
* 输出a.print();
* 注意这个输入不能自动去掉前导0的，可以先读入到char数组，去掉前导0，再用构造函数。
*/
#define MAXN 9999
#define MAXSIZE 1010
#define DLEN 4
class BigNum
{
private:
    int a[10000]; //可以控制大数的位数
    int len;
public:
    BigNum()
    {
        len=1;    //构造函数
        memset(a,0,sizeof(a));
    }
    BigNum(const char*); //将一个字符串类型的变量转化为大数
    BigNum(const BigNum &); //拷贝构造函数
    BigNum &operator=(const BigNum &); //重载赋值运算符，大数之间进行赋值运算
    friend istream& operator>>(istream&,BigNum&); //重载输入运算符
    friend ostream& operator<<(ostream&,BigNum&); //重载输出运算符
    BigNum operator+(const BigNum &)const; //重载加法运算符，两个大数之间的相加运算
    BigNum operator-(const BigNum &)const; //重载减法运算符，两个大数之间的相减运算
    BigNum operator*(const BigNum &)const; //重载乘法运算符，两个大数之间的相乘运算

    BigNum operator^(const int &)const; //大数的n次方运算
    int operator%(const int &)const; //大数对一个int类型的变量进行取模运算
    bool operator>(const BigNum &T)const; //大数和另一个大数的大小比较
    bool operator>(const int &t)const; //大数和一个int类型的变量的大小比较
    void print(); //输出大数
};
BigNum::BigNum(const BigNum &T):len(T.len) //拷贝构造函数
{
    int i;
    memset(a,0,sizeof(a));
    for(i=0; i<len; i++)
        a[i]=T.a[i];
}
BigNum & BigNum::operator=(const BigNum &n) //重载赋值运算符，大数之间赋值运算
{
    int i;
    len=n.len;
    memset(a,0,sizeof(a));
    for(i=0; i<len; i++)
        a[i]=n.a[i];
    return *this;
}
BigNum BigNum::operator+(const BigNum &T)const //两个大数之间的相加运算
{
    BigNum t(*this);
    int i,big;
    big=T.len>len?T.len:len;
    for(i=0; i<big; i++)
    {
        t.a[i]+=T.a[i];
        if(t.a[i]>MAXN)
        {
            t.a[i+1]++;
            t.a[i]-=MAXN+1;
        }
    }
    if(t.a[big]!=0)
        t.len=big+1;
    else t.len=big;
    return t;
}
BigNum BigNum::operator*(const BigNum &T)const //两个大数之间的相乘
{
    BigNum ret;
    int i,j,up;
    int temp,temp1;
    for(i=0; i<len; i++)
    {
        up=0;
        for(j=0; j<T.len; j++)
        {
            temp=a[i]*T.a[j]+ret.a[i+j]+up;
            if(temp>MAXN)
            {
                temp1=temp-temp/(MAXN+1)*(MAXN+1);
                up=temp/(MAXN+1);
                ret.a[i+j]=temp1;
            }
            else
            {
                up=0;
                ret.a[i+j]=temp;
            }
        }
        if(up!=0)
            ret.a[i+j]=up;
    }
    ret.len=i+j;
    while(ret.a[ret.len-1]==0 && ret.len>1)ret.len--;
    return ret;
}
void BigNum::print() //输出大数
{
    int i;
    printf("%d",a[len-1]);
    for(i=len-2; i>=0; i--)
        printf("%04d",a[i]);
    printf("\n");
}
BigNum f[5005];//卡特兰数
int main()
{
    f[0]=1;
    for(int i=1; i<=5001; i++)
        f[i]=f[i-1]*(4*i-2)/(i+1);//卡特兰数递推式
    int n;
    while(scanf("%d",&n)==1)
    {
        if(n==-1)break;
        f[n+1].print();
    }
    return 0;
}
