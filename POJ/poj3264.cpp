#include<cstdio>
#include<vector>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
#define maxn 
vector<int>ve;
int minn[50005][20];
int maxx[50005][20];
void rmq(){
    int n = ve.size();
    for(int i=0;i<n;i++){
        maxx[i][0] = ve[i];
        minn[i][0] = ve[i];
    }
    for(int j=1;(1<<j)<=n;j++){
        for(int i=0;i+(1<<(j))<=n;i++){
            minn[i][j] = min(minn[i][j-1],minn[i+(1<<(j-1))][j-1]);
            maxx[i][j] = max(maxx[i][j-1],maxx[i+(1<<(j-1))][j-1]);
        }
    }
}
int main()
{
    int m,n;
    cin >> m >> n;
    for(int i=0;i<m;i++) {
        int x;
        scanf("%d",&x);
        ve.push_back(x);
    }
    rmq();
    while(n--){
        int x,y;
        scanf("%d%d",&x,&y);
        x--; y--;
        int tmp = abs(y-x);
        int k = 0;
        while(1<<(k+1)<=tmp+1) k++; 
        cout << max(maxx[x][k],maxx[y-(1<<k)+1][k])-min(minn[x][k],minn[y-(1<<k)+1][k]) << endl;

    }


}