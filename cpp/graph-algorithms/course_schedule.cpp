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

int n, m, indegree[N];
vector<int> order, adj[N];

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
        indegree[b] += 1;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        order.pb(u);

        for (auto v : adj[u]) {
            if (indegree[v] != 0) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
            else {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }

    if (order.size() != n) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    for (auto v : order) {
        cout << v << " ";
    }
    cout << endl;







    return 0;
}
