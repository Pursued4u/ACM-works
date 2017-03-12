#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define CLOSEIO ios::sync_with_stdio(false)
#define maxn 100005
ll a[maxn];
ll b[maxn];
int main(){
    CLOSEIO;
    int t;
    cin >> t;
    while(t--){
        ll n;
        ll m;
        cin >> n >> m;
        for(int i = 0; i<n;i++){
            cin >> a[i];
        }
        int vis[maxn];
        //memset(vis,0,sizeof(vis));
        sort(a,a+n);
        int tmp = 1;
        b[0]=a[0];

        for(int i=1;i<n;i++)
        {
            if(a[i]!=a[i-1])
            b[tmp++] = a[i];
        }
        //cout << tmp << endl;
        //for(ll i=0;i<tmp;i++)    b[i]=a[i];
        ll ans = 0;
        //for(int i=0;i<tmp;i++){
          //  cout << b[i] << endl;
        //}//
        
        for(int i=0;b[i]<=m;i++){
            ll x  = *lower_bound(b,b+tmp,m-b[i]);
            //cout << a[i] << " " << x << endl;
            if(x+b[i]==m){
                //if(!vis[x]){
                  //  vis[x]=1;
                    ans++;
                //}
            }
            
            else {continue;
            //memset(vis,0,sizeof(vis));
            }
        }
    cout << ans << endl;
    }
}