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

int n, m;
vector<int> graph[N];

vector<int> bfs() {
    vector<int> ans;
    vector<bool> visited(n + 1, false);
    vector<int> parent(n + 1);

    queue<int> q;
    q.push(1);
    visited[1] = true;
    parent[1] = 1;
    parent[n] = n;

    while (!q.empty()) {
        int node = q.front();
        q.pop();


        if (node == n) break;


        for (auto& neighbour : graph[node]) {
            if (!visited[neighbour]) {
                q.push(neighbour);
                parent[neighbour] = node;
                visited[neighbour] = true;
            }
        }
    }

    while (n != parent[n]) {
        ans.pb(n);
        n = parent[n];
    }

    ans.pb(1);

    return ans;
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
        graph[a].pb(b);
        graph[b].pb(a);
    }

    vector<int> route = bfs();

    if (route.size() == 1) {
        cout << "IMPOSSIBLE" << endl;
    }
    else {
        reverse(route.begin(), route.end());
        cout << route.size() << endl;
        for (auto e : route) {
            cout << e << " ";
        }
        cout << endl;
    }


    return 0;
}
