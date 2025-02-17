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
const int M = 20;

int n, m, dp[N][M];

void calc_dp() {
    for (int i = 1; i < M; i++) {
        for (int j = 1; j <= n; j++) {
            if (dp[j][i - 1] == -1) {
                dp[j][i] = -1;
            } else {
                dp[j][i] = dp[dp[j][i - 1]][i - 1];
            }
        }
    }
}

int get_nth_parent(int node, int n) {
    for (int i = 0; i < M; i++) {
        if (n & (1 << i)) {
            if (node != -1) {
                node = dp[node][i];
            }
        }
    }

    return node;
}

int32_t main() {
    // fri("in.txt");
    // fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    dp[1][0] = -1;

    for (int i = 2; i <= n; i++) {
        cin >> dp[i][0];
    }

    calc_dp();

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;

        cout << get_nth_parent(a, b) << endl;
    }

    return 0;
}
