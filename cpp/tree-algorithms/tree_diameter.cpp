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

int n, height[N];
vector<int> adj[N];

void dfs(int u, int p, int h) {
    height[u] = h;

    for (auto v : adj[u]) {
        if (v == p) continue;
        dfs(v, u, h + 1);
    }
}

int32_t main() {
    // fri("in.txt");
    // fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    int a, b;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(1, 0, 0);

    int node = 0;
    for (int i = 1; i <= n; i++) {
        if (height[i] > height[node]) {
            node = i;
        }
    }

    dfs(node, 0, 0);

    for (int i = 1; i <= n; i++) {
        if (height[i] > height[node]) {
            node = i;
        }
    }

    cout << height[node] << endl;

    return 0;
}
