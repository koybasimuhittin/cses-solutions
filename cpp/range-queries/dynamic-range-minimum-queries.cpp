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

int n, m, q, a, b, arr[N], seg[4 * N];

void build(int v, int tl, int tr) {
    if (tl == tr) {
        seg[v] = arr[tl];
        return;
    }
    int tm = (tl + tr) / 2;

    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    seg[v] = min(seg[v * 2], seg[v * 2 + 1]);
}

void update(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        seg[v] = arr[tl];
        return;
    }

    int tm = (tl + tr) / 2;

    if (tm >= pos) {
        update(v * 2, tl, tm, pos);
    } else {
        update(v * 2 + 1, tm + 1, tr, pos);
    }
    seg[v] = min(seg[v * 2], seg[v * 2 + 1]);
}

int get(int v, int tl, int tr, int l, int r) {
    if (l > r) {
        return INT_MAX;
    }
    if (l == tl && r == tr) {
        return seg[v];
    }

    int tm = (tl + tr) / 2;
    return min(get(v * 2, tl, tm, l, min(r, tm)),
               get(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r));
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

    build(1, 0, n - 1);

    while (m--) {
        cin >> q >> a >> b;
        if (q == 1) {
            arr[a - 1] = b;
            update(1, 0, n - 1, a - 1);
        } else {
            cout << get(1, 0, n - 1, a - 1, b - 1) << endl;
        }
    }
}
