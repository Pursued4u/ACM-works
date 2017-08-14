#include<bits/stdc++.h>
using namespace std;
#define maxn 1005
int mapp[maxn][maxn];
void getnum(int x1,int y1,int r)
{

    for(int i=x1; i<=x1+r; i++)
        for(int j=y1; j<=y1+r; j++)
                mapp[i][j]=1;
}
int tt(int x1,int y1,int x2,int y2,int x3,int y3)
{
    int xx1=x2-x1;
    int xx2=x3-x1;
    int yy1=y2-y1;
    int yy2=y3-y1;
    return abs(xx1*yy2-xx2*yy1);
}
void circle(int x,int y,int r)
{
    for(int i=x-r;i<=x+r;i++)
        for(int j=y-r;j<=y+r;j++)
            if((x-i)*(x-i)+(y-j)*(y-j)<=r*r)
                mapp[i][j]=1;
        return;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        memset(mapp,0,sizeof(mapp));
        int n;
        cin >> n;
        int ans=0;
        while(n--)
        {

            char op;
            scanf("\n%c",&op);

            if(op=='C')
            {
                int x,y,r;
                cin >> x >> y >> r;
                x+=50;
                y+=50;
                circle(x,y,r);
            }
            else if(op=='S')
            {
                int x,y,r;
                cin >> x >> y >> r;
                getnum(x+50,y+50,r);
            }
            else if(op=='T')
            {
                int x1,x2,x3,y1,y2,y3;
                cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
                x1+=50;x2+=50;x3+=50;y1+=50;y2+=50;y3+=50;
                int minx=min(min(x1,x2),x3);
                int miny=min(min(y1,y2),y3);
                int maxx=max(max(x1,x2),x3);
                int maxy=max(max(y1,y2),y3);
                for(int i=minx; i<=maxx; i++)
                    for(int j=miny; j<=maxy; j++)
                    {
                        int s=tt(x1,y1,x2,y2,x3,y3);
                        int s1=tt(i,j,x1,y1,x2,y2);
                        int s2=tt(i,j,x2,y2,x3,y3);
                        int s3=tt(i,j,x1,y1,x3,y3);
                        if(s==s1+s2+s3)
                            mapp[i][j]=1;
                    }
            }
        }
        for(int i=0;i<=200;i++)
            for(int j=0;j<=200;j++)
            {
                if(mapp[i][j])
                ans++;
            }
            cout << ans << endl;

    }
}
