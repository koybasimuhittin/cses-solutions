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
const int M = 30;

int n, m, input[N], color[N], depth[N], parent[N], cycle_parent[N], cycle_size[N], cycle_end, cycle_start, current_color = 1;
bool is_in_cycle[N], visited[N];
vector<int> roots, adj[N];
int dp[N][M];

void find_cycle(int u, int p) {
    visited[u] = true;
    parent[u] = p;

    int v = input[u];
    adj[v].pb(u);

    if (!visited[v]) {
        find_cycle(v, u);
    }
    else {
        if (color[v] == 0) {
            cycle_end = u;
            cycle_start = v;
            color[v] = current_color;
        }
    }

    color[u] = color[v];
}

void dfs(int u, int p, int d) {
    depth[u] = d;
    cycle_parent[u] = p;

    for (auto v : adj[u]) {
        if (depth[v] == -1) {
            if (is_in_cycle[v]) {
                dfs(v, v, d + 1);
            }
            else {
                if (is_in_cycle[u]) {
                    dfs(v, p, d + 1);
                }
                else {
                    dfs(v, p, d + 1);
                }
            }
        }
    }
}

int get_nth_planet(int planet, int n) {
    if (n < 0) return -1;
    for (int i = 0; i < M; i++) {
        if (n & (1 << i)) {
            planet = dp[planet][i];
        }
    }

    return planet;
}

int calc_dist(int a, int b) {
    if (color[a] != color[b]) {
        return -1;
    }
    if (is_in_cycle[a] && is_in_cycle[b]) {
        if (depth[a] >= depth[b]) {
            return depth[a] - depth[b];
        }
        else {
            return cycle_size[color[a]] - (depth[b] - depth[a]);
        }
    }
    if (is_in_cycle[b]) {
        int curr = depth[a] - depth[cycle_parent[a]];
        a = cycle_parent[a];
        if (depth[a] >= depth[b]) {
            return depth[a] - depth[b] + curr;
        }
        else {
            return cycle_size[color[a]] - (depth[b] - depth[a]) + curr;
        }
    }

    if (!is_in_cycle[a]) {
        if (cycle_parent[a] != cycle_parent[b]) {
            return -1;
        }
        if (get_nth_planet(a, depth[a] - depth[b]) != b) {
            return -1;
        }
        return depth[a] - depth[b];
    }

    return -1;
}

int32_t main() {

    //fri("test_input.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> input[i];
        dp[i][0] = input[i];
    }

    for (int i = 1; i < M; i++) {
        for (int j = 1; j <= n; j++) {
            dp[j][i] = dp[dp[j][i - 1]][i - 1];
        }
    }

    memset(depth, -1, sizeof(depth));

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cycle_end = -1;
            cycle_start = -1;
            find_cycle(i, i);

            if (cycle_end != -1) {
                roots.pb(cycle_end);
                while (cycle_start != cycle_end) {
                    cycle_size[current_color]++;
                    is_in_cycle[cycle_end] = true;
                    cycle_end = parent[cycle_end];
                }
                cycle_size[current_color]++;
                is_in_cycle[cycle_end] = true;
                current_color += 1;
            }
        }
    }

    for (auto root : roots) {
        dfs(root, root, 0);
    }

    // for (int i = 1; i <= n; i++) {
    //     cout << i << " " << color[i] << " " << is_in_cycle[i] << " " << depth[i] << " " << cycle_parent[i] << endl;
    // }

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        cout << calc_dist(a, b) << endl;
    }



    return 0;
}