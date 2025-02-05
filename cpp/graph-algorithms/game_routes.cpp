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
const int N = 1e5 + 5;

int n, m, dp[N];
vector<int> adj[N];

int solve(int node) {
    if (node == n) return 1;
    if (dp[node] != -1) return dp[node];

    dp[node] = 0;
    for (auto child : adj[node]) {
        dp[node] += solve(child);
        dp[node] %= MOD;
    }

    return dp[node];
}

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].pb(b);
    }

    memset(dp, -1, sizeof(dp));
    cout << solve(1) << endl;


    return 0;
}
