#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include<vector>
#include<stack>
#include<climits>
#include<ctime>
#include<queue>
using namespace std;
const int maxn = 1e5+5;
typedef long long ll;
typedef double db;
const int inf = INT_MAX;
const ll INF = LLONG_MAX;
const ll mod = 1e9 + 7;
ll mul(ll x,ll y){return x*y%mod;}
ll q_mul(ll a, ll b){ ll ans = 0;while(b){if(b & 1){ans=(ans+a)%mod;} b>>=1;a=(a+a) % mod;}return ans;}
ll q_pow(ll x , ll y){ll res=1;while(y){if(y&1) res=q_mul(res,x) ; y>>=1 ; x=q_mul(x,x);} return res;}
ll inv(ll x) { return q_pow(x, mod-2); }
int Read() {
    int x = 0, F = 1; char C = getchar();
    while (C < '0' || C > '9') { if (C == '-') F = -F; C = getchar(); }
    while (C >= '0' && C <= '9') { x = x * 10 - '0' + C, C = getchar(); }
    return x * F;
}
const int MAXN = 4e5+1e3;
int sum2, sum3;
int t[MAXN], n;
vector<int> v;
pair<int,int> mingreedy(int l, int r) {
    int x, y;
    x=y=0;
    int i=l;
    while(i<r) {
        if(v[i].cnt==2) {
                ++x;
                ++i;
        }
        else {
            if(v[i+1].cnt==1) {
                    ++x;
                    i+=2;
            }
            else {
                ++y;
                i+=2;
            }
        }
    }
    return make_pair(x,y);
}
pair<int,int> maxgreedy(int l, int r) {
    int x, y;
    x=y=0;
    int i=l;
    while(i<r) {
        if(v[i].cnt==2) {
            if(i+1==r) {
                ++y;
                i+=2;
            }
            else {
                ++x;
                ++i;
            }
        }
        else {
            if(v[i+1].cnt==1) {
                if(v[i+2].cnt==2) {
                    ++x;
                    i+=2;
                }
                else {
                    ++y;
                    i+=3;
                }
            }
            else {
                ++y;
                i+=2;
            }
        }
    }
    return make_pair(x,y);
}
int subsolve(int l, int r) {
    while(l<r&&v[l]==1) {
        if(l+1<r) {
            if(v[l+1]==2) {
                sum3++;
                l+=2;
            }
            else break;
        }
        else return 2;
    }
    while(r>l&&v[r-1]==1) {
        if(r-1>l) {
            if(v[r-2]==2) {
                sum3++;
                r-=2;
            }
            else break;
        }
        else return 2;
    }
    if(l==r) return 0;
    if(r-l==3&&v[l==1&&v[l+1]==1&&v[l+2]==1) {
        ++sum3;
        return 0;
    }
    if(r-l>1&&v[l]==1&&v[l+1]==1) {
        ++l;
        v[l].cnt = 2;
    }
    if(r-l>2&&v[r-1]==1&&v[r-2]==1) {
        --r;
        v[r-1].cnt = 2;
    }
    auto p = mingreedy(l,r);
    auto q = maxgreedy(l,r);
    if(p!=q) return 1;
    sum2 += p.first;
    sum3 += p.second;
    return 0;
}
int solve() {
    v.clear();
    for(int i=0; i<n; ) {
        int j=i+1;
        while(j<n&&t[j]-t[j-1]<=1000)
            ++j;
        if(j-i>3) return 2;
        v.push_back(j-i);
        i=j;
    }
    int m=v.size();
    for(int i=0; i<m; ) {
        if(v[i]==3) {
            ++sum3;
            ++i;
            continue;
        }
        int j=i+1;
        while(j<m) {
            if(v[j].cnt==3)
                break;
            if(v[j].cnt==2&&v[j-1].cnt==2)
                break;
            ++j;
        }
        int ret = subsolve(i,j);
        if(ret) return ret;
        i = j;
    }
    return 0;
}
int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
        scanf("%d", t+i);
    sum2 = sum3 = 0;
    int ret = solve();
    if(ret==0) {
        printf("Cars without trailers: %d\n", sum2);
        printf("Cars with trailers: %d\n", sum3);
    }
    else if(ret==1) puts("Ambiguous");
    else puts("Impossible");
    return 0;
}
