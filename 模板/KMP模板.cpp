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
#define maxn 10005
#define MAXN 1000005
#define ll long long
#define inf 2147483647
#define INF 9223372036854775807

int n[maxn];
void getnext(char *a)
{
    int i=0,j=-1,
    l=strlen(a);
    n[0]=-1;
    while(i<l)
    {
        if(j==-1||a[i]==a[j])
        {
            i++;j++;
            if(a[i]==a[j])
                n[i]=n[j];
            else
                n[i]=j;
        }
        else
            j=n[j];
    }
}
int kmp(char *s,char *a)// a为子串 s为母串
{
    memset(n,0,sizeof(n));
    getnext(a);
    int i=0,j=0,k=0,len=strlen(s),l=strlen(s2);
    while(i<len)
    {
        if(j==-1||s[i]==s2[j])
            i++,j++;
        else
            j=n[j];
        if(j==l)
            k++,j=n[j];
    }
    return k;//返回次数
}
int main()
{
    char a[maxn];
    char b[maxn];
    scanf("%s",a);
    scanf("%s",b);
    cout << kmp(b,a) << endl;
}


