#include<cstdio>
#include<iostream>
#include<cstring>
#define ll long long
#define maxn 100005
using namespace std;

int c[maxn];
int a[maxn];
int n;
int lowbit(int x){
    return x&-x;
}

void update(int x,int v){
    while(x<=maxn)
    {
        c[x]+=v;
        x+=lowbit(x);
    }
}

int getsum(int x){
    int ans = 0;
    while(x){
        ans += c[x];
        x-=lowbit(x);
    }
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        memset(c,0,sizeof(c));
        int n;
        cin >> n;
        for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
        int mina[maxn];
        int minb[maxn];
        int maxa[maxn];
        int maxb[maxn];
        for(int i = 0;i<n;i++){
            update(a[i],1);
            mina[i] = getsum(a[i]-1);
            maxa[i] = i+1-getsum(a[i]);
        }
        memset(c,0,sizeof(c));
        for(int i = n-1;i>=0;i--){
            update(a[i],1);
            minb[i] = getsum(a[i]-1);
            maxb[i] = n-i-getsum(a[i]);
        }
        ll ans = 0;
        for(int i=0;i<n;i++){
            ans += mina[i]*maxb[i]+maxa[i]*minb[i];   
        }
        cout << ans << endl;
    }

}