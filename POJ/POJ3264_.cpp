#include<cstdio>
#include<iostream>
#include<cmath>
#include<vector>
#include<climits>
using namespace std;
#define maxn (int)2e5+5
int m,n;
int minn[maxn];
int maxx[maxn];
int num;
void init(){
    num = 1;
    while(num < m) num = num << 1;
    for(int i=0;i<2*num-1;i++){
        maxx[i] = 0;
    } 

}
void update(int k,int x){
    k+=num-1;  maxx[k] = x;
    while(k>0){
        k = (k-1)/2;
        maxx[k] = maxx[k*2+1]+maxx[k*2+2];

    }
}
int query(int a,int b,int l,int r,int k){
    if(r<=a || l>=b) return 0; 
    if(l>=a && r<=b) return maxx[k];
    else{
        int vl = query(a,b,l,(l+r)/2,k*2+1);
        int vr = query(a,b,(l+r)/2,r,k*2+2);
        return vl+vr;
    }
}


int main()
{
    
    cin >> m >> n;
    init();
    for(int i=0;i<m;i++)
    {
        int x;
        scanf("%d",&x);
        update(i,x);
    }
    while(n--){
        int x,y;
        scanf("%d%d",&x,&y);
        cout <<  query(x-1,y,0,num,0) << endl;
    }
}