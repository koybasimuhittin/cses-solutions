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

int n, dp[N][2];
vector<int> adj[N];

int solve(int node, int parent, int taken) {
    if (dp[node][taken] != -1) return dp[node][taken];

    dp[node][taken] = 0;

    int diff = 0;

    for (auto& child : adj[node]) {
        if (child == parent) continue;
        if (taken) {
            dp[node][taken] += solve(child, node, 0);
        } else {
            int a = solve(child, node, 0);
            int b = solve(child, node, 1) + 1;

            dp[node][taken] += a;
            diff = max(diff, b - a);
        }
    }
    dp[node][taken] += diff;

    return dp[node][taken];
}

int32_t main() {
    // fri("in.txt");
    // fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    int a, b;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(1, 0, 0) << endl;

    return 0;
}
