#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
/*
* ��ȫ����ģ��
* ���cin>>a
* ���a.print();
* ע��������벻���Զ�ȥ��ǰ��0�ģ������ȶ��뵽char���飬ȥ��ǰ��0�����ù��캯����
*/
#define MAXN 9999
#define MAXSIZE 1010
#define DLEN 4
class BigNum
{
private:
    int a[10000]; //���Կ��ƴ�����λ��
    int len;
public:
    BigNum()
    {
        len=1;    //���캯��
        memset(a,0,sizeof(a));
    }
    BigNum(const char*); //��һ���ַ������͵ı���ת��Ϊ����
    BigNum(const BigNum &); //�������캯��
    BigNum &operator=(const BigNum &); //���ظ�ֵ�����������֮����и�ֵ����
    friend istream& operator>>(istream&,BigNum&); //�������������
    friend ostream& operator<<(ostream&,BigNum&); //������������
    BigNum operator+(const BigNum &)const; //���ؼӷ����������������֮����������
    BigNum operator-(const BigNum &)const; //���ؼ������������������֮����������
    BigNum operator*(const BigNum &)const; //���س˷����������������֮����������

    BigNum operator^(const int &)const; //������n�η�����
    int operator%(const int &)const; //������һ��int���͵ı�������ȡģ����
    bool operator>(const BigNum &T)const; //��������һ�������Ĵ�С�Ƚ�
    bool operator>(const int &t)const; //������һ��int���͵ı����Ĵ�С�Ƚ�
    void print(); //�������
};
BigNum::BigNum(const BigNum &T):len(T.len) //�������캯��
{
    int i;
    memset(a,0,sizeof(a));
    for(i=0; i<len; i++)
        a[i]=T.a[i];
}
BigNum & BigNum::operator=(const BigNum &n) //���ظ�ֵ�����������֮�丳ֵ����
{
    int i;
    len=n.len;
    memset(a,0,sizeof(a));
    for(i=0; i<len; i++)
        a[i]=n.a[i];
    return *this;
}
BigNum BigNum::operator+(const BigNum &T)const //��������֮����������
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
BigNum BigNum::operator*(const BigNum &T)const //��������֮������
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
void BigNum::print() //�������
{
    int i;
    printf("%d",a[len-1]);
    for(i=len-2; i>=0; i--)
        printf("%04d",a[i]);
    printf("\n");
}
BigNum f[5005];//��������
int main()
{
    f[0]=1;
    for(int i=1; i<=5001; i++)
        f[i]=f[i-1]*(4*i-2)/(i+1);//������������ʽ
    int n;
    while(scanf("%d",&n)==1)
    {
        if(n==-1)break;
        f[n+1].print();
    }
    return 0;
}
