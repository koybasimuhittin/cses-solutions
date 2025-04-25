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

int n, m, ans;
vector<int> adj[N];

map<int, int> solve(int node, int parent, int depth) {
    map<int, int> cnt, child_cnt;

    cnt[depth]++;

    for (auto child : adj[node]) {
        if (child == parent)continue;
        child_cnt = solve(child, node, depth + 1);

        if (cnt.size() < child_cnt.size()) {
            swap(cnt, child_cnt);
        }

        for (auto [d, c] : child_cnt) {
            if (d - depth <= m) {
                ans += c * cnt[m - d + 2 * depth];
            }
        }

        for (auto [d, c] : child_cnt) {
            cnt[d] += c;
        }
    }

    return cnt;

}

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int a, b;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    solve(1, 0, 0);

    cout << ans << endl;


    return 0;
}