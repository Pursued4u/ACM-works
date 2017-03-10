#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define N 2
#define ll long long
#define mod 10000
#define CLR(x) memset(x,0,sizeof(x));
struct Matrix{
    ll mat[N][N];
};

Matrix operator * (Matrix a, Matrix b){
    Matrix c; CLR(c.mat);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                c.mat[j][i] += (a.mat[j][k]*b.mat[k][i])%mod;
            }
            c.mat[j][i]%=mod;
        }
    }
    return c;
}
Matrix operator ^ (Matrix a, ll b){
    Matrix c;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            c.mat[i][j] = (i==j);
        }
    }
    while(b){
        if(b&1) c = c*a;
        b>>=1;
        a = a*a; 
        }
    return c;
    
}

void init(Matrix &a){    
    a.mat[0][0]=1;
    a.mat[0][1]=1;
    a.mat[1][0]=1;
    a.mat[1][1]=0;
}
int main()
{
    Matrix f;
    while(1){
        ll n;
        cin >> n;
        if(n==-1)
        break;     
           init(f);
        f = f^n;
        cout << f.mat[1][0] << endl;


    }
}