#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int maxn = 100;
int T,n,m,k;
int flag;
set<char>good;
string s;
string mo;
bool pipei(string a)
{
    if(flag)
    {
        if(s.size()!=a.size())
            return false;
    }
    else
    {
        if(s.size()!=a.size()||s.size()!=(a.size()+1))
            return false;
    }
    int p1,p2;
    p1=0;
    p2=0;
    while(p1<a.size()&&p2<s.size())
    {
        if(a[p1]==s[p2])
        {
            p1++;
            p2++;
        }
        else
        {
            if(good.count(a[p1]))
            {
                if(s[p2]=='*')
                {
                    p2++;
                    continue;
                }
                else if(s[p2]=='?')
                {
                    p2++;
                    p1++;
                }
                else return false;
            }
            else
            {
                if(s[p2]!='*')
                    return false;
                else   p1++;
            }
        }
    }
    return true;
}
int main()
{

    cin>>s>>mo;
    cout<<s<<mo;
    flag=1;
    for(int i=0; i<s.size(); i++)
    {
        good.insert(s[i]);
    }
    for(int i=0; i<mo.size(); i++)
    {
        if(mo[i]=='*')
            flag=0;
    }
    scanf("%d",&n);
    string abc;
    for(int j=1; j<=n; j++)
    {
        cin>>abc;
        if (pipei(abc)) puts("YES");
        else puts("NO");
    }
    return 0;
}
