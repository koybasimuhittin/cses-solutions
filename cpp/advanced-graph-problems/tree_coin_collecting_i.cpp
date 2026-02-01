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
const int INF = 1e9;

int n, m, dist_to_nearest_coin[N], depth[N], lca[N][25], dp[N][25];
vector<int> adj[N];

void dfs(int node, int d, int parent) {
    depth[node] = d;
    lca[node][0] = parent;
    dp[node][0] = dist_to_nearest_coin[node];

    for (auto child : adj[node]) {
        if (child == parent) continue;

        dfs(child, d + 1, node);
    }
}

void build_dp() {
    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j <= n; j++) {
            lca[j][i] = lca[lca[j][i - 1]][i - 1];
            dp[j][i] = min(dp[j][i - 1], dp[lca[j][i - 1]][i - 1]);
        }
    }
}

int get(int a, int b) {
    int res = 0;
    if (depth[a] > depth[b])swap(a, b);

    int nearest = min(dp[a][0], dp[b][0]);
    int diff = depth[b] - depth[a];
    res += diff;

    for (int i = 19; i >= 0; i--) {
        if (diff & (1 << i)) {
            nearest = min(nearest, dp[b][i]);
            b = lca[b][i];
            diff ^= (1 << i);
        }
    }

    for (int i = 19;i >= 0; i--) {
        if (lca[a][i] != lca[b][i]) {
            nearest = min(nearest, min(dp[a][i], dp[b][i]));
            a = lca[a][i];
            b = lca[b][i];

            res += (1 << (i + 1));
        }
    }

    if (a != b) {
        nearest = min(nearest, min(dp[a][0], dp[b][0]));
        nearest = min(nearest, dp[lca[a][0]][0]);
        a = lca[a][0];
        b = lca[b][0];
        res += 2;
    }

    nearest = min(nearest, dp[a][0]);

    return 2 * nearest + res;
}


int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    int a, b;

    queue<int> q;

    for (int i = 1; i <= n; i++) {
        cin >> a;
        dist_to_nearest_coin[i] = INF;
        if (a) {
            dist_to_nearest_coin[i] = 0;
            q.push(i);
        }
    }

    for (int i = 0; i < 25; i++) {
        for (int j = 0; j <= n; j++) {
            lca[j][i] = 1;
            dp[j][i] = INF;
        }
    }

    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto child : adj[node]) {
            if (dist_to_nearest_coin[child] == INF) {
                dist_to_nearest_coin[child] = dist_to_nearest_coin[node] + 1;
                q.push(child);
            }
        }
    }

    dfs(1, 0, 1);
    build_dp();

    while (m--) {
        cin >> a >> b;
        cout << get(a, b) << endl;

    }

    return 0;
}