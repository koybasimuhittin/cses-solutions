#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define f1 first
#define s2 second
#define pb push_back
#define mp make_pair
#define fri(a) freopen(a,"r",stdin);
#define fro(a) freopen(a,"w",stdout);
const int MOD = 1e9 + 7;
const int N = 5e4 + 5;

int n, m;
vector<int> adj[N];
bitset<N> dp[N];
bool visited[N];

void solve(int node) {
    visited[node] = true;
    for (int neighbour : adj[node]) {
        if (!visited[neighbour]) {
            solve(neighbour);
        }
        dp[node] = dp[node] | dp[neighbour];
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
    }

    for (int i = 1; i <= n; i++) {
        dp[i].set(i - 1);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            solve(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << dp[i].count() << " ";
    }
    cout << endl;





    return 0;
}
