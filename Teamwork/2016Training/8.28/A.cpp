


void solve() {
    ll n;

    while (cin >> n) {
        int len = 0, a[15];
        ll tmp = n;
        while (tmp) {
            a[len++] = tmp%10;
            tmp /= 10;
        }
        sort(a, a+len);
        ll ans = 0;
        for (int i = len-1; i >= 0; i--) {
            ans = ans*10 + a[i];
        }
        ll pri = 1;
        while (pri < ans&&pri <= mod) {
            cout << pri << ' ';
            pri *= 2;
        }
        cout << endl;
    }
}

int main()
{
    solve();

}
