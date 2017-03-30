#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<cstring>
#include<queue>
#include<set>
#include<string>
#include<map>
#define inf 9223372036854775807
#define INF 9e7+5
#define PI acos(-1)
using namespace std;
typedef long long ll;
typedef double db;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
const db eps = 1e-9;
int abs(int x)
{
    return x<0?-x:x;
}

int main(){

    //cin.sync_with_stdio(false);
    //freopen("tt.txt", "r", stdin);
    //freopen("isharp.out", "w", stdout);
    int t;

    cin >> t;
    while (t--) {
        int tp, n, m;
        cin >> tp >> n >> m;
        if(tp == 1)
        {
            if((n%2)&&(m%2))
            cout << "G" << endl;
            else
            cout << "B" <<endl;
        }
        if (tp == 2) {
            if(m==n)
            cout << "G" <<endl;
            else
            cout << "B" <<endl;
        }
        if (tp == 3) {
            if (n < m) swap(n, m);
            if(m==n)
            {
                if((m-1)%3==0)
                cout << "G" << endl;
                else
                cout << "D" << endl;
            }
            else
            {
                if((n%3)==0&&m==n-1)
                    cout << "B" << endl;
                else
                cout << "D" << endl;
            }
        }
        if(tp ==4)
        {
        m--;
        n--;
        int k=abs(n-m);
        int a=n<m?n:m;
        int b=floor(k*(1.0+sqrt(5.0))/2);
        if(a!=b)
        cout << "B" << endl;
        else
        cout << "G" << endl;

        }
    }

    return 0;
}
