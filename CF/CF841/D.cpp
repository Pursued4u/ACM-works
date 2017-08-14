#include<bits/stdc++.h>

#define HEAP priority_queue
#define rep(i, n) for(int i = 0, _end_ = (n); i < _end_; ++i)
#define per(i, n) for(int i = (n) - 1; i >= 0 ; --i)
#define forn(i, l, r) for(int i = (l), _end_ = (r); i <= _end_; ++i)
#define nrof(i, r, l) for(int i = (r), _end_ = (l); i >= _end_; --i)
#define FOR(a, b) for(auto (a): (b))
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define X first
#define Y second
#define eps 1e-6
#define pi 3.1415926535897932384626433832795
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(), x.end()

using namespace std;

typedef long long LL;
typedef double flt;
typedef vector<int> vi;
typedef vector<LL> vl;
typedef pair<int,int> pii;
typedef pair<int,LL> pil;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
typedef vector<pil> vil;
typedef vector<pii> vii;
typedef vector<pli> vli;
typedef vector<pll> vll;

const int iinf = 1e9 + 7;
const int oo = 0x3f3f3f3f;
const LL linf = 1ll << 60;
const flt dinf = 1e60;

template <typename T> inline void scf(T &x)
{
	bool f = 0;
	x = 0;
	char c = getchar();
	while(c != '-' && (c < '0' || c > '9')) c = getchar();
	if(c == '-') f = 1, c = getchar();
	while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	if(f) x = -x;
	return;
}

template <typename T1, typename T2> void scf(T1 &x, T2 &y)
{
	scf(x);
	return scf(y);
}

template <typename T1, typename T2, typename T3> void scf(T1 &x, T2 &y, T3 &z)
{
	scf(x);
	scf(y);
	return scf(z);
}

template <typename T1, typename T2, typename T3, typename T4> void scf(T1 &x, T2 &y, T3 &z, T4 &w)
{
	scf(x);
	scf(y);
	scf(z);
	return scf(w);
}

inline char mygetchar()
{
	char c = getchar();
	while(c == ' ' || c == '\n') c = getchar();
	return c;
}

template <typename T> inline bool chkmax(T &x, const T &y)
{
	return y > x ? x = y, 1 : 0;
}

template <typename T> inline bool chkmin(T &x, const T &y)
{
	return y < x ? x = y, 1 : 0;
}

#ifdef King_George
#define DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

//---------------------------------------------------------head----------------------------------------------------

const int maxn = 3e5 + 100;

int n, q;
int l[maxn], r[maxn], a[maxn], cnt[maxn], lst[maxn], tag, nxt[maxn], k[maxn], ans[maxn];

int main()
{
    n = q = 300000;
    int ii = 0;
    forn(x, 1, 1500)
    {
        rep(j, 200) a[++ii] = x;
    }
	int lst_q = 0;
	int B = q / 2;
	forn(i, 1, q)
	{
		ans[i] = iinf;
		int kk;
		if(i <= B) l[i] = rand() % (n - 999) + 1, r[i] = l[i] + 1000, kk = 5;
		else l[i] = 1, r[i] = n, kk = 5;
		k[i] = (r[i] - l[i] + 1) / kk;
		while(k[i] * kk <= r[i] - l[i] + 1) ++k[i];
		if(r[i] - l[i] + 1 <= 1000)
		{
			++tag;
			for(register int &j = l[i]; j <= r[i]; ++j)
			{
				int &x = a[j];
				if(lst[x] != tag) lst[x] = tag, cnt[x] = 1;
				else ++cnt[x];
				if(cnt[x] >= k[i]) chkmin(ans[i], x);
			}
		}
		else
		{
			nxt[lst_q] = i;
			lst_q = i;
		}
	}
	forn(i, 1, n) lst[a[i]] = 0;
	forn(i, 1, n) ++lst[a[i]];
	forn(x, 1, n) if(lst[x] >= 200)
	{
		cnt[0] = 0;
		for(register int i = 1; i <= n; ++i) cnt[i] = cnt[i - 1] + (a[i] == x);
		for(register int i = nxt[0]; i; i = nxt[i]) if(cnt[r[i]] - cnt[l[i] - 1] >= k[i]) chkmin(ans[i], x);
	}
	forn(i, 1, q) printf("%d\n", ans[i] == iinf ? -1 : ans[i]);
	return 0;
}
