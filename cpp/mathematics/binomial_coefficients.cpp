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

int t, a, b;
int fact[N];

int pow(int a, int b) {
    if (b == 0) return 1;

    int x = pow(a, b / 2);

    if (b % 2) {
        return (((x * x) % MOD) * a) % MOD;
    } else {
        return ((x * x) % MOD);
    }
}

int inverse(int a) { return pow(a, MOD - 2); }

int32_t main() {
    // fri("in.txt");
    // fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fact[0] = 1;

    for (int i = 1; i < N; i++) {
        fact[i] = i * fact[i - 1];
        fact[i] %= MOD;
    }

    cin >> t;

    while (t--) {
        cin >> a >> b;

        cout << ((fact[a] * inverse(fact[b]) % MOD) * inverse(fact[a - b])) %
                    MOD
             << endl;
    }

    return 0;
}
