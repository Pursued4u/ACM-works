struct point{
    int x,y;
    point(int _x = 0,int _y = 0){
        x = _x;
        y = _y;
    }
    point operator -(const point &b){
        return point(x-b.x,y-b.y);
    }
    ll operator ^(const point &b){
        return (x*b.y-y*b.x);
    }
    ll operator *(const point &b){
        return (x*b.x+y*b.y);
    }
};
db Dis(point a,point b){
    return (a-b)*(a-b);
}
const int maxn = 1e5+7;
point p[maxn];
int st[maxn],top;
bool cmp(point a,point b){
    int tmp = (a-p[0])^(b-p[0]);
    if(tmp>0) return true;
    else if(!tmp&&Dis(a,p[0])<=Dis(b,p[0])) return true;
    else return false;
}
void Graham(int n){
    point cur;
    int k = 0;
    cur = p[0];
    for(int i=1;i<n;i++){
        if(cur.y>p[i].y||(cur.y==p[i].y&&cur.x>p[i].x)){
            cur = p[i];
            k = i;
        }
    }
    swap(p[k],p[0]);
    sort(p+1,p+n,cmp);
    if(n==1){
        top = 1;
        st[0] = 0;
        return;
    }
    if(n==2){
        top = 2;
        st[0] = 0;
        st[1] = 1;
        return;
    }
    top = 2;
        st[0] = 0;
        st[1] = 1;
    for(int i=2;i<n;i++){
        while(top>1&&((p[st[top-1]]-p[st[top-2]])^(p[i]-p[st[top-2]]))<=0)
            top--;
        st[top++] = i;
    }
}

int Max_trangle_area(point p[],int n){
    int ans =  0;
    point v;
    for(int i=0;i<n;i++){
        int j = (i+1)%n;
        int k = (j+1)%n;
        while(j!=i&&k!=i){
            ans = max(ans,abs((p[j]-p[i])^(p[k]-p[j])));
            while( ((p[i]-p[j])^(p[k+1%n]-p[k])) < 0){
                k = (k+1)%n;
            }
            j = (j+1)%n;
        }
    }
    return ans;
}
ll Max_Dis_Twopoints(point p[],int n){
	ll ans = 0;
	point v;
	int cur = 1;
	for(int i=0;i<n;i++){
		v = p[i]-p[(i+1)%n];
		while((v^(p[(cur+1)%n]-p[cur]))<0)
			cur = (cur+1)%n;
		ans = max(ans,max(Dis(p[i],p[cur]),Dis(p[(i+1)%n],p[(cur+1)%n])));
	}
	return sqrt(ans);
}
