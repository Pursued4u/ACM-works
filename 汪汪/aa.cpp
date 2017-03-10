#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define maxn 500005
ll c[maxn];
int n;
struct node{
    int x,id;
}a[maxn];
bool cmp(node a, node b){
    return a.x<b.x;
}
int lowbit(int x){
    return x&-x;
}
void update(int x){
    while(x<=n){
        c[x]+=1;
        x+=lowbit(x);
    }
}

ll getsum(int x){
    ll ans = 0;
    while(x>=1){
        ans+=c[x];
        x-=lowbit(x);
    }
    return ans;
}
int main(){
    while(scanf("%d",&n)!=EOF){
        if(!n) break;
        int b[maxn];
        memset(c,0,sizeof(c));
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i].x);
            a[i].id = i;
        }
        sort(a+1,a+1+n,cmp);
        for(int i=1;i<=n;i++){
            b[a[i].id] = i;
        }
        ll ansr = 0;
        for(int i=n;i>=1;i--){
            ansr += getsum(b[i]-1);
            update(b[i]);
        }
        cout << ansr << endl;
    }
}