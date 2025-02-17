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

int n, m, t, subtree_size[N], distance_to_all[N];
vector<int> adj[N];

void calc_subtree_size(int u, int p) {
    for (auto v : adj[u]) {
        if (v == p) continue;
        calc_subtree_size(v, u);
        subtree_size[u] += subtree_size[v];
    }
    subtree_size[u] += 1;
}

void calc_distance_from_one(int u, int p, int d) {
    distance_to_all[1] += d;
    for (auto v : adj[u]) {
        if (v == p) continue;
        calc_distance_from_one(v, u, d + 1);
    }
}

void calc_distance_for_all(int u, int p) {
    if (p != 0) {
        distance_to_all[u] = distance_to_all[p] + n - 2 * subtree_size[u];
    }

    for (auto v : adj[u]) {
        if (v == p) continue;
        calc_distance_for_all(v, u);
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

    calc_subtree_size(1, 0);
    calc_distance_from_one(1, 0, 0);
    calc_distance_for_all(1, 0);

    for (int i = 1; i <= n; i++) {
        cout << distance_to_all[i] << " ";
    }
    cout << endl;

    return 0;
}
