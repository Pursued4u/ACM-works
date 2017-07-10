#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<math.h>
#include<climits>
#include<cstring>
#include<queue>
#include<algorithm>
const int maxn = 1e4;
using namespace std;
#define ll long long
int ans[maxn];
int a[maxn];
int main()
{
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        if(s[0]=='F')
        {
            int minn = INT_MAX;
            int n;
            cin >>n;
            while(n--){int x; scanf("%d",&x);
            minn = min(x,minn);}
            cout << minn << "\n";
        }
        else{
            int maxx = INT_MIN;
            int n; cin >>n;
            while(n--){
            int x; scanf("%d",&x);
            maxx = max(x,maxx);
            }
            cout << maxx << "\n";

        }
    }


}