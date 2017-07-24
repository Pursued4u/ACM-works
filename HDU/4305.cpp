#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include<vector>
#include<stack>
#include<climits>
#include<ctime>
#include<queue>
#define FILEIN freopen("in.txt", "r", stdin)
#define FILEOUT freopen("out.txt", "w", stdout)
#define CLOSEIO ios::sync_with_stdio(false)
#define PI acos(-1)
#define CLR(a) memset(a,0,sizeof(a))
#define MEM(a,x) memset(a,x,sizeof(a))
#define eps 1e-6
#define sf(x) scanf("%d",&x)
#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)
#define lowbit(x) x&(-x)
#define fi first
#define se second
#define rep(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define drep(a,b,c) for(int (a)=(b);(a)>(c);--(a))
#define dbg(x) cout << #x << "=" << x << endl
using namespace std;
const int maxn = 300+5;
typedef long long ll;
typedef double db;
const int inf = INT_MAX;
const ll INF = LLONG_MAX;
const ll mod = 10007;
int n;
int r;
struct point{
    int x,y;
    point operator - (point a){ return {x-a.x,y-a.y};}
};
point po[maxn];
struct Matrix
{
    int mat[maxn][maxn];
    int getsum(int n)
    {
        int res = 1;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int x = i, y = j;
                while(mat[y][i])
                {
                    int t = mat[x][i]/mat[y][i]%mod;
                    for(int k=0; k<n; k++){
                        mat[x][k] -=mat[y][k]*t;
                        mat[x][k] %=mod;
                    }
                    swap(x,y);
                }
                if(x!=i)
                {
                    for(int k=0; k<n; k++)
                    {
                        swap(mat[x][k],mat[i][k]);
                    }
                    res *=-1;
                }
            }
            if(!mat[i][i]) return -1;
            res*=mat[i][i];
            res%=mod;
        }
        res= ((res%mod)+mod)%mod;
        return res;
    }
};
int dis(point a,point b)
{
    int x = a.x-b.x;
    int y = a.y-b.y;
    return (x*x+y*y);
}
bool eq(db x){
    return x<-eps?0:x>eps?0:1;
}
bool cs(point a,point b){
    return (a.x*b.y-b.x*a.y)==0;
}
bool cs1(point a,point b){
    return (a.x*b.x+a.y*b.y)<0;
}
Matrix operator-(Matrix a,Matrix b)
{
    Matrix c;
    CLR(c.mat);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            c.mat[i][j] =a.mat[i][j]-b.mat[i][j];
        }
    }
    return c;
}
Matrix D,A;
int t;
int main()
{
    scanf("%d",&t);

        while(t--)
        {
            CLR(D.mat);
            CLR(A.mat);
            scanf("%d%d",&n,&r);
            for(int i=0; i<n; i++)
            {
                scanf("%d %d",&po[i].x,&po[i].y);
            }
            for(int i=0; i<n; i++)
            {
                for(int j=i+1; j<n; j++)
                {
                    int flag = 0;
                    if(dis(po[i],po[j])>r*r) continue;
                    for(int k=0;k<n;k++){
                        if(k==i||k==j) continue;
                        if(cs(po[i]-po[j],po[i]-po[k])&&cs1(po[i]-po[k],po[j]-po[k])){
                           flag = 1;
                           break;
                        }
                    }
                    if(!flag){
                        A.mat[i][j] = 1;
                        A.mat[j][i] = 1;

                    }
                }
            }
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    if(A.mat[i][j]){
                        D.mat[i][i] ++;
                        D.mat[j][j] ++;
                    }
                }
            }
            Matrix c = D-A;
            int ans = c.getsum(n-1);
            printf("%d\n",ans);
        }

    return 0;
}
