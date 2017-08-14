#include<stdio.h>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<iostream>
using namespace std;
const int maxn=1e5+5;

int main(){
	freopen("in.txt", "w", stdout);
	cout << 100 << endl;
	for(int i=0;i<100;i++){
	int n = 10;
	cout << i << " " << n << ' ';
	srand(time(0));
	int m = (rand() %n) + 1;
	cout << m << endl;
	bool vis[505][505] = {0};
	for (int i = 1; i <= m; i++) {
		int u = rand() % n + 1, v = rand() % n + 1;
		if (vis[u][v] || u == v) {
			i--;
			continue;
		}
		vis[u][v] = vis[v][u] = 1;
		cout << u << ' ' << v << endl;
	}
}
}
