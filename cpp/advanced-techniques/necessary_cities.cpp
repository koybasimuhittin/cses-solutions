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
vector<int> adj[N], articulation_points;
bool visited[N];


void dfs(int node, int parent) {
    visited[node] = true;
    tin[node] = low[node] = timer++;

    int children = 0;
    for (auto& to : adj[node]) {
        if (to == parent) continue;
        if (visited[to])low[node] = min(low[node], tin[to]);
        else {
            dfs(to, node);
            low[node] = min(low[node], low[to]);
            if (low[to] >= tin[node] && parent != -1) {
                articulation_points.pb(node);
            }
            children++;
        }
    }
    if (parent == -1 && children > 1) {
        articulation_points.pb(node);
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
    sort(articulation_points.begin(), articulation_points.end());
    articulation_points.resize(distance(articulation_points.begin(), unique(articulation_points.begin(), articulation_points.end())));
    cout << articulation_points.size() << endl;
    for (auto& node : articulation_points) {
        cout << node << " ";
    }
    cout << endl;


    return 0;
}
