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
const int N = 3e3 + 5;

int n;
vector<string> v;
string dp[N][N];

string solve(int r, int c) {
    if (r >= n || c >= n) {
        return "";
    }

    if (dp[r][c] != "") {
        return dp[r][c];
    }

    string a = solve(r + 1, c);
    string b = solve(r, c + 1);

    if (a.size() > b.size()) {
        dp[r][c] = a + v[r][c];
    } else if (a.size() < b.size()) {
        dp[r][c] = b + v[r][c];
    } else {
        dp[r][c] = min(a, b) + v[r][c];
    }

    return dp[r][c];
}

int32_t main() {
    fri("in.txt");
    fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    string s;

    for (int i = 0; i < n; i++) {
        cin >> s;
        v.pb(s);
    }

    cout << solve(0, 0) << endl;

    return 0;
}
