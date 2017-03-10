#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define N 25
#define ll long long
#define mod 1000000009
#define CLR(x) memset(x,0,sizeof(x));
int maxx = 0;
ll m,n,c;
int a[N],b[N];
struct Matrix{
    ll mat[25][25];
};

Matrix operator * (Matrix a, Matrix b){
    Matrix x; CLR(x.mat); 
    for(int i=0;i<maxx;i++){
        for(int j=0;j<maxx;j++){
            for(int k=0;k<maxx;k++){
                x.mat[j][i] = (x.mat[j][i]%mod+(a.mat[j][k]%mod*b.mat[k][i]%mod)%mod)%mod;
            }
            x.mat[j][i]%=mod;
        }
    }
    return x;
}
Matrix operator ^ (Matrix a, ll b){
    Matrix x;
    for(int i=0;i<maxx;i++){
        for(int j=0;j<maxx;j++){
            x.mat[i][j] = (i==j);
        }
    }
    while(b){
        if(b&1) x = x*a;
        b>>=1;
        a = a*a; 
        }
    return x;
    
}

void init(Matrix &x){    
    CLR(x.mat);
    for(int i=0;i<c;i++) x.mat[0][b[i]-1] = 1; 
    for(int i=1;i<maxx;i++) x.mat[i][i-1]=1;
    /*for(int i=0;i<c;i++){
        for(int j=0;j<c;j++){
            cout << x.mat[i][j] << " ";
        }
        cout << endl;
    }*/
}
int main()
{
    Matrix f,e;
    cin >> m >> n >> c;
    for(int i=0;i<m;i++) cin >> a[i];
    maxx = 0;
    for(int i=0;i<c;i++) {cin >> b[i]; maxx = max(maxx,b[i]);}
    if(n<=m){
        cout << a[n-1] << endl; 
        return 0;
    }
    
    for(int i=0;i<maxx;i++) e.mat[i][0] = a[m-1-i]; 
    init(f);
    f = f^(n-m);
    f = f*e;
    cout << f.mat[0][0] << endl;
    