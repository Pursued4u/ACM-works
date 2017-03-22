#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n;
    ll ans = 0;
    cin >> n;
    ans +=n/10;
    ans +=n/7;
    if(n%10>=7)
    ans++;
    int k = n;
    int tmp=n/70;
    if(n%70>=7)
    tmp++;
    cout << ans-tmp << " " << n-ans+tmp<< endl;
    
 }
  