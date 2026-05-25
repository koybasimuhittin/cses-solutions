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
const int M = 1e6 + 5;

int n, sz[N], res;
vector<pair<int, int>> adj[N];
bool banned[N];

int get_subtree_size(int u, int p = -1) {
    sz[u] = 1;
    for (auto& [v, c] : adj[u]) {
        if (v != p && !banned[v]) {
            sz[u] += get_subtree_size(v, u);
        }
    }

    return sz[u];
}

int find_centroid(int u, int s, int p = -1) {
    for (auto& [v, c] : adj[u]) {
        if (v != p && !banned[v] && 2 * sz[v] >= s) {
            return find_centroid(v, s, u);
        }
    }

    return u;
}

vector<int> update(int u, int p, int w) {
    vector<int> edges;
    queue<tuple<int, int, int>> q;
    q.push({ u, p, w });

    while (!q.empty()) {
        auto [u, p, w] = q.front();
        q.pop();

        edges.pb(w);

        for (auto& [v, c] : adj[u]) {
            if (v != p && !banned[v]) {
                q.push({ v, u, min(w, c) });
            }
        }
    }

    return edges;
}

void solve(int u) {
    vector<int> edges;
    for (auto& [v, c] : adj[u]) {
        if (!banned[v]) {
            vector<int> child_edges = update(v, u, c);
            sort(child_edges.begin(), child_edges.end());

            int n = edges.size();
            int m = child_edges.size();
            vector<int> merged(n + m);

            int l = 0;
            int r = 0;
            while (l < n && r < m) {
                if (edges[l] <= child_edges[r]) {
                    res += edges[l] * (m - r);
                    merged[l + r] = edges[l];
                    l++;
                }
                else {
                    res += child_edges[r] * (n - l + 1);
                    merged[l + r] = child_edges[r];
                    r++;
                }
            }
            while (l < n) {
                merged[l + r] = edges[l];
                l++;
            }
            while (r < m) {
                res += child_edges[r];
                merged[l + r] = child_edges[r];
                r++;
            }

            swap(edges, merged);

        }
    }
}

void build_centroid_decomposition(int u) {
    int c = find_centroid(u, get_subtree_size(u));
    solve(c);
    banned[c] = true;

    for (auto& [v, w] : adj[c]) {
        if (!banned[v])build_centroid_decomposition(v);
    }
}

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    int a, b, c;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b >> c;
        adj[a].pb({ b, c });
        adj[b].pb({ a, c });
    }

    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end(), [&](const pair<int, int> a, const pair<int, int>b) {
            return a.s2 > b.s2;
            });
    }
    build_centroid_decomposition(1);

    cout << res << endl;


    return 0;
}
