#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
int a[maxn];

int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    cin >> a[i];
    sort(a+1,a+n+1);
    if(n%2)
    cout << a[n/2+1] << endl; 
    else
    cout <<  a[n/2] << endl;
    
}