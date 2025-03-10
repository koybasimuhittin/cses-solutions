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
const int M = 20;

int n, m, depth[N], first_occurance[N], sparse_table[4 * N][M];
vector<int> euler_path, adj[N];

void dfs(int u, int p) {
    if (p != 0) depth[u] = depth[p] + 1;
    first_occurance[u] = euler_path.size();
    euler_path.pb(u);

    for (auto v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        euler_path.pb(u);
    }
}

int mini(int a, int b) {
    if (depth[a] < depth[b]) {
        return a;
    }
    return b;
}

void build() {
    for (int i = 0; i < euler_path.size(); i++) {
        sparse_table[i][0] = euler_path[i];
    }

    for (int i = 1; i < M; i++) {
        for (int j = 0; j < euler_path.size(); j++) {
            if ((1 << i) < euler_path.size()) {
                sparse_table[j][i] =
                    mini(sparse_table[j][i - 1],
                         sparse_table[j + (1 << (i - 1))][i - 1]);
            }
        }
    }
}

int get(int l, int r) {
    int log = log2(r - l + 1);
    return mini(sparse_table[l][log], sparse_table[r - (1 << log) + 1][log]);
}

int32_t main() {
    // fri("in.txt");
    // fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < N; i++) {
        depth[i] = INT_MAX;
    }

    int a, b;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    depth[1] = 0;
    dfs(1, 0);
    build();

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        int l = first_occurance[a];
        int r = first_occurance[b];
        if (l > r) swap(l, r);
        int lca = get(l, r);
        cout << abs(depth[a] - depth[lca]) + abs(depth[b] - depth[lca]) << endl;
    }

    return 0;
}
