#include<bits/stdc++.h>
using namespace std;
#define CLR(x) memset(x,0,sizeof(x))
#define ll long long
ll mod;
struct Matrix{
    ll mat[5][5];
};

Matrix operator *(Matrix a,Matrix b){
    Matrix c; CLR(c.mat);
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            for(int k=1;k<=3;k++){
                c.mat[j][i]+=(a.mat[j][k]*b.mat[k][i])%mod;
            }
            c.mat[j][i]%=mod;
        }
    }
    return c;
}

Matrix operator ^(Matrix a,ll b){
    Matrix c; CLR(c.mat);
    for(int i=1;i<=3;i++) c.mat[i][i]=1;
    while(b){
        if(b&1) c = c*a;
        b>>=1;
        a = a*a;
    }
    return c;
}
int main(){
    int m,n;
    while(~scanf("%d %d",&m,&n)){
       mod =n; 
       if(m==1){
           cout << 1 %mod<< endl;
           continue;
       }
       else if(m==2){
           cout << 2%mod << endl;
           continue;
       }
       else{
           Matrix e; CLR(e.mat);
           e.mat[1][1]=2;e.mat[3][1]=1;e.mat[2][1]=1;
           Matrix f; CLR(f.mat);
           f.mat[1][1]=f.mat[1][3]=f.mat[2][1]=f.mat[3][3]=1;
           f.mat[1][2]=2;           
           /*for(int i=1;i<=3;i++){
               for(int j=1;j<=3;j++){
                   cout << e.mat[i][j];
               }
               cout << endl;
           }*/
           f = f^(m-2);
           e = f*e;
           /*for(int i=1;i<=3;i++){
               for(int j=1;j<=3;j++){
                   cout << e.mat[i][j];
               }
               cout << endl;
           }*/
           cout << e.mat[1][1]%mod << endl;

       }
    }

}