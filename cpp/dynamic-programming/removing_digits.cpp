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

int n, dp[M];

vector<int> digits(int num) {
    vector<int> res;

    while (num > 0) {
        res.pb(num % 10);
        num /= 10;
    }

    return res;
}

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i <= n; i++) {
        dp[i] = INT_MAX;
    }

    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        vector<int> d = digits(i);

        for (int j = 0; j < d.size(); j++) {
            dp[i] = min(dp[i], dp[i - d[j]] + 1);
        }
    }

    cout << dp[n] << endl;


    return 0;
}
