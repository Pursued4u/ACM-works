#include<cstdio>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>

using namespace std;
#define endl "\n"
int a[10005];

int main(){
    int t;
    cin >>t;

    while(t--){
        int n;
        scanf("%d",&n);
        int flag=0;
        if(n<10||n>13)
        flag=1;
        int maxx =-100000;
        for(int i=0;i<n;i++)
        {
                scanf("%d",&a[i]);
                maxx =max(a[i],maxx);
                if(a[i]<1)
                flag=1;
        }
        sort(a,a+n);
        if(a[0]!=1||a[1]!=1)
        flag=1;
        for(int i=1;i<n-1;i++){
            if(a[i]-a[i-1]>2)
            flag=1;
        }
        if(a[n-1]==maxx&&a[n-2]==maxx)
        flag=1;
        if(flag)
            cout << "No" <<endl;
        else cout << "Yes" <<endl;

    }

}