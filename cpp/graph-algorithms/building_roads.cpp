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
bool visited[N];

void dfs(int node) {
    visited[node] = true;

    for (auto& child : graph[node]) {
        if (!visited[child]) dfs(child);
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

    vector<int> roots;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            roots.pb(i);
            dfs(i);
        }
    }

    cout << roots.size() - 1 << endl;

    for (int i = 1; i < roots.size(); i++) {
        cout << roots[0] << " " << roots[i] << endl;
    }




    return 0;
}
