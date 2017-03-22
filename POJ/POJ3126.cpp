#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
bool prime[50005];
int dis[20000];
void make_prime()  {
    memset(prime, 1, sizeof(prime));
    prime[0]=false;
    prime[1]=false;
    int N=10000;
    for (int i=2;  i<=N;  i++)
      if (prime[i]) {
        for (int k=i*2; k<=N; k+=i)
            prime[k]=false;
      }
    return;
}
int a,b;
void BFS()
{
    memset(dis,0,sizeof(dis));
    queue<int>que;
    dis[a]=0;
    que.push(a);
    int flag=0;
    while(!que.empty())
    {
        int cur = que.front();
        que.pop();
        if(cur==b)
        {
            flag=1;
            break;
        }
        int mid=cur;
        int k=1;
        for(int i=0;i<4;i++)
        {
            int left = mid%10;
            for(int j=1;j<=9-left;j++)
            {
                int ncur = cur + j*k;
                if(prime[ncur]&&!dis[ncur])
                {
                    dis[ncur]=dis[cur]+1;
                    que.push(ncur);
                }
            }
            if(i==3)
            left--;
            for(int j=1;j<=left;j++)
            {
                int ncur = cur-j*k;
                if(prime[ncur]&&!dis[ncur])
                {
                    dis[ncur]=dis[cur]+1;
                    que.push(ncur);
                }
            }
            mid/=10;
            k*=10;
        }
    }

    if(flag)
    cout << dis[b] << endl;
    else
    cout << "Impossible" <<endl;
}

int main()
{
    make_prime();
    int t;
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        if(a==b)
        {
            cout << "0\n";
            continue;
        }
        BFS();

    }

}