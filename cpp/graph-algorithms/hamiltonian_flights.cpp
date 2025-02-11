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
const int N = 20;

int n, m, dp[N][1 << N];
vector<int> adj[N];

int solve(int node, int mask) {
    if (node == (n - 1)) {
        if (mask == (1 << n) - 1) {
            return 1;
        }
        else {
            return 0;
        }
    }

    if (dp[node][mask] != -1) return dp[node][mask];

    dp[node][mask] = 0;

    for (auto& neighbour : adj[node]) {
        if ((mask & (1 << neighbour)) == 0) {
            dp[node][mask] += solve(neighbour, (mask | (1 << neighbour)));
            dp[node][mask] %= MOD;
        }
    }

    return dp[node][mask];
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
        a--, b--;
        adj[a].pb(b);
    }

    memset(dp, -1, sizeof(dp));

    cout << solve(0, 1) << endl;




    return 0;
}
