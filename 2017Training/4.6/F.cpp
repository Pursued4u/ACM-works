#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
#define ll long long

ll getsum(ll x){
    ll num = 2;
    while(x>=num){
        x-=x/num;
        num++;
    }
    return x;
}
int main(){
    ll l,r;
    cin >> l >> r;
    cout <<getsum(r)-getsum(l-1) <<endl;
}