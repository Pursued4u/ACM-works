#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const double eps = 1e-8;
int n;
struct point {
	int x, y, id;
	point(int x, int y):x(x), y(y){}
	point(){}
	point operator-(const point &t) const {
		return point(x-t.x, y-t.y);
	}
	void in(int i) {
		scanf("%d%d", &x, &y);
		id = i;
	}
}p[3003];
point cp;

bool cmp(const point &a, const point &b) { //¼«½ÇÐò
	double t = a.x*b.y-a.y*b.x;
	return t > 0 || (t==0 && a.x*a.x+a.y*a.y> b.x*b.x+b.y*b.y);
}
int main() {
	int i, j, cas;
	scanf("%d", &cas);
	while(cas--) {
		scanf("%d", &n);
		p[0].in(0);
		for(i = 1; i < n; i++) {
			p[i].in(i);
			if(p[0].x > p[i].x || (p[0].x == p[i].x && p[0].y > p[i].y) )
				swap(p[0], p[i]);
		}
		for(i = n-1; i >= 0; i--) {
                int id = p[i].id;
			p[i] = p[i]-p[0];
			p[i].id = id;
		}
		sort(p+1, p+n, cmp);
		for(i = 1; i < n && p[1].x*p[i].y-p[1].y*p[i].x== 0; i++);
		j = i;
		for(i--;i >= 1; i--)printf("%d ", p[i].id);
		for(i = j; i < n; i++)
			printf("%d ", p[i].id);
		printf("%d\n", p[0].id);
	}
	return 0;
}
