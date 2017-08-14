#include<bits/stdc++.h>
#define rep(i,a, b) for(int i=(a); i<(b); ++i)
#define inf 0x3f3f3f3f
#define ll long long
#define de(a) cout<<#a<<" => " <<(a)<<endl
const int maxn = 1e6+5;
using namespace std;
int m;
//int a[maxn], b[maxn];
struct node{
	int index;
	int v;
}a[maxn], b[maxn];
bool cmp1(node c, node d){
	return c.v>d.v;
}
bool cmp(node c, node d){
	return c.v<d.v;
}
bool cmp2(node c, node d){
	return c.index < d.index;
}
int main(){
	//freopen("in.txt", "r", stdin);
	scanf("%d", &m);
	rep(i, 1, m+1) scanf("%d", &a[i].v);
	rep(i, 1, m+1) scanf("%d", &b[i].v), b[i].index=i;
	sort(a+1, a+m+1,cmp1);
	sort(b+1, b+m+1, cmp);
	rep(i, 1, m+1){
		a[i].index = b[i].index;
	}
	sort(a+1, a+m+1, cmp2);
	rep(i, 1, m+1){
		if(i!=1) printf(" ");
		printf("%d", a[i].v);
	}
	printf("\n");
	return 0;
}{
