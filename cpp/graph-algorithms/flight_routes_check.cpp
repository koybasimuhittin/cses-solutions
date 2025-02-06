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
vector<int> adj[N], reverse_adj[N];
bool visited[N], reverse_visited[N];

void traverse(int u) {
    visited[u] = true;

    for (auto v : adj[u]) {
        if (!visited[v]) {
            traverse(v);
        }
    }
}
void reverse_traverse(int u) {
    reverse_visited[u] = true;
    for (auto v : reverse_adj[u]) {
        if (!reverse_visited[v]) {
            reverse_traverse(v);
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

    traverse(1);
    reverse_traverse(1);

    int u, v;
    u = v = -1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cout << "NO" << endl;
            cout << 1 << " " << i << endl;
            return 0;
        }
        if (!reverse_visited[i]) {
            cout << "NO" << endl;
            cout << i << " " << 1 << endl;
            return 0;
        }

    }
    cout << "YES" << endl;
    return 0;
}
