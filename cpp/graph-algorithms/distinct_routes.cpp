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

int n, m, parent[N];
set<int> adj[N];

void dfs(int node, int p) {
    parent[node] = p;

    for (auto child : adj[node]) {
        if (parent[child] == -1 && child != p) {
            dfs(child, node);
        }
    }
}

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].insert(b);
    }
    vector<vector<int>> res;
    while (true) {
        for (int i = 1; i <= n; i++)parent[i] = -1;
        dfs(1, 0);
        if (parent[n] == -1)break;

        int curr = n;
        res.pb(vector<int>());
        while (curr != 0) {
            res.back().pb(curr);
            adj[parent[curr]].erase(curr);
            curr = parent[curr];
        }
    }

    cout << res.size() << endl;
    for (auto v : res) {
        cout << v.size() << endl;
        for (int i = 0; i < v.size(); i++) {
            cout << v[v.size() - i - 1] << " ";
        }
        cout << endl;
    }

    return 0;
}
