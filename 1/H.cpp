#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include<vector>
#include<stack>
#include<climits>
#include<ctime>
#include<queue>
#define FILEIN freopen("in.txt", "r", stdin)
#define FILEOUT freopen("out.txt", "w", stdout)
#define CLOSEIO ios::sync_with_stdio(false)
#define PI acos(-1)
#define CLR(a) memset(a,0,sizeof(a))
#define MEM(a,x) memset(a,x,sizoef(a))
#define eps 1e-8
#define sf(x) scanf("%d",&x)
#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)
#define lowbit(x) x&(-x)
#define fi first
#define se second
#define rep(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define drep(a,b,c) for(int (a)=(b);(a)>(c);--(a))
#define dbg(x) cout << #x << "=" << x << endl
using namespace std;
const int maxn = 1e5+5;
typedef long long ll;
typedef double db;
const int inf = INT_MAX;
const ll INF = LLONG_MAX;
const ll mod = 1e9 + 7;
map<string,int>m;
int po[2];
int main()
{
    m["Kamen"] =m["Rock"]= m["Pierre"] =m["Koe"]=m["Roccia"] =m["Stein"]= m["Ko"] = m["Sasso"] = m["Guu"] = m["Kamien"] = m["Piedra"] = 1;
    m["Nuzky"] =m["Scissors"]= m["Ciseaux"] = m["Schere"]= m["Olloo"]= m["Ollo"] = m["Forbice"] = m["Choki"] = m["Nozyce"] = m["Tijera"] = 2;
    m["Papir"] =m["Rete"]=m["Paper"]= m["Feuille"] = m["Papier"]= m["Papir"] = m["Carta"] = m["Paa"] = m["Papier"] = m["Papel"] = 3;
    string s;
    string a;
    string p1,p2;
    int k=1;

    while(cin >> a >> p1 >> s >> p2)
    {
        printf("Game #%d:\n",k);
        string x1;
        string x2;
        while(1)
        {
            cin >> x1;
            if(x1[0]=='-')
            {
                k++;
                break;

            }
            if(x1[0]=='.')
            {
                if(po[0]==1)
                    cout << p1 <<": " << po[0] <<" point\n";
                else
                    cout << p1 <<": " << po[0] <<" points\n";
                if(po[1]==1)
                    cout << p2 <<": " << po[1] <<" point\n";
                else
                    cout << p2 <<": " << po[1] <<" points\n";
                if(po[0]==po[1])
                    cout << "TIED GAME\n";
                else if(po[0]>po[1])
                    cout << "WINNER: " << p1 <<"\n" ;
                else
                    cout << "WINNER: " << p2 << "\n";
                return 0;
            }

            cin >>x2;
            //cout << x1 <<" "<< x2 <<endl;
            //cout << "######" << m[x1] << " " << m[x2] << endl;
            if(m[x1]==m[x2])
                continue;
            if((m[x1]==1&&m[x2]==2)||(m[x1]==2&&m[x2]==3)||(m[x1]==3&&m[x2]==1))
                po[0]++;
            if((m[x1]==1&&m[x2]==3)||(m[x1]==3&&m[x2]==2)||(m[x1]==2&&m[x2]==1))
                po[1]++;


        }
        if(po[0]==1)
            cout << p1 <<": " << po[0] <<" point\n" ;
        else
            cout << p1 <<": " << po[0] <<" points\n";
        if(po[1]==1)
            cout << p2 <<": " << po[1] <<" point\n";
        else
            cout << p2 <<": " << po[1] <<" points\n" ;

        if(po[0]==po[1])
            cout << "TIED GAME\n";
        else if(po[0]>po[1])
            cout << "WINNER: " << p1 << "\n";
        else
            cout << "WINNER: " << p2 << "\n";
        //cout <<x1 << x2 << endl;
        CLR(po);
    }

}
