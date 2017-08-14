#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=1e5+5;
#define FILEIN freopen("in.txt", "r", stdin)
#define FILEOUT freopen("out.txt", "w", stdout)
vector<int> G[maxn];
bool use[maxn];
int deg[maxn];
int n,m;
int slove(){
for (int i = 1; i <= n; ++i) {
  use[i] = false;
    //deg[i] = degree of the vertex i;
}
int ans = 0;
while (true) {
  int mx = -1, u;
    for (int i = 1; i <= n; ++i) {
      if (use[i])
          continue;
        if (deg[i] >= mx) {
          mx = deg[i];
            u = i;
        }
    }
    if (mx <= 0)
      break;
    ++ans;
    use[u] = true;
    for (int i=0;i<G[u].size();i++)
      --deg[G[u][i]];
}
return ans;
}
int main(){
	freopen("in.txt", "r", stdin);
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
		deg[a]++;
		deg[b]++;
	}
	int cnt=slove();
	printf("%d\n",cnt);
}
