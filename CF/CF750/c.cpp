#include<bits/stdc++.h>
using namespace std;
const int inf = INT_MAX;
int main(){
    int n;
    cin >> n;
    int d,x;
    int pre = 0;
    int tmp;
    int minn,maxx;
    minn = -inf;
    maxx = inf;
    pre = 0;
    for(int i=0;i<n;i++){
        cin >> x >> d;
        if(d==1){
            minn = max(minn,1900-pre);
        }
        else
            maxx = min(maxx,1899-pre);
        pre += x;
    }
    if(maxx == inf)
    cout << "Infinity" << endl;
    else if(minn>maxx)
    cout << "Impossible" << endl;
    else
    cout << maxx+pre << endl;
}