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
const int N = 5e2 + 5;

int n, m, capacity[N][N], parent[N];
vector<int> adj[N];

int calc_flow(int s, int t) {
    for (int i = 0; i < n; i++) {
        parent[i] = -1;
    }
    queue<pair<int, int>> q;
    parent[s] = s;
    q.push({ s, 1e9 });

    int f = 0;

    while (!q.empty()) {
        auto [node, flow] = q.front();
        q.pop();

        if (node == t) {
            f = flow;
            break;
        }
        for (int i : adj[node]) {
            if (capacity[node][i] > 0 && parent[i] == -1) {
                parent[i] = node;
                q.push({ i, min(flow, capacity[node][i]) });
            }
        }
    }


    while (t != parent[t] && parent[t] != -1) {
        capacity[parent[t]][t] -= f;
        capacity[t][parent[t]] += f;

        t = parent[t];
    }

    return f;
}

void dfs(int node, int p) {
    parent[node] = p;

    for (auto nxt : adj[node]) {
        if (parent[nxt] == -1 && capacity[node][nxt]) {
            dfs(nxt, node);
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
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
        capacity[a][b]++;
        capacity[b][a]++;
    }

    int f;

    while (true) {
        f = calc_flow(0, n - 1);
        if (f <= 0)break;
    }

    for (int i = 0; i < n; i++) {
        parent[i] = -1;
    }
    dfs(0, 0);

    vector<pair<int, int>> cut;

    for (int node = 0; node < n; node++) {
        for (auto nxt : adj[node]) {
            if (parent[node] != -1 && parent[nxt] == -1) {
                cut.pb({ node, nxt });
            }
        }
    }
    cout << cut.size() << endl;


    return 0;
}
