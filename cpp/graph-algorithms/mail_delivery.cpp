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

int n, m, ongoing[N];
unordered_set<int> adj[N];
vector<int> eulerian_path;

void find_eulerian_path(int node) {
    while (adj[node].size() > 0) {
        int nxt = *adj[node].begin();
        adj[node].erase(nxt);
        adj[nxt].erase(node);
        find_eulerian_path(nxt);
    }
    eulerian_path.pb(node);
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
        adj[a].insert(b);
        adj[b].insert(a);
        ongoing[a]++;
        ongoing[b]++;
    }

    if (ongoing[1] == 0) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        if (ongoing[i] % 2) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    find_eulerian_path(1);

    if (eulerian_path.size() != m + 1) {
        cout << "IMPOSSIBLE" << endl;
    }
    else {
        for (auto node : eulerian_path) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
