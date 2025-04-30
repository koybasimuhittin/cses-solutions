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

int n, m, indegree[N], outdegree[N];
vector<int> adj[N], eulerian_path;

void find_eulerian_path(int node) {
    while (outdegree[node] > 0) {
        outdegree[node]--;
        find_eulerian_path(adj[node][outdegree[node]]);
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
        adj[a].pb(b);
        outdegree[a]++;
        indegree[b]++;
    }

    for (int i = 1; i <= n; i++) {
        if (i == 1 && outdegree[i] - indegree[i] != 1) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
        else if (i == n && indegree[i] - outdegree[i] != 1) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
        else if (i != 1 && i != n && indegree[i] != outdegree[i]) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    find_eulerian_path(1);

    if (eulerian_path.size() != m + 1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    reverse(eulerian_path.begin(), eulerian_path.end());
    for (auto node : eulerian_path) {
        cout << node << " ";
    }
    cout << endl;


    return 0;
}
