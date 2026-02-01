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

int n, m, k, dist[N][2], shop[N][2];
vector<int> adj[N];
set<int> anime_shops;
bool visited[N];

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    queue<pair<int, int>> q;
    memset(dist, -1, sizeof(dist));

    int x;
    for (int i = 0; i < k; i++) {
        cin >> x;
        q.push({ x, 0 });
        dist[x][0] = 0;
        shop[x][0] = x;
    }

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    while (!q.empty()) {
        auto [u, t] = q.front();
        q.pop();

        for (auto v : adj[u]) {
            if (t == 0) {
                if (dist[v][0] != -1) {
                    if (dist[v][1] == -1 && shop[v][0] != shop[u][0]) {
                        dist[v][1] = dist[u][0] + 1;
                        shop[v][1] = shop[u][0];
                        q.push({ v, 1 });
                    }
                }
                else {
                    dist[v][0] = dist[u][0] + 1;
                    shop[v][0] = shop[u][0];
                    q.push({ v, 0 });
                }
            }
            else {
                if (dist[v][1] == -1) {
                    dist[v][1] = dist[u][1] + 1;
                    shop[v][1] = shop[u][1];
                    q.push({ v, 1 });
                }
            }
        }
    }

    for (int i = 1;i <= n; i++) {
        if (shop[i][0] == i) {
            cout << dist[i][1] << " ";
        }
        else {
            cout << dist[i][0] << " ";
        }
    }


    return 0;
}
