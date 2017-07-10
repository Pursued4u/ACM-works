#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int c[50005];
int ans[50005];
int lowbit(int x)
{
    return x&(-x);
}
void add(int x)
{
    while(x<=32005)
    {
        c[x]+=1;
        x+=lowbit(x);
    }
}
int sum(int x)
{
    int ansr=0;
    while(x>=1)
    {
        ansr+=c[x];
        x-=lowbit(x);
    }
    return ansr;
}
int main()
{
    int n;
    scanf("%d",&n);

        memset(c,0,sizeof(c));
        for(int i=1;i<=n;i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            add(x+1);
            int temp;
            temp=sum(x+1);
            ans[temp]++;
        }
        for(int i=1;i<=n;i++)
        {
        cout << ans[i] <<endl;
        }


}
