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
const int M = 1e2 + 5;
const int N = 1e5 + 5;

int n, m, dp[N][M], nums[N];

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    if (nums[0] == 0) {
        for (int i = 1; i <= m; i++) {
            dp[0][i] = 1;
        }
    }

    else {
        dp[0][nums[0]] = 1;
    }

    int ans = 0;

    for (int i = 1; i < n; i++) {
        if (nums[i] == 0) {
            for (int j = 1; j <= m; j++) {
                for (int d = -1; d <= 1; d++) {
                    if (j + d > 0 && j + d <= m) {
                        dp[i][j] += dp[i - 1][j + d];
                        dp[i][j] %= MOD;
                    }
                }
            }
        }
        else {
            for (int d = -1; d <= 1; d++) {
                if (nums[i] + d > 0 && nums[i] + d <= m) {
                    dp[i][nums[i]] += dp[i - 1][nums[i] + d];
                    dp[i][nums[i]] %= MOD;
                }
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        ans += dp[n - 1][i];
        ans %= MOD;
    }

    cout << ans << endl;


    return 0;
}
