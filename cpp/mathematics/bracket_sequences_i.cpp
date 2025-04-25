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
const int N = 2e5 + 5;

int n;

int fact(int n) {
    if (n == 0) return 1;

    return (n * (fact(n - 1))) % MOD;
}

int pow(int a, int b) {
    if (b == 0) return 1;
    int x = pow(a, b / 2);

    if (b % 2) return (x * x % MOD) * a % MOD;
    return x * x % MOD;
}

int inverse(int a) { return pow(a, MOD - 2); }

int32_t main() {
    // fri("in.txt");
    // fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    if (n & 1) {
        cout << 0 << endl;
        return 0;
    }

    n /= 2;

    cout << ((fact(2 * n) * inverse(fact(n + 1)) % MOD) * inverse(fact(n))) %
                MOD
         << endl;

    return 0;
}
