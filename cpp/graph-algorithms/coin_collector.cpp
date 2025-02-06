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
const int N = 1e5 + 5;

int n, m, component[N], coins[N], scc_coins[N], scc_count, dp[N];
vector<int> adj[N], reverse_adj[N], scc_adj[N], order;
bool visited[N];

void find_order(int u) {
    visited[u] = true;

    for (auto v : adj[u]) {
        if (!visited[v]) {
            find_order(v);
        }
    }

    order.pb(u);
}

void dfs(int u) {
    visited[u] = true;
    component[u] = scc_count;
    scc_coins[scc_count] += coins[u];

    for (auto v : reverse_adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int solve(int u) {
    if (dp[u] != -1)return dp[u];

    dp[u] = 0;

    for (auto v : scc_adj[u]) {
        dp[u] = max(dp[u], solve(v));
    }

    dp[u] += scc_coins[u];

    return dp[u];
}



int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> coins[i];
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

    memset(visited, false, sizeof(visited));
    reverse(order.begin(), order.end());

    for (int i = 0; i < n; i++) {
        if (!visited[order[i]]) {
            scc_count++;
            dfs(order[i]);
        }
    }


    for (int u = 1; u <= n; u++) {
        for (auto v : adj[u]) {
            if (component[u] != component[v]) {
                scc_adj[component[u]].pb(component[v]);
            }
        }
    }

    memset(dp, -1, sizeof(dp));


    int ans = 0;
    for (int i = 1; i <= scc_count; i++) {
        if (dp[i] == -1) {
            ans = max(ans, solve(i));
        }
    }

    cout << ans << endl;


    return 0;
}
