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

int n, m, component_size[N], p[N];
vector<tuple<int, int, int>> v;

int parent(int node) {
    return ((p[node] == node) ? node : parent(p[node]));
}

bool merge(int u, int v) {
    u = parent(u);
    v = parent(v);

    if (u == v) return false;
    if (component_size[u] < component_size[v]) {
        swap(u, v);
    }

    p[v] = u;
    component_size[u] += component_size[v];

    return true;
}

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        v.pb({ c, a, b });
    }

    for (int i = 0; i < N; i++) {
        p[i] = i;
        component_size[i] = 1;
    }

    sort(v.begin(), v.end());

    int ans = 0;
    for (auto [c, u, v] : v) {
        if (merge(u, v)) {
            ans += c;
        }
    }

    if (component_size[parent(1)] != n) {
        cout << "IMPOSSIBLE" << endl;

    }
    else {
        cout << ans << endl;
    }



    return 0;
}
