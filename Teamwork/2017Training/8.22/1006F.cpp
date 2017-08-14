#include<bits/stdc++.h>
#define rep(i,x,y) for(i=x;i<=y;i++)
#define reps(i,x,y) for(i=x;i>=y;i--)
#define N 110000
#define MP make_pair
#define PB emplace_back
#define INF 0x5ffffffffffffffll
using namespace std;
typedef long long LL;
typedef double DB;
struct node{
	int x,w;LL v;
};
bool operator <(const node &A,const node &B){
	if(A.v!=B.v)return A.v<B.v;
	if(A.x!=B.x)return A.x<B.x;
	return A.w<B.w;
}
bool mark[N];
LL f1[N],f2[N];int p1[N],p2[N];
vector<pair<int,int> > G[N];
priority_queue<node>Q;
int n,m;
void solve(){
	int i,j,k;
	scanf("%d%d",&n,&m);
	rep(i,1,n)mark[i]=0,f1[i]=f2[i]=INF;
	while(m--){
		scanf("%d%d%d",&i,&j,&k);
		G[i].PB(MP(j,k));
	}

	while(!Q.empty())Q.pop();
	scanf("%d",&k);
	while(k--){
		scanf("%d",&j);
		mark[j]=1;
		f1[j]=0;
		p1[j]=j;
		Q.emplace((node){j,j,0});
	}
	LL ans=INF;node t;
	while(!Q.empty()){
		t=Q.top();Q.pop();
		int x=t.x,w=t.w;LL v=t.v;
		bool ok=0;
		if(v==f1[x]&&w==p1[x])ok=1;
		if(v==f2[x]&&w==p2[x])ok=1;
		if(!ok)continue;
		for(k=0;k<G[x].size();k++){
			int y=G[x][k].first;
			if(mark[y]&&y!=w){
				ans=min(ans,v+G[x][k].second);
			}
			if(v+G[x][k].second<f1[y]){
				if(p1[y]!=w){
					p2[y]=p1[y];
					f2[y]=f1[y];
				}
				f1[y]=v+G[x][k].second;
				Q.emplace((node){y,w,f1[y]});
			}
			else{
				if(w==p1[y])continue;
				if(v+G[x][k].second<f2[y]){
					p2[y]=w;
					f2[y]=v+G[x][k].second;
					Q.emplace((node){y,w,f2[y]});
				}
			}
		}
	}

	printf("%lld\n",ans);
	rep(i,1,n)G[i].clear();
}
int main(){
	//freopen("in.txt","r",stdin);
	int T;scanf("%d",&T);
	for(int i=1;i<=T;i++){
		printf("Case #%d: ",i);
		solve();
	}
	return 0;
}
