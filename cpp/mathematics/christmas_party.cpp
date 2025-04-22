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

int n, dp[N];

int derangement(int n) {
    if (n == 0) return 1;
    if (n == 1) return 0;

    if (dp[n] != -1) {
        return dp[n];
    }

    return dp[n] =
               (n - 1) * (derangement(n - 1) + derangement(n - 2) % MOD) % MOD;
}

int32_t main() {
    // fri("in.txt");
    // fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    memset(dp, -1, sizeof(dp));

    cout << derangement(n) << endl;

    return 0;
}
