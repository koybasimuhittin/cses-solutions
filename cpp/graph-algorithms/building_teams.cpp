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

int n, m, color[N];
vector<int> graph[N];

bool dfs(int node, int c) {
    color[node] = c;

    bool res = true;


    for (auto& neighbour : graph[node]) {
        if (color[neighbour] == c) {
            res = false;
        }

        if (color[neighbour] == 0) {
            res = res && dfs(neighbour, 3 - c);
        }
    }

    return res;
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

    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            if (!dfs(i, 1)) {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << color[i] << " ";
    }
    cout << endl;


    return 0;
}
