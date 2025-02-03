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
const int N = 1e6 + 5;

int t, n, dp[N][2];

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;

    dp[1][0] = 1;
    dp[1][1] = 1;

    for (int i = 2; i < N; i++) {
        dp[i][0] = 4 * dp[i - 1][0] + dp[i - 1][1];
        dp[i][0] %= MOD;

        dp[i][1] = dp[i - 1][0] + 2 * dp[i - 1][1];
        dp[i][1] %= MOD;
    }

    while (t--) {
        cin >> n;

        cout << (dp[n][0] + dp[n][1]) % MOD << endl;
    }


    return 0;
}
