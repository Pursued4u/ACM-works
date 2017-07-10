#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<math.h>
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
        int n;
        cin >> n;
        if(!n){
            int x;
            cin >> x;
            cout << 0 << "\n";
        }
        else {
            for(int i=0;i<=n;i++) {
                scanf("%d",&a[i]);
            }
            int k = 0;
            while(n){
                ans[k] = n*a[k];
                k++;
                n--;

            }
            for(int i=0;i<k;i++){
                if(i!=k-1)
                cout << ans[i] << " ";
                else
                cout << ans[i] << "\n";
            }

        }
    }


}