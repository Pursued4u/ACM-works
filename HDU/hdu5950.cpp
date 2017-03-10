#include<bits/stdc++.h>
using namespace std;
#define maxn 7
#define CLR(x) memset(x,0,sizeof(x))
#define ll long long
#define mod 2147493647
struct Matrix{
    ll mat[maxn][maxn];
};
Matrix operator * (Matrix A,Matrix B){
    Matrix c; CLR(c.mat);
    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            for(int k=0;k<7;k++){
                c.mat[j][i] =(c.mat[j][i]+ (A.mat[j][k]*B.mat[k][i])%mod)%mod; 
            }
        }
    }
    return c;
}
Matrix operator ^ (Matrix A, ll b){
    Matrix c;CLR(c.mat);
    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            c.mat[i][j]=(i==j);
        }
    }
    while(b){
        if(b&1) c = A *c;
        b>>=1
        A = A*A;
    }
    return c;
}
void init(Matrix &a){
    CLR(a.mat);
    a.mat[0][0]=a.mat[1][0]=a.mat[2][2]=a.mat[2][6]=a.mat[3][3]=a.mat[3][6]=a.mat[4][4]=a.mat[4][6]=a.mat[5][5]=a.mat[5][6]=a.mat[6][6]=1;
    a.mat[0][1]=a.mat[4][5]=2;
    a.mat[0][2]=1;
    a.mat[0][3]=a.mat[2][3]=a.mat[2][5]=4;
    a.mat[0][4]=a.mat[2][4]=6;
    a.mat[0][5]=4;
    a.mat[0][6]=1;
    a.mat[1][0]=1;
    a.mat[3][4] = a.mat[3][5]=3;
    /*{1,2,1,4,6,4,1};
      {1,0,0,0,0,0,0};
      {0,0,1,4,6,4,1};
      {0,0,0,1,3,3,1};
      {0,0,0,0,1,2,1};
      {0,0,0,0,0,1,1};
      {0,0,0,0,0,0,1};*/
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        ll n,a,b;
        cin >> n >> a >> b;
        Matrix e,f;
        CLR(f.mat);
        f.mat[0][0]=b;f.mat[1][0]=a;f.mat[2][0]=16;f.mat[3][0]=8;f.mat[4][0]=4;f.mat[5][0]=2;f.mat[6][0]=1;
        init(e);
        e = e^(n-2);
        f = e*f;
        cout << f.mat[0][0] %mod << endl;
    }
}