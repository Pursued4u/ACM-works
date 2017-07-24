#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>

#define dbg(x) cout << #x << "=" << x << endl
using namespace std;
int Read()
{
    int x = 0, F = 1;
    char C = getchar();
    while (C < '0' || C > '9')
    {
        if (C == '-') F = -F;
        C = getchar();
    }
    while (C >= '0' && C <= '9')
    {
        x = x * 10 - '0' + C, C = getchar();
    }
    return x * F;
}
const int MAXN = 3e6+1e3;
const int MAXX = 2e5+1e2;
struct Node
{
    int x;
    Node* pre;
    Node* next;
};
struct Pool
{
    Node e[MAXN], *h;
    Pool() {
        for(int i=0; i<MAXN-1; ++i)
            e[i].next = e+i+1;
        e[MAXN-1].next = nullptr;
        h = e;
    }
    Node *newnode()
    {
        Node *ret=h;
        h=h->next;
        return ret;
    }
}pool;
vector<Node*> v[MAXX];
Node *head, *tail;
int n, l, r, sz;
void init()
{
    head = tail = pool.newnode();
    head->next=head->pre=nullptr;
    head->x = 0;
    v[0].push_back(head);
    sz = 1;
}
void myinsert(Node *p, int x) {
    Node *q = pool.newnode();
    q->x = x;
    q->pre=p;
    q->next=p->next;
    p->next=q;
    v[x].push_back(q);
}
void rebuild() {
    for(int i=0; i<MAXX; ++i)
        v[i].clear();
    Node *p = head;
    int k=0;
    for(; p!=nullptr&&k<r; p=p->next) {
        if(k<r) {
            v[p->x].push_back(p);
        }
        ++k;
    }
    sz = k;
    if(p!=nullptr) {
        tail->next = pool.h;
        pool.h = p;
        tail = p->pre;
        tail->next = nullptr;
    }
}
int ans[MAXN];
int main()
{
    n = Read();
    l = Read();
    r = Read();
    init();
    while(n--) {
        int x, y;
        x = Read();
        y = Read();
        sz += v[x].size();
        for(int i=0; i<v[x].size(); ++i) {
            myinsert(v[x][i], y);
        }
        while(tail->next!=nullptr)
            tail = tail->next;
        if(sz>2e6) rebuild();
    }
    int k=0;
    for(Node* p=head; p!=nullptr; p=p->next) {
        ans[k++] = p->x;
    }
    for(int i=l; i<r; ++i)
        printf("%d%c", ans[i%sz], i==r-1?'\n':' ');
    return 0;
}
