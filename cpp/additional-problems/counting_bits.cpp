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
const int N = 50;

string s;
int dp[N][2][2], n;

int solve(int i, int prev, bool tight, int kth) {
    if (i == s.size()) {
        return 1;
    }
    if (dp[i][prev][tight] != -1) {
        return dp[i][prev][tight];
    }

    int ans = 0;
    int limit = tight ? s[i] - '0' : 1;

    if (kth == i) {
        if (tight && s[i] == '0') {
            return dp[i][prev][tight] = 0;
        }
        ans += solve(i + 1, 1, tight, kth);
    }
    else {
        for (int j = 0; j <= limit; j++) {
            ans += solve(i + 1, j, tight && (j == limit), kth);
        }
    }

    return dp[i][prev][tight] = ans;
}

vector<int> v;

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    while (n > 0) {
        s += (n % 2) + '0';
        n /= 2;
    }

    reverse(s.begin(), s.end());

    int ans = 0;

    for (int i = 0; i < s.size(); i++) {
        memset(dp, -1, sizeof(dp));
        ans += solve(0, 0, true, i);
    }

    cout << ans << endl;



    return 0;
}
