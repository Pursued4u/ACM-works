#include<cstdio>
#include<cstring>
#include<string>
#include<deque>
#include<iostream>
using namespace std;
int a[400010];
int l,r;
int flag;
int m;
#define N 200005
#define FILEIN freopen("in.txt","r",stdin);
deque<int>dq;
void push(int x){
    if(flag){
        a[++r] = x;
        if(!x)dq.push_back(r);
    }
    else{
        a[--l] = x;
        if(!x)dq.push_front(l);
    }

}
void pop(){
    if(flag){
        if(!a[r]) dq.pop_back();
        r--;
    }
    else{
        if(!a[l])dq.pop_front();
        l++;
    }
}
void reverse(){
    flag^=1;
}
void query(){
    if(dq.empty()){
        if(r<l) cout << "Invalid." << "\n";
        else{
            int tmp  = r-l+1;
            if(tmp&1) cout << 1 << "\n";
            else cout << 0 << "\n";
            
        }
    }
    else{
        if(flag){
            int nl = dq.front();
            int tmp = nl - l;
            if(tmp&1){
                if(nl==r) cout << 1 << "\n";
                else cout << 0 << endl;
            }
            else{
                if(nl==r) cout << 0 << "\n";
                else cout << 1 << "\n";
            }
        }
        else{
            int nr= dq.back();
            int tmp = r - nr;
            if(tmp&1){
                if(nr==l) cout << 1 << "\n";
                else cout << 0 << "\n";
            }
            else{
                if(nr==l) cout << 0 << "\n";
                else cout << "1" << "\n";
            }
        }
    }
}
void init(){
    flag = 0;
    r = N-1;
    l = N;
    while(!dq.empty()) dq.pop_back();
}
int main(){
//FILEIN;
    int t;
    cin >> t;
    int ca = 1;
    while(t--){
        init();
        cin >> m;
        printf("Case #%d:\n",ca++);
        while(m--){
            char s[10];
            scanf("%s",s);
            if(s[0]=='P'){
                if(s[1]=='O') pop();
                else{ int x; scanf("%d",&x); push(x);}
            }
            else if(s[0]=='Q') query();
            else flag^=1;
        }
        
    }
}