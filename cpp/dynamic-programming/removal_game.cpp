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
const int N = 5e3 + 5;

int n, dp[N][N], coins[N];

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    for (int l = n - 1; l >= 0; l--) {
        for (int r = 0; r < n; r++) {
            if (l > r) continue;

            bool turn = ((n - (r - l + 1)) % 2) == 0;

            if (turn) {
                dp[l][r] = max(coins[l] + dp[l + 1][r], coins[r] + dp[l][r - 1]);
            }
            else {
                dp[l][r] = min(dp[l + 1][r], dp[l][r - 1]);
            }
        }
    }

    cout << dp[0][n - 1] << endl;


    return 0;
}
