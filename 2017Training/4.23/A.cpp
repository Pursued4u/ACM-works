#include<cstdio>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;

int main(){
    int t;
    cin >>t;
    while(t--){
        int n;
        int  ans=0;
        int ans1=0;
        cin >> n;
        while(n--){
            int x;
            cin >>x;
            if(x==1)
            ans++;
            else if(x==2)
            ans1++;
            else if(x==3){
                ans1++;
                ans++;
            }
            else {
                ans--;
                ans1--;
            }
        }
        if(ans>ans1){
            cout << "Kobayashi" <<endl;
        }
        else if(ans<ans1){
            cout << "Tohru" << endl;
        }
        else cout << "Draw" << endl;
    }

}