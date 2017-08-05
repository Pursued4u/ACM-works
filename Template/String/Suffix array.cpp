int t1[maxn];
int t2[maxn];
int c[maxn];
int Rank[maxn];
int height[maxn];
int sa[maxn];
int r[maxn];
int RMQ[maxn];
int mm[maxn];
int dp[maxn][20];

bool cmp(int *r,int a,int b,int l){
    return r[a]==r[b]&&r[a+l] == r[b+l];
}
void da(int str[],int sa[],int Rank[],int height[],int n,int m){
    n++;
    int i,j,p,*x=t1,*y=t2;
    for(int i=0;i<m;i++) c[i] = 0;
    for(int i = 0;i <n;i++) c[x[i] = str[i]]++;
    for(int i = 1;i < m; i++) c[i]+=c[i-1];
    for(int i=n-1;i>=0;i--) sa[--c[x[i]]] = i;
    for(int j=1;j<=n;j<<=1){
        p = 0;
        for(int i = n-j;i<n;i++) y[p++] = i;
        for(int i=0;i<n;i++) if(sa[i]>=j) y[p++] = sa[i] - j;
        for(int i=0;i<m;i++) c[i] = 0;
        for(int i=0;i<n;i++) c[x[y[i]]]++;
        for(int i=1;i<m;i++) c[i]+=c[i-1];
        for(int i=n-1;i>=0;i--) sa[--c[x[y[i]]]] = y[i];
        swap(x,y);
        p = 1; x[sa[0]] = 0;
        for(int i=1;i<n;i++){
            x[sa[i]] = cmp(y,sa[i-1],sa[i],j)?p-1:p++;
        }
        if(p>=n) break;
        m = p;
    }
    int k = 0;
    n--;
    for(int i=0;i<=n;i++) Rank[sa[i]] = i;
    for(int i=0;i<n;i++){
        if(k)k--;
        j = sa[Rank[i]-1];
        while(str[i+k]==str[j+k])k++;
        height[Rank[i]] = k;
    }
}
void init_RMQ(int n){
	int m = floor(log(n+0.0)/log(2.0));
	for(int i=1;i<=n;i++) dp[i][0] = height[i];
	for(int i=1;i<=m;i++){
		for(int j=n;j;j--){
			dp[j][i] = dp[j][i-1];
			if(j+(1<<(i-1))<=n)
				dp[j][i] = min(dp[j][i],dp[j+(1<<(i-1))][i-1]);
		}
	}
}
int query_RMQ(int l,int r){
	int a = Rank[l];
	int b = Rank[r];
	if(a>b) swap(a,b);
	a++;
	int m = floor(log(b-a+1.0)/log(2.0));
	return min(dp[a][m],dp[b-(1<<m)+1][m]);
}
