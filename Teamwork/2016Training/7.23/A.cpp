#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<cstring>
#include<queue>
#include<set>
#include<string>
#include<map>
#define inf 9223372036854775807
#define INF 9e7+5
#define PI acos(-1)
using namespace std;
typedef long long ll;
typedef double db;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
const db eps = 1e-9;
#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)

int n, xx, yy, f;
db a[210];

int abss(int x)
{
    return x>=0?x:-x;
}
int main(){
    //char a[] = "lrb"
    //cin.sync_with_stdio(false);
    //freopen("tt.txt", "r", stdin);
    //freopen("tt.txt", "w", stdout);
    int ca=1;
    while(~scanf("%d%d%d%d", &n, &xx, &yy, &f) && (n||xx||yy||f))
    {
        for(int i=0; i<n; i++)
        {
            int x, y;
            db jiao;
            scanf("%d%d", &x, &y);
            x -= xx;
            y -= yy;
            if(!x)
            {
                jiao = 90;
                a[i] = jiao;
            }
            else
            {
                a[i] = atan(1.0*abss(y)/abss(x))/PI*180.0;
                if(x<0)
                {
                    if(y>=0)
                    a[i]=180-a[i];
                    if(y<0)
                    a[i]+=180;
                }
                else
                {
                    if(y<0)
                       a[i]=360-a[i];
                }

            }
        }
        db ff = f;
        sort(a, a+n);

        for(int i=n; i<2*n; i++)
            a[i] = a[i-n]+360;
        int sum = 0;
        int minn=INF;
        for(int i=0; i<n; i++)
        {
            int cnt=i;
            int ans=1;
            for(int j=i+1;j<i+n;)
            {
                //cout <<a[j] << ' '<< a[cnt ]<< ' '<< ff<< endl;

                if(a[j]-a[cnt]>ff)
                {
                    cnt=j;
                    ans++;

                }
                else if(a[j]-a[cnt]==ff)
                {
                    cnt=j+1;
                    ans++;
                    j++;
                }
                j++;
            }
            minn=min(ans,minn);
        }

        cout << "Case "<< ca++ <<":";
        cout <<" " <<minn <<endl;
    }
    return 0;
}
