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

char b[105][105] = {"Cleveland Cavaliers",
"Golden State Warriors",
"San Antonio Spurs",
"Miami Heat",
"Miami Heat",
"Dallas Mavericks",
"L.A. Lakers",
"L.A. Lakers",
"Boston Celtics",
"San Antonio Spurs",
"Miami Heat",
"San Antonio Spurs",
"Detroit Pistons",
"San Antonio Spurs",
"L.A. Lakers",
"L.A. Lakers",
"L.A. Lakers",
"San Antonio Spurs",
"Chicago Bulls",
"Chicago Bulls",
"Chicago Bulls",
"Houston Rockets",
"Houston Rockets",
"Chicago Bulls",
"Chicago Bulls",
"Chicago Bulls",
"Detroit Pistons",
"Detroit Pistons",
"L.A. Lakers",
"L.A. Lakers",
"Boston Celtics",
"L.A. Lakers",
"Boston Celtics",
"Philadelphia 76ers",
"L.A. Lakers",
"Boston Celtics",
"L.A. Lakers",
"Seattle Sonics",
"Washington Bullets",
"Portland Trail Blazers",
"Boston Celtics",
"Golden State Warriors",
"Boston Celtics",
"New York Knicks",
"L.A. Lakers",
"Milwaukee Bucks",
"New York Knicks",
"Boston Celtics",
"Boston Celtics",
"Philadelphia 76ers",
"Boston Celtics",
"Boston Celtics",
"Boston Celtics",
"Boston Celtics",
"Boston Celtics",
"Boston Celtics",
"Boston Celtics",
"Boston Celtics",
"St. Louis Hawks",
"Boston Celtics",
"Philadelphia Warriors",
"Syracuse Nats",
"Minneapolis Lakers",
"Minneapolis Lakers",
"Minneapolis Lakers",
"Rochester Royals",
"Minneapolis Lakers",
"Minneapolis Lakers",
"Baltimore Bullets",
"Philadelphia Warriors",

};
map<string, int> mp;

int main(){
    //cin.sync_with_stdio(false);
    //freopen("tt.txt", "r", stdin);
    //freopen("isharp.out", "w", stdout);
    for (int i = 0; i < 70; i++) {
        mp[b[i]]++;
    }
    int t, cas = 1;

    cin >> t;
    getchar();
    while (t--) {
        string a; getline(cin, a);
       // cout << a << endl;
        printf("Case #%d: ", cas++);
        cout << mp[a] << endl;
    }

    return 0;
}
