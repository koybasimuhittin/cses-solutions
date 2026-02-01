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
const int N = 5e3 + 5;
const int INF = 1e18;

int n, m, pref[N];
vector<pair<int, int>> adj[N];

bool flag = true;

void dfs(int u, int val) {
    pref[u] = val;
    for (auto& [v, w] : adj[u]) {
        if (pref[v] == INF) {
            dfs(v, val + w);
        }
        else if (pref[v] != val + w) {
            flag = false;
            return;
        }
        if (!flag) return;
    }
}

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    int l, r, x;
    for (int i = 0; i < m; i++) {
        cin >> l >> r >> x;
        l--;
        adj[l].pb({ r, x });
        adj[r].pb({ l, -x });
    }

    for (int i = 0; i <= n; i++) {
        pref[i] = INF;
    }

    for (int i = 0; i <= n; i++) {
        if (pref[i] == INF) {
            dfs(i, 0);
        }
    }

    if (flag) {
        cout << "YES" << endl;
        for (int i = 1; i <= n; i++) {
            cout << pref[i] - pref[i - 1] << " ";
        }
    }
    else cout << "NO" << endl;



    return 0;
}
