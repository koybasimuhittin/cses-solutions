#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define f1 first
#define s2 second
#define pb push_back
#define mp make_pair
#define int long long

const int N = 1000 + 5;

int n, m, k;
int capacity[N][N];
int parent[N];
vector<int> graph[N];
vector<pair<int, int>> adj;

int calc_flow(int s, int t) {
    for (int i = 0; i <= n + m + 1; i++) parent[i] = -1;
    queue<pair<int, int>> q;
    parent[s] = s;
    q.push({ s, (int)1e9 });
    int flow = 0;

    while (!q.empty()) {
        auto [u, f] = q.front(); q.pop();
        if (u == t) { flow = f; break; }
        for (int v : graph[u]) {
            if (capacity[u][v] > 0 && parent[v] == -1) {
                parent[v] = u;
                q.push({ v, min(f, capacity[u][v]) });
            }
        }
    }

    int cur = t;
    while (cur != parent[cur]) {
        int p = parent[cur];
        capacity[p][cur] -= flow;
        capacity[cur][p] += flow;
        cur = p;
    }
    return flow;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        capacity[0][i] = 1;
        graph[0].pb(i);
        graph[i].pb(0);
    }
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        adj.pb({ a, b });
        capacity[a][n + b] = 1;
        graph[a].pb(n + b);
        graph[n + b].pb(a);
    }
    for (int j = 1; j <= m; j++) {
        capacity[n + j][n + m + 1] = 1;
        graph[n + j].pb(n + m + 1);
        graph[n + m + 1].pb(n + j);
    }

    int flow = 0;
    while (true) {
        int f = calc_flow(0, n + m + 1);
        if (f == 0) break;
        flow += f;
    }

    cout << flow << endl;
    int cnt = 0;
    for (auto& p : adj) {
        int a = p.f1, b = p.s2;
        if (capacity[a][n + b] == 0 && cnt++ < flow) {
            cout << a << " " << b << endl;
        }
    }
    return 0;
}
