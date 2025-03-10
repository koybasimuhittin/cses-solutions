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

int n, m, depth[N], first_occurance[N];
vector<int> euler_path, adj[N], seg;

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

void build(int v, int tl, int tr) {
    if (tl == tr) {
        seg[v] = euler_path[tl];
        return;
    }

    int tm = (tl + tr) / 2;

    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);

    seg[v] = mini(seg[v * 2], seg[v * 2 + 1]);
}

int get(int v, int tl, int tr, int l, int r) {
    if (l > r) {
        return N - 1;
    }
    if (l == tl && r == tr) {
        return seg[v];
    }

    int tm = (tl + tr) / 2;

    return mini(get(v * 2, tl, tm, l, min(r, tm)),
                get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

int32_t main() {
    // fri("in.txt");
    // fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int a, b;
    for (int i = 2; i <= n; i++) {
        cin >> a;
        adj[a].pb(i);
        adj[i].pb(a);
    }
    depth[N - 1] = INT_MAX;

    dfs(1, 0);
    seg.resize(4 * euler_path.size());
    build(1, 0, euler_path.size() - 1);

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        int l = first_occurance[a];
        int r = first_occurance[b];
        if (l > r) swap(l, r);
        cout << get(1, 0, euler_path.size() - 1, l, r) << endl;
    }

    return 0;
}