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
const int M = 1e5 + 5;

int n, m, dp[2][M], h[N], s[N];

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j - h[i] >= 0) {
                dp[1][j] = max(dp[1][j], dp[0][j - h[i]] + s[i]);
            }
        }

        for (int j = 1; j <= m; j++) {
            dp[0][j] = dp[1][j];
        }
    }

    int ans = 0;

    for (int i = 0; i <= m; i++) {
        ans = max(ans, dp[0][i]);
    }

    cout << ans << endl;


    return 0;
}
