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
int i,m,n;
int a[maxn];
int main()
{
    int a,b,c;
    while(cin >> a >> b >>c){
    if(a==b) cout << "YES" << endl;
    else if(a<b)
    {
        if(c<=0)
        cout << "NO" <<endl;
        else
        {
        if((b-a)%c==0)
            cout << "YES" <<endl;
        else
            cout << "NO" <<endl;
        }

    }
    else
    {
        if(c>=0) cout << "NO" <<endl;
        else
        {
            if((a-b)%-c==0)
                cout << "YES" <<endl;
            else cout << "NO" <<endl;
        }
    }
    }
}
