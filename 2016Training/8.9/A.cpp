#include<iostream>
#include<cstdio>
#include<set>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 10000010
int n;//n��
int k;//��ȡ�������Ŀ
int x[MAXN];//n�ѷֱ����Ŀ
int a[MAXN];//��ȡ���
int sg[MAXN];//�ȼ���Nim�е�ʯ����

void solve()
{
    int Max=100;
    sg[0]=0;//�ֵ��Լ���ʣ0öʱ�Ǳذ�̬
    for(int i=1; i<=Max; ++i)
    {
        set<int>s;//�洢��ǰ���ܵ���״̬��sgֵ
        for(int j=1; j<i; ++j)
            for(int k=1;k<i-j;k++)
            s.insert(sg[j]^sg[k]^sg[i-j-k]);//���Էֳ�����
        for(int j=0; j<i; ++j)
            s.insert(sg[j]);//���ֳ����ѣ�ֱ��ȡ
        int cnt=0;//Ѱ�ҵ�ǰ״̬����С�ų�ֵ
        while(s.count(cnt)!=0)//����ֵΪcnt��Ԫ�ظ���
            ++cnt;
        sg[i]=cnt;
        cout<<i<<" "<<sg[i]<<endl;
    }
    /*int res=0;
    for(int i=0; i<n; ++i)
        res^=sg[x[i]];
    if(res)puts("Alice");//���ֱ�ʤ
    else puts("Bob");*/
}

int main()
{
    solve();
    for(int i=1;i<=100;i++)
    {
        cout << i << " "<<sg[i] <<endl;
    }
    return 0;
}
