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

int n, m, values[N], heavy[N], head[N], subtree_size[N], depth[N], parent[N], pos[N], t, seg[4 * N];
vector<int> adj[N];

void dfs(int u, int p) {
    parent[u] = p;
    heavy[u] = -1;
    depth[u] = depth[p] + 1;

    for (auto v : adj[u]) {
        if (v == p)continue;
        dfs(v, u);
        subtree_size[u] += subtree_size[v];

        if (heavy[u] == -1 || subtree_size[heavy[u]] < subtree_size[v]) {
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
        if (v == heavy[u] || v == parent[u]) continue;

        decompose(v, v);
    }
}

void update(int v, int tl, int tr, int pos, int el) {
    if (tl == tr) {
        seg[v] = el;
    }
    else {
        int tm = (tl + tr) / 2;
        if (pos <= tm) {
            update(v * 2, tl, tm, pos, el);
        }
        else {
            update(v * 2 + 1, tm + 1, tr, pos, el);
        }
        seg[v] = seg[v * 2] + seg[v * 2 + 1];
    }
}

int get(int v, int tl, int tr, int l, int r) {
    if (l > r) {
        return 0;
    }
    if (tl == l && tr == r) {
        return seg[v];
    }
    int tm = (tl + tr) / 2;
    return get(v * 2, tl, tm, l, min(r, tm)) + get(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r);
}

int query(int l, int r) {
    int ans = 0;

    while (head[l] != head[r]) {
        if (depth[head[l]] < depth[head[r]]) {
            swap(l, r);
        }
        ans += get(1, 0, n - 1, pos[head[l]], pos[l]);
        l = parent[head[l]];
    }

    if (depth[l] > depth[head[r]]) {
        swap(l, r);
    }
    ans += get(1, 0, n - 1, pos[l], pos[r]);

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
        update(1, 0, n - 1, pos[i], values[i]);
    }

    for (int i = 0; i < m; i++) {
        cin >> a;
        if (a == 1) {
            cin >> a >> b;
            values[a] = b;
            update(1, 0, n - 1, pos[a], b);
        }
        else {
            cin >> a;
            cout << query(1, a) << endl;
        }
    }


    return 0;
}
