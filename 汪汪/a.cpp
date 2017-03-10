#include<cstdio>
#include<cstring>
using namespace std;
#define maxn 50005
#define lowbit(x) x&-x
int c[maxn];
int vis[maxn];
int n;
void update(int x,int v){
    while(x<=maxn){
        c[x]+=v;
        x+=lowbit(x);
    }
}

int getsum(int x){
    int ans = 0;
    while(x>0){
        ans += c[x];
        x-=lowbit(x);
    }
    return ans;
}

int main()
{
    
    int t;
    int ca =1;
    scanf("%d",&t);
    while(t--){
        memset(c,0,sizeof(c));
        printf("Case %d:\n",ca++);
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&vis[i]);
            update(i+1,vis[i]);
        }
        while(1){
            char s[30];
            scanf("%s",s);
            if(s[0]=='E')
            break;
            else if(s[0]=='A')
            {
                int x, v;
                scanf("%d %d",&x,&v);
                update(x,v);
            }
            else if(s[0]=='S')
            {
                int x, v;
                scanf("%d %d",&x,&v);
                update(x,-v);
            }
            else 
            {
                int l ,r;
                scanf("%d %d ",&l,&r);
                printf("%d\n",getsum(r)-getsum(l-1));
            }
        }
    }

}