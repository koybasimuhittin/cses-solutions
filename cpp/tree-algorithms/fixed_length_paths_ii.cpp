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
const int N = 200000 + 5;

long long ans;
int n, m, k1, k2, subtree_size[N], cnt[N], bit[N];
vector<int> adj[N];
bool dead[N];

inline void update(int idx, int val, int n = N) {
    for (; idx < n; idx = idx | (idx + 1))
        bit[idx] += val;
}

int get(int l, int r) {
    int ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
        ret += bit[r];
    for (l--; l >= 0; l = (l & (l + 1)) - 1)
        ret -= bit[l];
    return ret;
}

inline void dfs(int u, int p) {
    subtree_size[u] = 1;
    for (int v : adj[u]) {
        if (v == p || dead[v]) continue;
        dfs(v, u);
        subtree_size[u] += subtree_size[v];
    }
}

int find_centroid(int u, int p, int sz) {
    for (int v : adj[u]) {
        if (v == p || dead[v]) continue;
        if ((subtree_size[v] << 1) > sz)
            return find_centroid(v, u, sz);
    }
    return u;
}

void calc(int u, int p, int r) {
    if (r > k2) return;
    ans += get(max(0, k1 - r), k2 - r);
    for (int v : adj[u]) {
        if (v == p || dead[v]) continue;
        calc(v, u, r + 1);
    }
}

void updt(int u, int p, int r, int sz) {
    if (r > k2) return;
    cnt[r]++;
    update(r, 1, sz);
    for (int v : adj[u]) {
        if (v == p || dead[v]) continue;
        updt(v, u, r + 1, sz);
    }
}

inline void solve(int c, int sz) {
    cnt[0] = 1;
    update(0, 1, sz);
    for (int v : adj[c]) {
        if (dead[v]) continue;
        calc(v, c, 1);
        updt(v, c, 1, sz);
    }

    for (int i = 0; i <= min(sz, k2); i++) {
        bit[i] = 0;
        cnt[i] = 0;
    }
}

inline void build(int u) {
    dfs(u, 0);
    int c = find_centroid(u, 0, subtree_size[u]);
    dead[c] = true;
    solve(c, subtree_size[u] + 10);
    for (int v : adj[c]) {
        if (!dead[v]) build(v);
    }
}

int32_t main() {
    //fri("in.txt");
    //fro("out.txt");
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k1 >> k2;
    int a, b;
    for (int i = 1; i <= n - 1; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    ans = 0;
    build(1);

    cout << ans << endl;

    return 0;
}
