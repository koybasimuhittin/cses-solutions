#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define f1 first
#define s2 second
#define pb push_back
#define mp make_pair
#define fri(a) freopen(a,"r",stdin);
#define fro(a) freopen(a,"w",stdout);
const int MOD = 1e9 + 7;
const int N = 5e2 + 5;

int n, m, capacity[N][N], initial_capacity[N][N];
vector<int> adj[N];

int flow(int s, int t) {
    vector<int> p(n + 1, -1);
    p[s] = -2;

    queue<int> q;
    q.push(s);

    while (!q.empty() && p[t] == -1) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (p[v] == -1 && capacity[u][v] > 0) {
                p[v] = u;
                q.push(v);
                if (v == t) break;
            }
        }
    }
    if (p[t] == -1) return 0;

    int cur = t;
    while (cur != s) {
        int prev = p[cur];
        capacity[prev][cur] -= 1;
        capacity[cur][prev] += 1;
        cur = prev;
    }
    return 1;
}


bool dfs(int u, int t, vector<int>& path) {
    if (u == t) {
        cout << path.size() << endl;
        for (auto& v : path) {
            cout << v << " ";
        }
        cout << endl;
        return true;
    }

    bool flag = false;

    for (auto& v : adj[u]) {
        if (v != u && initial_capacity[u][v] && capacity[v][u]) {
            path.push_back(v);
            initial_capacity[u][v]--;
            capacity[v][u]--;
            flag |= dfs(v, t, path);
            path.pop_back();
            if (flag) return flag;
        }
    }

    return false;
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
        capacity[a][b]++;
        initial_capacity[a][b]++;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int res = 0;
    int f;
    while (f = flow(1, n)) {
        res += f;
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << initial_capacity[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << capacity[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    cout << res << endl;
    vector<int> path = { 1 };
    while (dfs(1, n, path)) {}

    return 0;
}
