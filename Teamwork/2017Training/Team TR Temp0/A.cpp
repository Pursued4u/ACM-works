#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long LL;

const int maxn = 1e6 + 10;
char s[maxn];
int sa[maxn], t[maxn], t2[maxn], c[maxn], n;

void build_sa(int m) {
	int i, *x = t, *y = t2;
	for (i = 0; i < m; ++i) c[i] = 0;
	for (i = 0; i < n; ++i) c[x[i] = s[i]]++;
	for (i = 1; i < m; ++i) c[i] += c[i - 1];
	for (int i = n - 1; i >= 0; --i) sa[--c[x[i]]] = i;
	for (int k = 1; k <= n; k <<= 1) {
		int p = 0;
		for (i = n - k; i < n; ++i) y[p++] = i;
		for (i = 0; i < n; ++i) if (sa[i] >= k) y[p++] = sa[i] - k;
		for (i = 0; i < m; ++i) c[i] = 0;
		for (i = 0; i < n; ++i) c[x[y[i]]]++;
		for (i = 1; i < m; ++i) c[i] += c[i - 1];
		for (i = n - 1; i >= 0; --i) sa[--c[x[y[i]]]] = y[i];
		swap(x, y);
		p = 1; x[sa[0]] = 0;
		for (i = 1; i < n; ++i)
			x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1 : p++;
		if (p >= n) break;
		m = p;
	}
}

int rk[maxn], height[maxn];
void getheight() {
	int i, j, k = 0;
	for (i = 0; i < n; ++i) rk[sa[i]] = i;
	for (i = 0; i < n; ++i) {
		if (k) k--;
		int j = sa[rk[i] - 1];
		while (s[i + k] == s[j + k]) k++;
		height[rk[i]] = k;
	}
}

int q[100010];

int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	int T, k;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &k);
		scanf("%s", s);
		n = strlen(s);
		build_sa(300);
		getheight();

		//for (int i = 1; i <= n - 1; ++ i) printf("%d%c", height[i], " \n"[i == n - 1]);
		for (int i = 1; i < n; ++i) cout << height[i] << " "; cout << endl;
		LL ans = 0;
		int back = 0, front = 1;
		height[0] = 0;
		for (int i = 0; i < k - 1; ++ i) {
			//while (front <= back && height[i] < height[q[front]]) ++ front;
			while (front <= back && height[i] < height[q[back]]) -- back;
			q[++ back] = i;
			//for (int j = front; j <= back; ++ j) printf("%d%c", j, " \n"[j == back]);
		}

		for (int i = 0; i + k - 2 <= n - 1; ++ i) {
			while (front <= back && height[i + k - 2] < height[q[back]]) -- back;
			q[++ back] = i + k - 2;
			while (front <= back && q[back] - q[front] + 1 >= k) ++ front;
			int minv = height[q[front]];
			cout << i << " " << minv << endl;
			if (!minv) continue;
			if (height[i - 1] >= minv || height[i + k - 1] >= minv) continue;
			ans += minv - max(height[i - 1], height[i + k - 1]);


		}
		printf("%lld\n", ans);
	}
	return 0;
}
