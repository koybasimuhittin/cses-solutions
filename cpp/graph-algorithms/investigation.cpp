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
const int INF = 1e14 + 5;

int n, m, dist_to_start[N], dist_to_end[N], min_edge, max_edge, dp[N][3];
vector<pair<int, int>> adj[N];
vector<pair<int, int>> adj_reversed[N];

void calc_min_dist(int start, int* dist, vector<pair<int, int>>* adj) {
    for (int i = 0; i < N; i++) {
        dist[i] = INF;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, start });
    dist[start] = 0;

    while (!pq.empty()) {
        auto [c, u] = pq.top();
        pq.pop();

        if (dist[u] < c && u != start) {
            continue;
        }

        for (auto [v, w] : adj[u]) {
            if (c + w < dist[v]) {
                dist[v] = c + w;
                pq.push({ dist[v], v });
            }
        }
    }
}

void solve(int u, int p) {
    if (u == n) {
        dp[u][0] = 1;
        dp[u][1] = dp[u][2] = 0;
        return;
    }

    if (dp[u][0] != -1) return;

    dp[u][0] = 0;
    dp[u][1] = INT_MAX;
    dp[u][2] = INT_MIN;

    for (auto [v, w] : adj[u]) {
        if (v == p) continue;

        if (dist_to_start[u] + dist_to_end[v] + w == dist_to_start[n]) {
            solve(v, u);
            dp[u][0] += dp[v][0];
            dp[u][1] = min(dp[u][1], dp[v][1] + 1);
            dp[u][2] = max(dp[u][2], dp[v][2] + 1);
            dp[u][0] %= MOD;
        }
    }

}

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        adj[a].pb({ b, c });
        adj_reversed[b].pb({ a, c });
    }

    memset(dp, -1, sizeof(dp));
    min_edge = INT_MAX;
    max_edge = INT_MIN;

    calc_min_dist(1, dist_to_start, adj);
    calc_min_dist(n, dist_to_end, adj_reversed);

    solve(1, 1);

    cout << dist_to_start[n] << " " << dp[1][0] << " " << dp[1][1] << " " << dp[1][2] << endl;


    return 0;
}
