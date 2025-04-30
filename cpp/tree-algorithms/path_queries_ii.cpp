#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define f1 first
#define s2 second
#define pb push_back
#define mp make_pair
#define fri(a) freopen(a,"r",stdin);
#define fro(a) freopen(a,"w",stdout);
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;

int n, m, t, values[N], parent[N], head[N], heavy[N], subtree_size[N], seg[2 * N], pos[N], depth[N];
vector<int> adj[N];

void dfs(int u, int p) {
    parent[u] = p;
    heavy[u] = -1;
    depth[u] = depth[p] + 1;

    for (auto v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        subtree_size[u] += subtree_size[v];

        if (heavy[u] == -1 || subtree_size[v] > subtree_size[heavy[u]]) {
            heavy[u] = v;
        }
    }
    subtree_size[u]++;
}

void decompose(int u, int h) {
    head[u] = h;
    pos[u] = t++;

    if (heavy[u] != -1) {
        decompose(heavy[u], h);
    }

    for (auto v : adj[u]) {
        if (v == parent[u] || v == heavy[u])continue;
        decompose(v, v);
    }
}

void update(int p, int val) {
    p += N;
    seg[p] = val;
    for (p >>= 1; p; p >>= 1)
        seg[p] = max(seg[p << 1], seg[p << 1 | 1]);
}

int get(int l, int r) {
    l += N;  r += N;
    int ans = INT_MIN;
    while (l <= r) {
        if (l & 1) ans = max(ans, seg[l++]);
        if (!(r & 1)) ans = max(ans, seg[r--]);
        l >>= 1; r >>= 1;
    }
    return ans;
}

int query(int a, int b) {
    int ans = 0;
    while (head[a] != head[b]) {
        if (depth[head[a]] < depth[head[b]]) {
            swap(a, b);
        }
        ans = max(ans, get(pos[head[a]], pos[a]));
        a = parent[head[a]];
    }

    if (depth[a] > depth[b]) {
        swap(a, b);
    }
    ans = max(ans, get(pos[a], pos[b]));

    return ans;
}

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> values[i];
    }

    int a, b;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(1, 0);
    decompose(1, 1);

    for (int i = 1; i <= n; i++) {
        update(pos[i], values[i]);
    }

    for (int i = 0; i < m; i++) {
        cin >> a;
        if (a == 1) {
            cin >> a >> b;
            values[a] = b;
            update(pos[a], b);
        }
        else {
            cin >> a >> b;
            cout << query(a, b) << " ";
        }
    }
    cout << endl;


    return 0;
}
