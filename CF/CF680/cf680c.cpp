#include<bits/stdc++.h>
using namespace std;
#define maxn 25;
int prime[20]={2,3,5,7,11,13,16,17,19,23,25,29,31,37,41,43,47,49};
string op[20];
int main()
{
    int n=0;
    for(int i=0;i<20;i++)
    {
        cout << prime[i] << endl;
        fflush(stdout);
        cin >> op[i];
        if(op[i]=="yes")
        n++;
    }
    if(n>1)
    cout << "composite" ;
    else
    cout << "prime" ;

}
