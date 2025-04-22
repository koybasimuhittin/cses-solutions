#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define f1 first
#define s2 second
#define pb push_back
#define mp make_pair
#define int long long
#define fri(a) freopen(a, "r", stdin);
#define fro(a) freopen(a, "w", stdout);
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

int n, m;

int fact(int n) {
    if (n == 0) {
        return 1;
    }

    return (n * fact(n - 1)) % MOD;
}

int pow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }

    return res % MOD;
}

int inverse(int a) { return pow(a, MOD - 2); }

int32_t main() {
    // fri("in.txt");
    // fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    cout << ((fact(n - 1 + m) * inverse(fact(n - 1))) % MOD) *
                inverse(fact(m)) % MOD
         << endl;

    return 0;
}
