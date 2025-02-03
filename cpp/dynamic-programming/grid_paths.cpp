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
const int N = 1e3 + 5;

int n, m, dp[N][N];
char grid[N][N];

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    dp[n - 1][n - 1] = grid[n - 1][n - 1] == '.';

    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (grid[i][j] == '*') continue;

            if (j + 1 < n) {
                dp[i][j] += dp[i][j + 1];
                dp[i][j] %= MOD;
            }

            if (i + 1 < n) {
                dp[i][j] += dp[i + 1][j];
                dp[i][j] %= MOD;
            }

            //cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }

    cout << dp[0][0] << endl;


    return 0;
}
