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

string s;
int cnt[30];

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

    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        cnt[s[i] - 'a']++;
    }

    int ans = fact(s.size());
    for (int i = 0; i < 30; i++) {
        if (cnt[i] == 0) continue;
        ans *= inverse(fact(cnt[i]));
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}
