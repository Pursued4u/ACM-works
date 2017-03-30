#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<math.h>
#include<cstring>
#include<queue>
#include<algorithm>
#define LL long long
const int MAX_N = 1e4+10;
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n==1)
            cout << 7 << endl;
        else if(n==2)
            cout << 27 <<endl;
        else if(n<=10)
            cout << 70 <<endl;
        else if(n==11)
            cout << 270 <<endl;
        else
            cout << 700 <<endl;
    }


            return 0;

}