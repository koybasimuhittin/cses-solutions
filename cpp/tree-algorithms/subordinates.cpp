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
const int N = 2e5 + 5;

int n, subordinates[N];
vector<int> adj[N];

void solve(int u) {
    for (auto v : adj[u]) {
        solve(v);
        subordinates[u] += subordinates[v] + 1;
    }
}

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    int a;
    for (int i = 2; i <= n; i++) {
        cin >> a;
        adj[a].pb(i);
    }

    solve(1);

    for (int i = 1; i <= n; i++) {
        cout << subordinates[i] << " ";
    }
    cout << endl;




    return 0;
}
