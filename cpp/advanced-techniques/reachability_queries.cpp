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
const int N = 5e4 + 5;

int n, m, q, scc_index[N], scc_count;
bitset<N> can_reach[N];
vector<int> adj[N], reverse_adj[N], scc_adj[N], topological_order;
bool visited[N];

void find_order(int u) {
    visited[u] = true;
    for (const int v : adj[u]) {
        if (!visited[v]) {
            find_order(v);
        }
    }
    topological_order.pb(u);
}

void build_component(int u) {
    visited[u] = true;
    scc_index[u] = scc_count;

    for (auto v : reverse_adj[u]) {
        if (!visited[v]) {
            build_component(v);
        }
    }
}

void calc_dp(int u) {
    can_reach[u].set(u);
    visited[u] = true;
    for (auto v : scc_adj[u]) {
        if (!visited[v]) {
            calc_dp(v);
        }
        can_reach[u] |= can_reach[v];
    }
}



int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> q;

    for (int i = 1; i <= n; i++) {
        can_reach[i].set(i);
    }

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        reverse_adj[b].pb(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            find_order(i);
        }
    }

    reverse(topological_order.begin(), topological_order.end());
    memset(visited, false, sizeof(visited));

    for (auto u : topological_order) {
        if (!visited[u]) {
            build_component(u);
            scc_count++;
        }
    }

    for (int u = 1; u <= n; u++) {
        for (auto v : adj[u]) {
            if (scc_index[u] != scc_index[v]) {
                scc_adj[scc_index[u]].pb(scc_index[v]);
            }
        }
    }

    memset(visited, false, sizeof(visited));
    for (int i = 0; i < scc_count; i++) {
        if (!visited[i]) {
            calc_dp(i);
        }
    }


    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        if (can_reach[scc_index[a]].test(scc_index[b])) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
