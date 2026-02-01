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
const int M = 20;

int n, m, q, dp[N][M], lca[N][M], parent[N], sz[N], depth[N];
vector<pair<int, int>> adj[N], edges;

int get_parent(int node) {
    if (parent[node] == node) return node;
    return get_parent(parent[node]);
}

bool merge(int a, int b) {
    a = get_parent(a);
    b = get_parent(b);

    if (a == b) return false;
    if (sz[a] < sz[b])swap(a, b);

    sz[a] += sz[b];
    parent[b] = a;
    return true;
}

void dfs(int node, int p, int d) {
    depth[node] = d;
    lca[node][0] = p;
    for (auto [child, w] : adj[node]) {
        if (child != p) {
            dp[child][0] = w;
            dfs(child, node, d + 1);
        }
    }
}

int get(int a, int b) {
    if (depth[a] > depth[b])swap(a, b);

    int res = 0;

    for (int i = M - 1; i >= 0; i--) {
        if ((depth[b] - depth[a]) & (1 << i)) {
            res = max(res, dp[b][i]);
            b = lca[b][i];
        }
    }

    if (a == b) return res;

    for (int i = M - 1; i >= 0; i--) {
        if (lca[a][i] != lca[b][i]) {
            res = max(res, max(dp[b][i], dp[a][i]));
            a = lca[a][i];
            b = lca[b][i];
        }
    }

    if (lca[a][0] != lca[b][0]) return -1;
    res = max(res, max(dp[a][0], dp[b][0]));

    return res;

}

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> q;

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }

    int a, b;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        if (merge(a, b)) {
            adj[a].pb({ b, i });
            adj[b].pb({ a, i });
        }
    }
    memset(depth, -1, sizeof(depth));
    for (int i = 1; i <= n; i++) {
        if (depth[i] == -1) {
            dfs(i, i, 0);
        }
    }
    for (int j = 1; j < M; j++) {
        for (int i = 1; i <= n; i++) {
            dp[i][j] = max(dp[i][j - 1], dp[lca[i][j - 1]][j - 1]);
            lca[i][j] = lca[lca[i][j - 1]][j - 1];
        }
    }

    while (q--) {
        cin >> a >> b;
        cout << get(a, b) << endl;
    }

    return 0;
}
