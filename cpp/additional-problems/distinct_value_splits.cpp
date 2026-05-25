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
const int N = 2e5 + 5;

int n, arr[N], next_position[N], dp[N], suffix_dp[N];
map<int, int> np;

int32_t main() {

    //fri("test_input-2.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;


    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        next_position[i] = n;
    }
    next_position[n] = n;

    dp[n] = 1;
    suffix_dp[n] = 1;

    for (int i = n - 1; i >= 0; i--) {
        if (np[arr[i]] != 0) {
            next_position[i] = np[arr[i]];
        }
        np[arr[i]] = i;
        next_position[i] = min(next_position[i], next_position[i + 1]);

        dp[i] = (suffix_dp[i + 1] - suffix_dp[next_position[i] + 1] + MOD) % MOD;
        dp[i] %= MOD;
        suffix_dp[i] = (suffix_dp[i + 1] + dp[i]) % MOD;

        //cout << i << ' ' << next_position[i] << ' ' << dp[i] << ' ' << suffix_dp[i] << endl;

    }

    cout << dp[0] << endl;



    return 0;
}
