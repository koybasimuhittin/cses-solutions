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

int n, m, dist[N], child[N];
vector<int> adj[N];
bool visited[N];

void dfs(int node) {
    visited[node] = true;

    if (node == n) {
        dist[n] = 1;
        return;
    }

    for (auto neighbour : adj[node]) {
        if (!visited[neighbour]) {
            dfs(neighbour);
        }
    }

    for (auto neighbour : adj[node]) {
        if (dist[neighbour] + 1 > dist[node]) {
            dist[node] = dist[neighbour] + 1;
            child[node] = neighbour;
        }
    }
    if (dist[node] == 0) {
        dist[node] = INT_MIN;
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
    }
    dfs(1);

    if (dist[n] == 0) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    cout << dist[1] << endl;
    int curr = 1;
    while (curr != n) {
        cout << curr << " ";
        curr = child[curr];
    }
    cout << n << " " << endl;


    return 0;
}
