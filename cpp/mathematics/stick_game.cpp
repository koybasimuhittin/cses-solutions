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
const int N = 1e2 + 5;
const int M = 1e6 + 5;

int n, m, sticks[N], dp[M];

int32_t main() {
    // fri("in.txt");
    // fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, 0, sizeof(dp));

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> sticks[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            if (i - sticks[j] >= 0) {
                dp[i] = dp[i] || (1 - dp[i - sticks[j]]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dp[i]) {
            cout << "W";
        } else {
            cout << "L";
        }
    }
    cout << endl;
    return 0;
}
