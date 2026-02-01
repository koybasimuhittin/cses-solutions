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
const int N = 1e5 + 5;

int n, m, q, res[2 * N];
vector<int> v;

class DSU {
private:
    vector<int> sz, p;
    vector<pair<int&, int>> history;
    int component_count;
public:
    void init(int n) {
        p.resize(n + 1);
        sz.resize(n + 1, 1);
        component_count = n;
        iota(p.begin(), p.end(), 0);

    }
    int find(int u) {
        if (u == p[u])return u;
        return find(p[u]);
    }
    void unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;
        if (sz[u] < sz[v])swap(u, v);

        history.pb({ p[v], p[v] });
        history.pb({ sz[u], sz[u] });
        history.pb({ component_count, component_count });
        p[v] = u;
        sz[u] += sz[v];
        component_count--;
    }

    int snapshot() {
        return history.size();
    }

    int get() {
        return component_count;
    }

    void rollback(int until) {
        while (snapshot() > until) {
            history.back().f1 = history.back().s2;
            history.pop_back();
        }
    }
};

typedef struct Query {
    int u, v;

    Query(int _u, int _v) {
        u = _u;
        v = _v;
    }
} Query;

map<pair<int, int>, pair<vector<int>, vector<int>>> edges;
vector<Query> seg[8 * N];
DSU dsu;

void update(int v, int tl, int tr, int l, int r, const Query& q) {
    if (l > r) return;
    if (l == tl && r == tr) {
        seg[v].pb(q);
        return;
    }
    int tm = (tl + tr) >> 1;
    update(v * 2, tl, tm, l, min(r, tm), q);
    update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, q);
}

void fill_seg() {
    for (auto [nodes, times] : edges) {
        for (int i = 0; i < times.f1.size(); i++) {
            int start = times.f1[i];
            int finish = m + q - 1;
            if (times.s2.size() > i) finish = times.s2[i];
            update(1, 0, m + q - 1, start, finish, Query(nodes.f1, nodes.s2));
        }
    }
}

void solve(int v, int l, int r) {
    int snapshot = dsu.snapshot();

    for (Query& q : seg[v])
        dsu.unite(q.u, q.v);

    if (l == r) {
        res[l] = dsu.get();
    }

    else {
        solve(v * 2, l, (l + r) / 2);
        solve(v * 2 + 1, (l + r) / 2 + 1, r);
    }

    dsu.rollback(snapshot);
}


int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> n >> m >> q;

    dsu.init(n);

    int a, b;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        if (a > b) swap(a, b);
        edges[{a, b}].f1.pb(0);
    }

    int t;
    for (int i = m; i < q + m; i++) {
        cin >> t >> a >> b;
        if (a > b) swap(a, b);
        if (t == 1) {
            edges[{a, b}].f1.pb(i);
        }
        else {
            edges[{a, b}].s2.pb(i - 1);
        }
    }

    fill_seg();
    solve(1, 0, m + q - 1);

    for (int i = m - 1; i < m + q; i++) {
        cout << res[i] << " ";
    }


    return 0;
}
