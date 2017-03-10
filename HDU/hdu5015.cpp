#include<bits/stdc++.h>
using namespace std;
#define maxn 15
#define mod 10000007
#define ll long long
#define CLR(x) memset(x,0,sizeof(x))
int m,n;
struct Matrix
{
    ll mat[15][15];
};

Matrix operator *(Matrix a,Matrix b){
    Matrix c; CLR(c.mat);
    for(int i=1;i<=m+2;i++){
        for(int j=1;j<=m+2;j++){
            for(int k=1;k<=m+2;k++){
                c.mat[j][i] += (a.mat[j][k]*b.mat[k][i])%mod;
            }
            c.mat[j][i]%=mod;
        }
    }
    return c;
}


Matrix operator ^(Matrix A, int b){
    Matrix c; CLR(c.mat);
    for(int i=1;i<=m+2;i++){
        for(int j=1;j<=m+2;j++){
            c.mat[i][j]=(i==j);
        }
    }
    while(b){
        
        if(b&1) c = c * A;
        b = b/2;
        A= A*A;
       
    }
    return c;
}


ll sum[15];
int main(){

    while(scanf("%d %d",&m,&n)!=EOF){
        Matrix e;CLR(e.mat);
        for(int i=1;i<=m;i++){
            int x; scanf("%d",&x);
            if(i==1) sum[i]=x;
            else sum[i]=sum[i-1]+x;
        }    
        //for(int i=1;i<=m;i++) cout << sum[i] << endl;
        Matrix f; CLR(f.mat);
        if(n==1){
            cout << (sum[m]+233)%mod<< endl;
            continue;
        }
        else{
            e.mat[1][1]=233LL;
            
            for(int i=2;i<=m+1;i++){
                e.mat[i][1]=(sum[i-1]+233)%mod;
            }
          
            e.mat[m+2][1]=3;
           for(int i=1;i<=m+2;i++){
               for(int j=2;j<=m+2;j++){
                   e.mat[i][j]=0;
               }
           }
            //for(int i=1;i<=m+2;i++) cout << e.mat[i][1]<< endl; 
            for(int i=1;i<=m+1;i++){
                f.mat[i][1]=10;
            }
            
            for(int i=1;i<=m+2;i++) f.mat[i][m+2]=1;
            for(int i=2;i<=m+1;i++){
                for(int j=1;j<=i-1;j++){
                    f.mat[i][j+1]=1;
                }
            }
            /*for(int i=1;i<=m+2;i++){
                for(int j=1;j<=m+2;j++){
                    cout << f.mat[i][j] << " ";
                }
                cout << endl;
            }*/
            /*for(int i=1;i<=m+2;i++){
                for(int j=1;j<=m+2;j++){
                    cout << e.mat[i][j] << " ";
                }
                cout << endl;
            }*/
            
            f = f^(n-1);
            
            e = f*e;
        /*for(int i=1;i<=m+2;i++){
                for(int j=1;j<=m+2;j++){
                    cout << e.mat[i][j] << " ";
                }
                cout << endl;
            }
        }*/
        cout << e.mat[m+1][1] << endl;

        }

    }
}
