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

int n, m, low[N], tin[N], timer;
vector<int> adj[N];
vector<pair<int, int>> bridges;
bool visited[N];

void dfs(int node, int parent) {
    visited[node] = true;
    low[node] = tin[node] = timer++;

    bool parent_skipped = false;
    for (auto& to : adj[node]) {
        if (to == parent && !parent_skipped) {
            parent_skipped = true;
            continue;
        }

        if (visited[to]) {
            low[node] = min(low[node], tin[to]);
        }
        else {
            dfs(to, node);
            low[node] = min(low[node], low[to]);
            if (low[to] > tin[node])
                bridges.pb({ node, to });
        }
    }
}

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(1, -1);

    cout << bridges.size() << endl;
    for (auto& [a, b] : bridges) {
        cout << a << " " << b << endl;
    }

    return 0;
}
