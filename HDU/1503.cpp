#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <complex>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>
using namespace std;
#define maxn 105
#define ll long long
#define inf 9e5+7;
char a[maxn],b[maxn];
int dp[maxn][maxn];
int mark[maxn][maxn];
void PrintLCS(int i,int j)
{
    if(!(i+1) && !(j+1))
    return ;
    if(mark[i][j]==0)
    {
        PrintLCS(i-1,j-1);
        printf("%c",a[i]);
    }
    else if(mark[i][j]==1)//根据回溯的位置进行输出
    {
        PrintLCS(i-1,j);
        printf("%c",a[i]);
    }
    else
    {
        PrintLCS(i,j-1);
        //printf("%c",b[j]);
    }
}
int main()
{
    while(~scanf("%s%s",a,b))
    {
        int i,j;
        int len1=strlen(a);
        int len2=strlen(b);
        memset(dp,0,sizeof(dp));
        memset(mark,-1,sizeof(mark));
         for(i = 0;i<=len1;i++)
    mark[i][0] = 1;
    for(i = 0;i<=len2;i++)
    mark[0][i] = -1;
        for(i=0;i<len1;i++)
        {
            for(j=0;j<len2;j++)
            {
                if(a[i]==b[j])
                {
                    dp[i+1][j+1]=dp[i][j]+1;
                    mark[i][j]=0;
                }
                else if(dp[i+1][j]<=dp[i][j+1])
                {
                    dp[i+1][j+1]=dp[i][j+1];
                    mark[i][j]=1;
                }
                else
                {
                    dp[i+1][j+1]=dp[i+1][j];
                    mark[i][j]=-1;
                }

            }
        }
        /*for(i=0;i<len1;i++)
        {
            for(j=0;j<len2;j++)
            {
                printf("%d ",dp[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        for(i=0;i<len1;i++)
        {
            for(j=0;j<len2;j++)
            {
                printf("%d ",mark[i][j]);
            }
            printf("\n");
        }*/
        PrintLCS(len1-1,len2-1);
        printf("\n");



    }
}

