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
const int N = 2500 + 5;

int n, m, dist[2][N][N];
vector<int> adj[N];

void calc_dist(int start) {
    vector<int> parent(n + 1, -1);
    for (int i = 0; i < 2; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][start][j] = N;
        }
    }
    dist[0][start][start] = 0;
    parent[start] = start;

    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto child : adj[node]) {
            if (child == parent[node])continue;
            if (dist[0][start][child] == N) {
                dist[0][start][child] = dist[0][start][node] + 1;
                parent[child] = node;
                q.push(child);
            }
            else {
                dist[1][start][child] = min(dist[1][start][child], dist[0][start][node] + 1);
            }
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
        adj[a].pb(b);
        adj[b].pb(a);
    }

    for (int i = 1; i <= n; i++) {
        calc_dist(i);
    }

    int res = N;

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            res = min(res, dist[0][i][j] + dist[1][i][j]);
        }
    }

    if (res >= N) {
        cout << -1 << endl;
    }
    else cout << res << endl;


    return 0;
}
