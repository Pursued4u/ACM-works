#include<bits/stdc++.h>
#define CLR(x) memset(x,-1,sizeof(x))
using namespace std;
#define maxn 15
int a[20];
int dp[maxn][maxn];
int find(int pos,int pre,int status,bool limit){
    if(pos==-1) return 1;
    if(!limit && dp[pos][status]!=-1) return dp[pos][status];
    int up = limit?a[pos]:9;
    int tmp = 0;
    for(int i=0;i<=up;i++){
        if(pre==6&&i==2) continue;
        if(i==4) continue;
        tmp+=find(pos-1,i,i==6,limit&&i==a[pos]);

    }
    if(!limit) dp[pos][status] = tmp;
    return tmp;
}
int getsum(int x){
    int pos = 0;
    while(x){
        a[pos++] = x%10;
        x/=10;
    }
    return find(pos-1,-1,0,true);
}
int main(){
    int l,r;
    CLR(dp);
    while(~scanf("%d %d",&l,&r)&&l+r)
    {
        cout << getsum(r)-getsum(l-1) << endl;
    }

}