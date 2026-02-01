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
const int N = 2500 + 5;
const int INF = 1e14 + 5;

int n, m, t, cycle_end, cycle_start, parent[N], dist[N];
vector<tuple<int, int, int>> edges;
vector<pair<int, int>> adj[N];
bool vis[N];

void dfs(int node, int d) {
    vis[node] = true;
    for (auto& [to, weight] : adj[node]) {
        if (cycle_end != -1) return;
        if (to == cycle_start && d + weight < 0) {
            cycle_end = node;
            return;
        }

        if (!vis[to]) {
            parent[to] = node;
            dfs(to, d + weight);
        }
    }
    vis[node] = false;
}

int32_t main() {

    fri("in.txt");
    fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < N; i++) {
        dist[i] = INF;
    }

    dist[1] = 0;

    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        edges.pb({ a, b, c });
        adj[a].pb({ b, c });
    }

    for (int i = 1; i < n; i++) {
        for (auto& [from, to, weight] : edges) {
            dist[to] = min(dist[to], dist[from] + weight);
        }
    }

    cycle_start = cycle_end = -1;

    for (auto& [from, to, weight] : edges) {
        if (dist[to] > dist[from] + weight) {
            cycle_start = from;
            break;
        }
    }


    if (cycle_start == -1) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;

    parent[cycle_start] = cycle_start;
    dfs(cycle_start, 0);

    cout << cycle_end << endl;

    vector<int> cycle;
    cycle.pb(cycle_start);
    while (parent[cycle_end] != cycle_end) {
        cycle.pb(cycle_end);
        cycle_end = parent[cycle_end];
    }
    cycle.pb(cycle_start);

    for (int i = cycle.size() - 1; i >= 0; i--) {
        cout << cycle[i] << " ";
    }

    cout << endl;


    return 0;
}