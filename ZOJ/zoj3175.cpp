#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        
        int tmp = sqrt(n);
        ll ans = 0;
        for(int i=1;i<=tmp;i++){
            ans+=n/i;
        }
        ans<<=1;
        ans = ans - n -tmp*tmp;
        cout << ans << endl;
    }
}