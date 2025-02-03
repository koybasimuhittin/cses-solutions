#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define f1 first
#define s2 second
#define pb push_back
#define mp make_pair
#define int long long
#define fri(a) freopen(a,"r",stdin);
#define fro(a) freopen(a,"w",stdout);
const int MOD = 1e9 + 7;
const int N = 5e2 + 5;
const int M = N * (N + 1) / 2;
const int INV = 5e8 + 4;

int n, m, dp[2][M];

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    dp[0][0] = 1;


    for (int i = 1; i <= n; i++) {
        for (int j = i; j < M; j++) {
            dp[1][j] += dp[0][j - i];
            dp[1][j] %= MOD;
        }

        for (int j = i; j < M; j++) {
            dp[0][j] = dp[1][j];
        }
    }

    if ((n * (n + 1)) % 4 == 0) {
        cout << (dp[0][n * (n + 1) / 4] * INV) % MOD << endl;
    }
    else {
        cout << 0 << endl;
    }


    return 0;
}
