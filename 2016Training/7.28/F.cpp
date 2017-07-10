
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

typedef long long ll;
#define DEBUG(x) cout<< #x << ':' << x << endl
#define FOR(i,s,t) for(int i = (s);i <= (t);i++)
#define FORD(i,s,t) for(int i = (s);i >= (t);i--)
#define REP(i,n) FOR(i,0,n-1)
#define REPD(i,n) FORD(i,n-1,0)
#define PII pair<int,int>
#define PB push_back
#define MP make_pair
#define ft first
#define sd second
#define lowbit(x) (x&(-x))
#define INF (1<<30)

const int maxn = 100005;
char s[maxn];
int sa[maxn],t1[maxn],t2[maxn],c[maxn];
int Rank[maxn],height[maxn];
int vis[maxn];

void getHeight(int n){
    int k = 0;
    for(int i=1;i<=n;i++)Rank[sa[i]] = i;
    for(int i=0;i<n;i++){
        if(k)k--;
        int j = sa[Rank[i]-1];
        while(s[i+k]==s[j+k])k++;
        height[Rank[i]] = k;
    }
}
bool cmp(int *r,int a,int b,int l){
    return (r[a]==r[b] && r[a+l]==r[b+l]);
}
void build_sa(int m,int n){
    int i,*x=t1,*y=t2,k,p;
    for( i=0;i<m;i++)c[i] = 0;
    for( i=0;i<n;i++)c[x[i] = s[i]]++;
    for( i=1;i<m;i++)c[i] += c[i-1];
    for( i=n-1;i>=0;i--)sa[-- c[x[i]]] = i;
    for(k=1,p=0;p<n;m=p,k<<=1){
        p = 0;
        for(i=n-k;i<n;i++)y[p++] = i;
        for(i=0;i<n;i++)if(sa[i]>=k)y[p++] = sa[i]-k;
        for(i=0;i<m;i++)c[i] = 0;
        for(i=0;i<n;i++)c[x[y[i]]]++;
        for(i=1;i<m;i++)c[i] += c[i-1];
        for(i=n-1;i>=0;i--)sa[--c[x[y[i]]]] = y[i];
        swap(x,y);
        p = 1; x[sa[0]] = 0;
        for(i=1;i<n;i++)
            x[sa[i]] = cmp(y,sa[i-1],sa[i],k)?p-1:p++;
    }
    getHeight(n-1);
}

int main(){
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    int T;
    int ca=1;
    cin>>T;
    getchar();
    while(T--){
        char x[maxn];

        scanf("%s%s",x,s);
        int n = strlen(s);
        build_sa(128,n+1);
        int cnt=n;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]==x[0])
                cnt=i;
            vis[i] = cnt;
        }
        ll ans=0;
        /*for(int i=0;i<n;i++)
        {
            cout << vis[i] << " ";
        }*/
        for(int i=1;i<=n;i++)
        {
            ans+=n-max(vis[sa[i]],sa[i]+height[i]);
        }
        printf("Case #%d: ", ca++);
        printf("%lld\n", ans);
    }
    return 0;
}
