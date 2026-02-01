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

int n, m, t, arr[N], dp[N], last_non_distinct_index;
map<int, int> last_occurrence;
int fpow(int a, int b) {
    if (b < 0) return 0;
    int res = 1;
    while (b) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int32_t main() {
    fri("in.txt");
    fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        last_occurrence[arr[i]] = n;
    }
    last_non_distinct_index = n;
    last_occurrence[arr[n - 1]] = n - 1;
    dp[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        last_non_distinct_index =
            min(last_non_distinct_index, last_occurrence[arr[i]]);
        last_occurrence[arr[i]] = i;
        if (last_non_distinct_index != n) {
            dp[i] = dp[i + 1] + (dp[last_non_distinct_index] *
                                 fpow(2, last_non_distinct_index - i - 2)) %
                                    MOD;
        } else {
            dp[i] = 2 * dp[i + 1];
        }
        cout << dp[i] << " " << last_non_distinct_index << endl;
        dp[i] %= MOD;
    }
    cout << dp[0] << endl;

    return 0;
}
