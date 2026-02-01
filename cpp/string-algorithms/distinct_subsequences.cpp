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
const int N = 5e5 + 5;

int n, dp[N], pos[30];
string s;

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    dp[0] = 0;
    memset(pos, -1, sizeof(pos));

    for (int i = 1; i <= s.size(); i++) {
        dp[i] = 2 * dp[i - 1] + 1;
        if (pos[s[i - 1] - 'a'] != -1) {
            dp[i] -= dp[pos[s[i - 1] - 'a'] - 1] + 1;
            dp[i] += MOD;
        }
        dp[i] %= MOD;
        pos[s[i - 1] - 'a'] = i;
    }

    cout << dp[s.size()] << endl;

    return 0;
}
