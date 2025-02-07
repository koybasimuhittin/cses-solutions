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
const int M = 5e3 + 5;
const int INF = 1e18;

typedef struct Edge {
    int a, b, c;
} Edge;

int n, m, dist[N], is_in_cycle[N];
vector<Edge> e(M);
vector<int> adj[N];
bool visited[N];

void dfs(int u) {
    visited[u] = true;

    for (auto v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < N; i++) {
        dist[i] = INF;
    }
    dist[1] = 0;

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> e[i].a >> e[i].b >> e[i].c;
        e[i].c = -1 * e[i].c;
        adj[e[i].b].pb(e[i].a);
    }

    for (int i = 0; i < n - 1; i++) {
        for (auto& edge : e) {
            if (dist[edge.a] < INF) {
                if (dist[edge.b] > dist[edge.a] + edge.c) {
                    dist[edge.b] = dist[edge.a] + edge.c;
                }
            }
        }
    }

    for (auto& edge : e) {
        if (dist[edge.a] < INF) {
            if (dist[edge.b] > dist[edge.a] + edge.c) {
                is_in_cycle[edge.b] = true;
                is_in_cycle[edge.a] = true;
            }
        }
    }


    dfs(n);

    for (int i = 1; i <= n; i++) {
        if (visited[i] && is_in_cycle[i]) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << -1 * dist[n] << endl;

    return 0;
}