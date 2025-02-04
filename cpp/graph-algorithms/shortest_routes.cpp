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

int n, m, dist[N];
vector<pair<int, int>> graph[N];

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        graph[a].pb({ b, c });
    }

    for (int i = 2; i <= n; i++)dist[i] = INF;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[1] = 0;
    pq.push({ 0, 1 });

    while (!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();

        if (dist[node] < d) {
            continue;
        }

        for (auto edge : graph[node]) {
            if (d + edge.s2 < dist[edge.f1]) {
                dist[edge.f1] = d + edge.s2;
                pq.push({ dist[edge.f1], edge.f1 });
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }

    cout << endl;

    return 0;
}
