int t1[maxn];
int t2[maxn];
int c[maxn];
int Rank[maxn];
int height[maxn];
int sa[maxn];
int r[maxn];
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
