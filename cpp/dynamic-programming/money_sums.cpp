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

int n, m, coins[N];
bool dp[2][M];

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    dp[0][0] = true;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < M; j++) {
            if (j - coins[i] >= 0) {
                dp[1][j] |= dp[0][j - coins[i]];
            }
        }

        for (int j = 1; j < M; j++) {
            dp[0][j] = dp[1][j];
        }
    }

    int cnt = 0;

    for (int i = 1; i < M; i++) {
        cnt += dp[0][i];
    }

    cout << cnt << endl;
    for (int i = 1; i < M; i++) {
        if (dp[0][i]) {
            cout << i << " ";
        }
    }

    cout << endl;


    return 0;
}
