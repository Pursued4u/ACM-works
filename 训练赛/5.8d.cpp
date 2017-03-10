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
using namespace std;
typedef long long ll;
typedef double db;
const int maxn = 2e2 + 5;
const int mod = 1e9 + 7;
vector<string> ve;

int main()
{
    //cin.sync_with_stdio(false);
    //freopen("isharp.in", "r", stdin);
    //freopen("isharp.out", "w", stdout);
    int n;
    char op[10], a[maxn];
    string b;

    ve.clear();
    cin >> n;
    while (n--) {
       // cout << n << endl;
        getchar();
        scanf("%s", op);
        if (op[0] == 'c') {
            scanf("%s", a);
            int len = strlen(a);
            b = "";
            if (a[0] == '/') ve.clear();
            for (int i = 0; i < len; i++) {
                if (a[i] == '/') {
                    if (b != "") ve.push_back(b);
                    b = "";
                }
                else if (a[i] == '.') {
                    if (ve.size()) ve.pop_back();
                    i++;
                    continue;
                }
                else {
                    b += a[i];
                }
            }
            if (b != "") ve.push_back(b);
        }
        else {
            putchar('/');
            int len = ve.size();
            for (int i = 0; i < len; i++) {
                cout << ve[i] << "/";
            }
            puts("");
        }
    }
}
