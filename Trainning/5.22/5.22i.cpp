#include <queue>
#include <cstdio>
using namespace std;
priority_queue <int> que;
int n,i,a,b;
int main()
{

    scanf("%d",&n);

        int ans=0;
        int sum=0;

        for(i=0;i<n;i++)
        {
            scanf("%d %d",&a,&b);
            sum+=b;
            que.push(b);
            if(sum>a)
            {
                sum-=que.top();
                ans++;
                que.pop();
            }
        }
        printf("%d\n",ans);


}
