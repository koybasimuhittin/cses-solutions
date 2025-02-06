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

int n, m, t, ans[N], cnt;
vector<int> adj[N], reverse_adj[N], order;
bool visited[N];

void find_order(int u) {
    visited[u] = true;

    for (auto v : adj[u]) {
        if (!visited[v]) {
            find_order(v);
        }
    }

    order.pb(u);
}

void dfs(int u) {
    visited[u] = true;
    ans[u] = cnt;

    for (auto v : reverse_adj[u]) {
        if (!visited[v]) {
            dfs(v);
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
        reverse_adj[b].pb(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            find_order(i);
        }
    }

    reverse(order.begin(), order.end());
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < n; i++) {
        if (!visited[order[i]]) {
            cnt++;
            dfs(order[i]);
        }
    }

    cout << cnt << endl;
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;



    return 0;
}
