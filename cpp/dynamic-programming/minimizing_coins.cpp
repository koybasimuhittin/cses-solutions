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
const int N = 1e2 + 5;
const int M = 1e6 + 5;

int n, m, dp[M], coins[N];

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    for (int i = 1; i < M; i++) {
        dp[i] = INT_MAX;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < n; j++) {
            if (i - coins[j] >= 0) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    if (dp[m] >= INT_MAX) {
        cout << -1 << endl;
    }
    else {
        cout << dp[m] << endl;
    }


    return 0;
}
