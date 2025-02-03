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

int n, m, parent[N];
vector<int> graph[N];

bool found = false;
int ending;

void dfs(int node, int p) {
    parent[node] = p;

    for (auto neighbour : graph[node]) {
        if (found) return;
        if (neighbour == p) continue;
        if (parent[neighbour] != 0) {
            ending = node;
            parent[neighbour] = neighbour;
            found = true;
        }
        if (found) return;

        dfs(neighbour, node);
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
        graph[a].pb(b);
        graph[b].pb(a);
    }

    for (int i = 1; i <= n && !found; i++) {
        if (parent[i] == 0) {
            dfs(i, i);
        }
    }

    if (found) {
        vector<int> ans;
        int temp = ending;

        while (parent[temp] != temp) {
            ans.pb(temp);
            temp = parent[temp];
        }

        ans.pb(temp);
        ans.pb(ending);

        cout << ans.size() << endl;

        for (auto e : ans) {
            cout << e << " ";
        }
        cout << endl;
    }

    else {
        cout << "IMPOSSIBLE" << endl;
    }



    return 0;
}
