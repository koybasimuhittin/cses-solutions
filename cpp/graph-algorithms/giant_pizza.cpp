#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define f1 first
#define s2 second
#define pb push_back
#define mp make_pair
#define int long long
#define fri(a) freopen(a, "r", stdin);
#define fro(a) freopen(a, "w", stdout);
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;

int n, m, comp[N];
vector<int> adj[N], adj_t[N], order;
bool visited[N], res[N];

void add_edges(int a, int b, bool na, bool nb) {
    a = (a << 1) ^ na;
    b = (b << 1) ^ nb;

    adj[a ^ 1].pb(b);
    adj[b ^ 1].pb(a);
    adj_t[b].pb(a ^ 1);
    adj_t[a].pb(b ^ 1);
}

void dfs1(int node) {
    visited[node] = true;

    for (auto& child : adj[node]) {
        if (visited[child]) continue;
        dfs1(child);
    }
    order.pb(node);
}

void dfs2(int node, int c) {
    comp[node] = c;
    for (auto& child : adj_t[node]) {
        if (comp[child] != -1) continue;
        dfs2(child, c);
    }
}

int32_t main() {
    // fri("in.txt");
    // fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n;

    int a, b;
    char na, nb;

    for (int i = 0; i < m; i++) {
        cin >> na >> a >> nb >> b;
        add_edges(a, b, na == '-', nb == '-');
    }

    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= 2 * n; i++) {
        if (!visited[i]) {
            dfs1(i);
        }
    }

    int cnt = 0;
    memset(comp, -1, sizeof(comp));
    reverse(order.begin(), order.end());
    for (auto& node : order) {
        if (comp[node] == -1) {
            dfs2(node, cnt++);
        }
    }

    bool flag = true;
    for (int i = 1; i <= n; i++) {
        if (comp[(i << 1)] == comp[(i << 1) ^ 1]) {
            flag = false;
            break;
        }
        res[i] = comp[(i << 1)] > comp[(i << 1) ^ 1];
    }

    if (flag) {
        for (int i = 1; i <= n; i++) {
            cout << (res[i] ? '+' : '-') << " ";
        }
        cout << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
