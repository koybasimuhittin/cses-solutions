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
const int N = 1e6 + 5;

int n, m, dp[N];

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    int arr[] = { 1, 2, 3, 4, 5, 6 };
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 6; j++) {
            if (i - arr[j] >= 0) {
                dp[i] += dp[i - arr[j]];
                dp[i] %= MOD;
            }
        }
    }

    cout << dp[n] << endl;


    return 0;
}
