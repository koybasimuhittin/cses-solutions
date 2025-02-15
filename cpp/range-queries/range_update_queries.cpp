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

int n, m, t, arr[N], lazy[4 * N];

void update(int v, int tl, int tr, int l, int r, int u) {
    if (l > r) return;
    if (tl == l && tr == r) {
        lazy[v] += u;
        return;
    }

    int tm = (tl + tr) / 2;

    lazy[2 * v] += lazy[v];
    lazy[2 * v + 1] += lazy[v];

    lazy[v] = 0;

    update(v * 2, tl, tm, l, min(r, tm), u);
    update(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r, u);
}

int get(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        return arr[tl] + lazy[v];
    }

    int tm = (tl + tr) / 2;

    lazy[2 * v] += lazy[v];
    lazy[2 * v + 1] += lazy[v];

    lazy[v] = 0;

    if (pos <= tm) {
        return get(v * 2, tl, tm, pos);
    }
    return get(v * 2 + 1, tm + 1, tr, pos);
}

int32_t main() {
    // fri("in.txt");
    // fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int q;
    while (m--) {
        cin >> q;
        if (q == 1) {
            int l, r, u;
            cin >> l >> r >> u;
            update(1, 0, n - 1, l - 1, r - 1, u);
        } else {
            int pos;
            cin >> pos;
            cout << get(1, 0, n - 1, pos - 1) << endl;
        }
    }

    return 0;
}
