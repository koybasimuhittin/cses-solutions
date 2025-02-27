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
const int N = 105;

int n, a, b;
double dp[N][6 * N];

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> a >> b;

    dp[0][0] = 1.0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6 * N; j++) {
            for (int k = 1; k <= 6; k++) {
                if (j - k >= 0) {
                    dp[i][j] += dp[i - 1][j - k];
                }
            }
            dp[i][j] /= 6.0;
        }
    }

    double res = 0.0;

    for (int i = a; i <= b; i++) {
        res += (double)dp[n][i];
    }

    cout << fixed << setprecision(6) << res << endl;


    return 0;
}
