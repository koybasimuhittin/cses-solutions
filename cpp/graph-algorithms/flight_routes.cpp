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
const int INF = 1e14 + 5;

int n, m, k, dist[N][10];
vector<pair<int, int>> adj[N];

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;

    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        adj[a].pb({ b, c });
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 10; j++) {
            dist[i][j] = INF;
        }
    }

    for (int j = 0; j < 10; j++) {
        dist[0][j] = 0;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, 1 });

    while (!pq.empty()) {
        auto [c, u] = pq.top();
        pq.pop();

        bool flag = true;
        for (int i = 0; i < k; i++) {
            if (dist[u][i] >= c || u == 1) {
                flag = false;
            }
        }

        if (flag) continue;

        for (auto [v, w] : adj[u]) {
            int max_dist = 0;
            int max_dist_index = -1;

            for (int i = 0; i < k; i++) {
                if (dist[v][i] > max_dist) {
                    max_dist = dist[v][i];
                    max_dist_index = i;
                }
            }

            if (max_dist_index == -1) continue;
            if (max_dist > c + w) {
                dist[v][max_dist_index] = c + w;
                pq.push({ dist[v][max_dist_index], v });
            }
        }
    }

    sort(dist[n], dist[n] + 10);

    for (int i = 0; i < k; i++) {
        cout << dist[n][i] << " ";
    }
    cout << endl;


    return 0;
}
