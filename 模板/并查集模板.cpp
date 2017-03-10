#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 100005
#include<iostream>
#include<algorithm>
using namespace std;
int pre[N];
int num[N];
int n,i;
int Find(int a)
{
    int t=a;
    while(pre[t]!=t)
        t=pre[t];
    int k=a,j;
    while(pre[k]!=t)
    {
        j=pre[k];
        pre[k]=t;
        k=j;
    }
    return t;
}
int main()
{
    int t;
    //cin.sync_with_stdio(false);
    cin >> t;
    int nn=t;
    for(int i=1;i<=t;i++)
    {
        pre[i]=i;
        num[i]=1;
    }
    while(nn--)
    {
        if(nn)
        {
            int m,n;
        cin >> m >> n;
        pre[n]=m;
        }
        else
        {
            int k;
            cin >> k;
            while(k--)
            {
                int ans=0;
                char a[2];
                scanf("%s",a);
                if(a[0]=='Q')
                {
                    int op;
                    cin >> op;
                    //cout << op << endl;
                    for(int i=op;i<=t;i++)
                    {
                        //cout << Find(i) << endl;
                        if(Find(i)==Find(op))
                        {
                            ans+=num[i];
                        }
                    }
                    cout << ans << endl;
                }
                else
                {
                    int op;
                    cin >> op;
                    if(!num[op])
                        num[op]++;
                    else
                        num[op]=0;
                }
            }
        }
    }

    return 0;
}

