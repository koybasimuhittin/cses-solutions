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

int n, m, capacity[N][N];
vector<int> adj[N];
vector<int> parent(N);


int bfs(int sink, int target) {
    parent.assign(n + 1, -1);
    parent[sink] = -2;

    queue<pair<int, int>> q;
    q.push({ sink, LLONG_MAX });

    while (!q.empty()) {
        auto [node, flow] = q.front();
        q.pop();

        if (node == target) {
            return flow;
        }

        for (auto next : adj[node]) {
            if (parent[next] == -1 && capacity[node][next]) {
                parent[next] = node;
                int new_flow = min(flow, capacity[node][next]);
                q.push({ next, new_flow });
            }
        }
    }

    return 0;
}

int calc_flow(int sink, int target) {
    int flow = 0;

    int new_flow;
    while ((new_flow = bfs(sink, target))) {
        fflush(stdout);
        flow += new_flow;

        int cur = target;

        while (cur != sink) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int a, b, c;

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        adj[a].pb(b);
        adj[b].pb(a);
        capacity[a][b] += c;
    }

    cout << calc_flow(1, n) << endl;


    return 0;
}
