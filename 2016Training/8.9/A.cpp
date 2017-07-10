#include<iostream>
#include<cstdio>
#include<set>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 10000010
int n;//n堆
int k;//可取情况的数目
int x[MAXN];//n堆分别的数目
int a[MAXN];//可取情况
int sg[MAXN];//等价于Nim中的石子数

void solve()
{
    int Max=100;
    sg[0]=0;//轮到自己还剩0枚时是必败态
    for(int i=1; i<=Max; ++i)
    {
        set<int>s;//存储当前所能到达状态的sg值
        for(int j=1; j<i; ++j)
            for(int k=1;k<i-j;k++)
            s.insert(sg[j]^sg[k]^sg[i-j-k]);//可以分成两堆
        for(int j=0; j<i; ++j)
            s.insert(sg[j]);//不分成两堆，直接取
        int cnt=0;//寻找当前状态的最小排斥值
        while(s.count(cnt)!=0)//返回值为cnt的元素个数
            ++cnt;
        sg[i]=cnt;
        cout<<i<<" "<<sg[i]<<endl;
    }
    /*int res=0;
    for(int i=0; i<n; ++i)
        res^=sg[x[i]];
    if(res)puts("Alice");//先手必胜
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
