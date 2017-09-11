#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int maxn=105;
typedef double Matrix[maxn][maxn];
Matrix A,S;
//n是方程的个数
void gauss(Matrix A,int n)
{
    int i,j,k,r;
    for(int i=0; i<n; i++)
    {
        r=i;
        for( j=i+1; j<n; j++)
            if(fabs(A[j][i])>fabs(A[r][i]))r=j;
        if(r!=i)
            for(j=0; j<=n; j++)swap(A[r][j],A[i][j]);
        for(k=i+1; k<n; k++)
        {
            double f=A[k][i]/A[i][i];
            for(j=i; j<=n; j++)
                A[k][j]-=f*A[i][j];
        }
    }
    for(i=n-1; i>=0; i--)
    {
        for(j=i+1; j<n; j++)
            A[i][n]-=A[j][n]*A[i][j];
        A[i][n]/=A[i][i];
    }
}
int main()
{

    memset(A,0,sizeof(A));
    A[0][0]=95,A[0][1]=36,A[0][2]=11,A[0][3]=5,A[1][0]=6336,A[1][1]=2245,A[1][2]=781;
    A[1][3]=281,A[2][0]=781,A[2][1]=281,A[2][2]=95,A[2][3]=36,A[3][0]=2245,A[3][1]=781;
    A[3][2]=281,A[3][3]=95,A[0][4]=281,A[1][4]=18061,A[2][4]=2245,A[3][4]=6336;
    gauss(A,4);
    for(int i=0; i<4; i++)
    {
        printf("%8.2f\n",A[i][4]);
    }
    return 0;
}
