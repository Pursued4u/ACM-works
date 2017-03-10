#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<map>
#include<vector>
#define FILEIN freopen("in.txt", "r", stdin)
#define FILEOUT freopen("output.txt", "w", stdout)
#define CLOSEIO ios::sync_with_stdio(false)
#define PI acos(-1)
#define eps 1e-8
#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)
using namespace std;
const int maxn = 1e2+100;
typedef long long ll;
const int inf = ((1LL<<29)-10);
const ll mod = 1000000007;
string s;
int sum=0;
int sg;
int m,n;
int oid;
int nid;
int p,q;
struct pos
{
    int x,y;
    char po;
    int id;

} rot[maxn];
int vis[maxn][maxn];
string turn(int id)
{
    string k;
    if((id/100))
    {
        k+=id/100+'0';
        k+='0';
        k+='0';
    }
    else if((id/10))
    {
        k+=id/10+'0';
        k+=id%10+'0';
    }
    else
        k+=id+'0';
    return k;

}
char LL(char x,int tt)
{
    tt%=4;

    for(int i=0; i<tt; i++)
    {
        if(x=='E') x='N';
        else if(x=='N') x='W';
        else if(x=='W') x='S';
        else x='E';
    }
    return x;
}


char RR(char x,int tt)
{
    tt%=4;
    for(int i=0; i<tt; i++)
    {
        if(x=='E') x='S';
        else if(x=='S') x='W';
        else if(x=='W') x='N';
        else x='E';
    }
    return x;
}
bool judge(int x,int y)
{

    if(x<=0||x>n||y<=0||y>m)
        return true;
    else
        return false;
}
bool check(int a,int b,int c)
{
    cout << a << " "  << b <<endl;
    a=max(1,a);
    b=min(b,m);
    cout << a << " " << b <<endl;
    for(int i=a+1; i<=b; i++)
        if(vis[c][i])
            return true;
    return false;
}
bool check1(int a,int b,int c)
{
    a=max(1,a);
    b=min(b,n);
    for(int i=a+1; i<=b; i++)
        if(vis[i][c])
            return true;
    return false;
}
void Move(int id,char op,int d)
{
    int kk=0;
    if(op=='F')
    {
        vis[rot[id].x][rot[id].y]=0;
        if(rot[id].po=='E')
        {
            for(int i=max(rot[id].x+1,1); i<=min(rot[id].x+d,n); i++)
            {
                if(vis[i][rot[id].y]==1)
                {
                    for(int j=1; j<=p; j++)
                    {
                        if(rot[j].x==i&&rot[j].y==rot[id].y)
                            kk=j;
                        if(kk)
                        {
                            int qq=id;
                            s+="Robot ";
                            s+=turn(qq);
                            s+=" crashes into robot ";
                            sg=2;
                            s+=turn(kk);
                            return;
                        }
                    }
                }

            }

            rot[id].x+=d;
        }
        else if(rot[id].po=='W')
        {
            for(int i=max(rot[id].x-d,1); i<=min(rot[id].x-1,n); i++)
            {
                if(vis[i][rot[id].y]==1)
                {
                    for(int j=1; j<=p; j++)
                    {
                        if(rot[j].x==i&&rot[j].y==rot[id].y)
                            kk=j;

                    }
                }

            }
            if(kk)
                        {
                            int qq=id;
                            s+="Robot ";
                            s+=turn(qq);
                            s+=" crashes into robot ";
                            sg=2;
                            s+=turn(kk);
                            return;
                        }

            rot[id].x-=d;
        }
        else if(rot[id].po=='N')
        {
            for(int i=max(rot[id].y+1,1); i<=min(rot[id].y+d,m); i++)
            {
                if(vis[rot[id].x][i]==1)
                {
                    for(int j=1; j<=p; j++)
                    {
                        if(rot[j].y==i&&rot[j].x==rot[id].x)
                            kk=j;
                        if(kk)
                        {
                            int qq=id;
                            s+="Robot ";
                            s+=turn(qq);
                            s+=" crashes into robot ";
                            sg=2;
                            s+=turn(kk);
                            return;
                        }

                    }
                }

            }
            rot[id].y+=d;
        }
        else
        {
            for(int i=max(rot[id].y-d,1); i<=min(rot[id].y-1,m); i++)
            {
                if(vis[rot[id].x][i]==1)
                {
                    for(int j=1; j<=p; j++)
                    {
                        if(rot[j].y==i&&rot[j].x==rot[id].x)
                            kk=j;

                    }
                }
            }
            if(kk)
                        {
                            int qq=id;
                            s+="Robot ";
                            s+=turn(qq);
                            s+=" crashes into robot ";
                            sg=2;
                            s+=turn(kk);
                            return;
                        }

            rot[id].y-=d;
        }
    }
    if(judge(rot[id].x,rot[id].y))
    {
        s+="Robot ";
        int qq=id;
        s+=turn(qq);
        s+=" crashes into the wall";
        sg=1;
        return;
    }
    vis[rot[id].x][rot[id].y]=1;
}
int main()
{
    //FILEIN;
    int t;
    cin >> t;
    while(t--)
    {
        sg=0;
        oid=0;
        nid=0;
        s="";
        memset(vis,0,sizeof(vis));
        scanf("%d %d",&n,&m);
        scanf("%d %d",&p,&q);
        for(int i=1; i<=p; i++)
        {
            int a,b;
            char c;
            scanf("%d %d",&a,&b);
            cin >> c;
            rot[i].x=a;
            rot[i].y=b;
            vis[a][b]=1;
            rot[i].po=c;
            rot[i].id=i;
        }
        for(int i=1; i<=q; i++)
        {
            int a;
            char op;
            int d;
            scanf("%d %c %d",&a,&op,&d);
            if(!sg)
            {
                {
                    if(op=='F') Move(a,op,d);
                    else if(op=='L') rot[a].po=LL(rot[a].po,d);
                    else rot[a].po=RR(rot[a].po,d);
                }
            }
        }
        if(!sg)
            s="OK";
        cout << s << endl;
    }
}