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
const int N = 21;
const int M = 1e6 + 5;

int n, m, weights[N];
pair<int, int> dp[1 << N];

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    for (int i = 0; i < (1 << N); i++) {
        dp[i] = mp(INT_MAX, INT_MAX);
    }

    dp[0] = mp(1, 0);

    for (int i = 1; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if ((i & (1 << j)) > 0) {
                if (weights[j] + dp[i ^ (1 << j)].s2 > m) {
                    dp[i] = min(dp[i], mp(dp[i ^ (1 << j)].f1 + 1, weights[j]));
                }
                else {
                    dp[i] = min(dp[i], mp(dp[i ^ (1 << j)].f1, dp[i ^ (1 << j)].s2 + weights[j]));
                }
            }
        }
    }

    cout << dp[(1 << n) - 1].f1 << endl;

    return 0;
}
