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
const int M = 20;

int n, m, dp[M][N];

int32_t main() {
    // fri("in.txt");
    // fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < N; i++) {
        dp[0][i] = N - 1;
    }

    cin >> n >> m;
    int l, r;
    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        dp[0][l] = min(dp[0][l], r);
    }
    for (int i = N - 2; i >= 0; i--) {
        dp[0][i] = min(dp[0][i], dp[0][i + 1]);
    }

    for (int j = 1; j < M; j++) {
        for (int i = 1; i < N; i++) {
            dp[j][i] = dp[j - 1][dp[j - 1][i]];
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> l >> r;
        int ans = 0;
        for (int j = M - 1; j >= 0; j--) {
            if (dp[j][l] <= r) {
                ans += (1 << j);
                l = dp[j][l];
            }
        }
        cout << ans << endl;
        fflush(stdout);
    }

    return 0;
}
