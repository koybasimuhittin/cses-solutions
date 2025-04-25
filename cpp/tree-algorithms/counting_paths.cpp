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
const int N = 2e5 + 5;
const int M = 21;

int n, q, dp[N][M], pref[N], depth[N];
vector<int> adj[N];

void dfs(int u, int p, int d = 0) {
    depth[u] = d;
    dp[u][0] = p;

    for (auto v : adj[u]) {
        if (v == p) continue;
        dfs(v, u, d + 1);
    }
}

void build() {
    for (int j = 1; j < M; j++) {
        for (int i = 1; i <= n; i++) {
            if (dp[i][j - 1] != -1) {
                dp[i][j] = dp[dp[i][j - 1]][j - 1];
            }
        }
    }
}

int get_nth_ancestor(int u, int n) {
    for (int i = 0; i < M; i++) {
        if (n & (1 << i)) {
            u = dp[u][i];
        }
    }

    return u;
}

int get_lca(int u, int v) {

    if (depth[u] < depth[v]) swap(u, v);
    u = get_nth_ancestor(u, depth[u] - depth[v]);

    if (u == v) return u;

    for (int i = M - 1; i >= 0; i--) {
        if (dp[u][i] != dp[v][i]) {
            u = dp[u][i];
            v = dp[v][i];
        }
    }

    return dp[u][0];
}

void calc(int u, int p) {
    for (auto v : adj[u]) {
        if (v == p) continue;
        calc(v, u);
        pref[u] += pref[v];
    }

}

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof(dp));

    cin >> n >> q;

    int a, b;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1, 0);
    build();

    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        pref[a]++;
        pref[b]++;
        int lca = get_lca(a, b);
        pref[lca]--;
        pref[dp[lca][0]]--;
    }

    calc(1, 0);

    for (int i = 1; i <= n; i++) {
        cout << pref[i] << " ";
    }
    cout << endl;




    return 0;
}
