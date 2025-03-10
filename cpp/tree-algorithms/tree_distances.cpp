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

int n;
vector<int> adj[N];

void dfs(int u, int p, int dist[]) {
    if (p) dist[u] = dist[p] + 1;

    for (auto v : adj[u]) {
        if (v == p) continue;
        dfs(v, u, dist);
    }
}

int32_t main() {
    // fri("in.txt");
    // fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    int a, b;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    int dist1[N], dist2[N];
    dist1[1] = 0;

    dfs(1, 0, dist1);

    int node = 0;
    for (int i = 1; i <= n; i++) {
        if (dist1[i] > dist1[node]) {
            node = i;
        }
    }

    dist1[node] = 0;
    dfs(node, 0, dist1);

    node = 0;
    for (int i = 1; i <= n; i++) {
        if (dist1[i] > dist1[node]) {
            node = i;
        }
    }

    dist2[1] = 0;
    dfs(node, 0, dist2);

    for (int i = 1; i <= n; i++) {
        cout << max(dist1[i], dist2[i]) << " ";
    }
    cout << endl;

    return 0;
}
