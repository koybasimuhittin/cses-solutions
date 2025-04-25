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

int n, q, seg[8 * N], in[N], out[N], timer = 0, arr[N], values[2 * N];
vector<int> adj[N];

void dfs(int node, int parent) {
    in[node] = timer++;

    for (auto child : adj[node]) {
        if (child == parent) {
            continue;
        }
        dfs(child, node);
    }

    out[node] = timer++;
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        seg[v] = values[tl];
    }
    else {
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);

        seg[v] = seg[v * 2] + seg[v * 2 + 1];
    }
}

void update(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        seg[v] = values[tl];
    }
    else {
        int tm = (tl + tr) / 2;
        if (pos <= tm) {
            update(v * 2, tl, tm, pos);
        }
        else {
            update(v * 2 + 1, tm + 1, tr, pos);
        }

        seg[v] = seg[v * 2] + seg[v * 2 + 1];
    }
}

int get(int v, int tl, int tr, int l, int r) {
    if (l > r) {
        return 0;
    }

    if (l == tl && r == tr) {
        return seg[v];
    }

    int tm = (tl + tr) / 2;

    return get(v * 2, tl, tm, l, min(r, tm)) + get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;


    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int a, b, c;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        values[in[i]] = arr[i];
        values[out[i]] = arr[i];
    }

    build(1, 0, 2 * n - 1);

    for (int i = 0; i < q; i++) {
        cin >> a;
        if (a == 1) {
            cin >> b >> c;
            values[in[b]] = c;
            values[out[b]] = c;

            update(1, 0, 2 * n - 1, in[b]);
            update(1, 0, 2 * n - 1, out[b]);
        }
        else {
            cin >> b;

            cout << get(1, 0, 2 * n - 1, in[b], out[b]) / 2 << endl;
        }
    }







    return 0;
}
