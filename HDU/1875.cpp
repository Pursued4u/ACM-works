#include<bits/stdc++.h>
using namespace std;
#define maxn 107
#define db double 
#define eps 1e-8
db res;
struct node{
    int from,to;
    double v;
    node (int u,int v,db x) : from(u),to(v),v(x){}    
    node () {}
}Edge[maxn*maxn];
struct point{
    double x,y;
    point (double a,db b) : x(a),y(b){}
    point () {}
}p[maxn];
int fa[maxn];
int Find(int x){
    return fa[x]==x?x:fa[x]=Find(fa[x]);
}
bool cmp(node a,node b){
    return a.v<b.v;
}
db ffabs(db x){
    return x<eps?-x:x;
}
double dis(point a,point b){
    return sqrt(ffabs(a.x-b.x)*ffabs(a.x-b.x)+ffabs(a.y-b.y)*ffabs(a.y-b.y));
}
int m,n;
bool check(db x){
    return x>(10-eps)&&x<(double)(1000+eps);
}
void init(){
    for(int i=1;i<=m;i++){
        fa[i]=i;
    }
    res = 0;
}
int main(){
    int t; 
    while(cin >> t){
    while(t--){
     cin >> m;
        init();
        for(int i=1;i<=m;i++){
            db x,y;
            scanf("%lf %lf",&x,&y);
            p[i] = point(x,y);
        }
        int k = 0;
        for(int i=1;i<=m;i++){
            for(int j=i+1;j<=m;j++){
                db d = dis(p[i],p[j]);
                if(check(d))
                Edge[k++] = node(i,j,d);
            }
        }
        sort(Edge,Edge+k,cmp);
        for(int i=0;i<k;i++){
            int faa = Find(Edge[i].from);
            int fab = Find(Edge[i].to);
            //cout << faa << fab << endl;
            if(faa!=fab){
                fa[fab] = faa;
                res+=Edge[i].v;
            }
        }
        int flag=0;
        for(int i=1;i<=m;i++){
            if(Find(i)!=Find(1))
            {flag=1; break;}
        }
        if(flag) cout << "oh!" << "\n";
        else printf("%.1f\n",res*100);
    }
}
}