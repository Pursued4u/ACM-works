#include<iostream>
using namespace std;
#define db double 
int main()
{
    db s,vx,vy,h;
    int t;
    cin >> t;
    while(t--){

    cin >> s >> h >> vx >> vy;
    db tmp = s/vx;
    db ans = vy*tmp-10.0*tmp*tmp/2.0;
    if(ans-h>=1e-10)
    cout << "good done!" <<endl;
    else
    cout << "poor Merida!" << endl;
    }
}
