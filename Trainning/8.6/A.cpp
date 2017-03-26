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

int a[maxn],sa[maxn];

int main(){
    int t,n,m,k;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(a[i]>=m)
                a[i]=1;
            else
                a[i]=0;
            sa[i]=sa[i-1]+a[i];
        }
        ll ans=0;
        for(int i=1;i+k-1<=n;i++){
            int l=i+k-1,r=n,mid,cnt=-1;
            while(l<=r){
                mid=(l+r)>>1;
                if(sa[mid]-sa[i-1]>=k)
                    r=mid-1,cnt=mid;
                else
                    l=mid+1;
            }
            if(cnt>0){
                ans+=n-cnt+1;
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}

