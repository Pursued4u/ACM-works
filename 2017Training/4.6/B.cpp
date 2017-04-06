#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 128;
bool prog[MAXN][MAXN];
int n, m;
int cal(int x, int y, int t) {
	int ret=0;
	for(int i=0; i<n; ++i) {
		if(t==0)ret += (!prog[i][x]&&!prog[i][y])?1:0;
		else if(t==1)ret += (prog[i][x]&&!prog[i][y])?1:0;
		else if(t==2)ret += (!prog[i][x]&&prog[i][y])?1:0;
		else ret += (prog[i][x]&&prog[i][y])?1:0;
	}
	return ret;
}
int main() {
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; ++i) {
		for(int j=0; j<m; ++j) {
			int x;scanf("%d", &x);
			prog[i][j] = x;
		}
	}
	int ans=0x3f3f3f3f, x, y;
	for(int i=0; i<m; ++i) {
		for(int j=i+1; j<m; ++j) {
			int sz = 0;
			for(int k=0; k<4; ++k)
				sz = max(sz, cal(i,j,k));
			if(ans>sz) {
				ans = sz;
				x = i;
				y = j;
			}
		}
	}
	printf("%d\n%d %d\n", ans, x+1, y+1);
	return 0;
}