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
const int N = 1e3 + 5;
const int M = 1e2 + 5;

int n, pi[M], dp[N][M];
string s;

int solve(int idx, int kmp) {
    if (idx >= n) {
        return kmp == s.size();
    }

    if (dp[idx][kmp] != -1) {
        return dp[idx][kmp];
    }

    dp[idx][kmp] = 0;

    if (kmp == s.size()) {
        dp[idx][kmp] += (('Z' - 'A' + 1) * solve(idx + 1, kmp)) % MOD;
    }
    else {
        for (char i = 'A'; i <= 'Z'; i++) {
            if (s[kmp] == i) {
                dp[idx][kmp] += solve(idx + 1, kmp + 1);
                dp[idx][kmp] %= MOD;
            }
            else {
                int j = pi[kmp - 1];
                while (j > 0 && i != s[j]) {
                    j = pi[j - 1];
                }
                if (i == s[j]) {
                    j++;
                }
                dp[idx][kmp] += solve(idx + 1, j);
                dp[idx][kmp] %= MOD;
            }
        }
    }
    return dp[idx][kmp] % MOD;
}

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> s;

    for (int i = 1; i < s.size(); i++) {
        int j = pi[i - 1];

        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        pi[i] = j;
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0) << endl;


    return 0;
}
