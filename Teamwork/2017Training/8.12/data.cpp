#include<cstdio>

int main() {
	int t=5;
	freopen("in.txt", "w", stdout);
	int n=4e4, k=89;
	while(t--) {
		printf("%d %d\n", n, k);
		for(int i=0; i<n; ++i)
			printf("%d", i%10);
		puts("");
	}
	return 0;
}
