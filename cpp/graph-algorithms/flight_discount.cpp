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

int n, m, dist[N][2];
vector<pair<int, int>> adj[N];

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int a, b, c;

    for (int i = 0; i < N; i++) {
        dist[i][0] = dist[i][1] = INF;
    }

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        adj[a].pb({ b, c });
    }

    priority_queue<tuple<int, int, bool>, vector<tuple<int, int, bool>>, greater<tuple<int, int, bool>>> pq;
    pq.push({ 0, 1, false });
    dist[0][0] = 0;

    while (!pq.empty()) {
        auto [d, u, used] = pq.top();
        pq.pop();

        if (dist[u][used] < d) {
            continue;
        }

        for (auto v : adj[u]) {
            if (d + v.s2 < dist[v.f1][used]) {
                dist[v.f1][used] = d + v.s2;
                pq.push({ dist[v.f1][used], v.f1, used });
            }

            if (!used && d + v.s2 / 2 < dist[v.f1][true]) {
                dist[v.f1][true] = d + v.s2 / 2;
                pq.push({ dist[v.f1][true], v.f1, true });
            }
        }
    }


    cout << dist[n][1] << endl;



    return 0;
}
