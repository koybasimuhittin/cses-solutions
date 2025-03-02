#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define f1 first
#define s2 second
#define pb push_back
#define mp make_pair
#define int long long
#define fri(a) freopen(a, "r", stdin);
#define fro(a) freopen(a, "w", stdout);
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;

int n, color[N], res[N];
vector<int> adj[N];

set<int> dfs(int u, int p) {
    set<int> cnt;
    set<int> temp_cnt;

    for (auto& v : adj[u]) {
        if (v == p) continue;
        temp_cnt = dfs(v, u);
        if (temp_cnt.size() > cnt.size()) {
            swap(cnt, temp_cnt);
        }

        for (auto& i : temp_cnt) {
            cnt.insert(i);
        }
    }

    cnt.insert(color[u]);
    res[u] = cnt.size();

    return cnt;
}

int32_t main() {
    // fri("in.txt");
    // fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> color[i];
    }

    int a, b;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(1, -1);

    for (int i = 1; i <= n; i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
