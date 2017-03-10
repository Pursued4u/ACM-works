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
#define maxn 100005
#define ll long long
#define inf 2147483647
#define INF 9223372036854775807
#define PI acos(-1)
int i,m,n,k;
char x;
int vis[maxn];
map<int,string>mp;
int main()
{
    cin >> n;
    string s;
    getchar();
    for(i=0;i<n;i++)
    {
        s="";
        cin >>s;
        cin >>m;
        cin >>k;
        vis[m]=k;
        mp[m]=s;




    }
    cin >> m;
    while(m--)
    {
        cin >>i;
        cout <<mp[i] <<" " << vis[i]<<endl;
    }
}
