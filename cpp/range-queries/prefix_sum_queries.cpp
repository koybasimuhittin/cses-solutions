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

int n, m, t, arr[N];
pair<int, int> seg[4 * N];

void build(int v, int tl, int tr) {
    if (tl == tr) {
        seg[v].s2 = arr[tl];
        seg[v].f1 = max(0ll, arr[tl]);
        return;
    }

    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);

    seg[v].f1 = max(seg[v * 2].s2 + seg[v * 2 + 1].f1, seg[v * 2].f1);
    seg[v].s2 = seg[v * 2].s2 + seg[v * 2 + 1].s2;
}

void update(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        seg[v].s2 = arr[tl];
        seg[v].f1 = max(0ll, arr[tl]);
        return;
    }

    int tm = (tl + tr) / 2;

    if (pos <= tm) {
        update(v * 2, tl, tm, pos);
    } else {
        update(v * 2 + 1, tm + 1, tr, pos);
    }

    seg[v].f1 = max(seg[v * 2].s2 + seg[v * 2 + 1].f1, seg[v * 2].f1);
    seg[v].s2 = seg[v * 2].s2 + seg[v * 2 + 1].s2;
}

pair<int, int> get(int v, int tl, int tr, int l, int r) {
    // cout << v << " " << tl << " " << tr << " " << l << " " << r << endl;
    // fflush(stdout);
    if (l > r) {
        return {0, 0};
    }

    if (tl == l && tr == r) {
        return seg[v];
    }

    int tm = (tl + tr) / 2;
    pair<int, int> left_seg = get(v * 2, tl, tm, l, min(tm, r));
    pair<int, int> right_seg = get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);

    return {max(left_seg.s2 + right_seg.f1, left_seg.f1),
            left_seg.s2 + right_seg.s2};
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

    int q, a, b;
    while (m--) {
        cin >> q >> a >> b;

        if (q == 1) {
            arr[a - 1] = b;
            update(1, 0, n - 1, a - 1);
        } else {
            cout << get(1, 0, n - 1, a - 1, b - 1).f1 << endl;
        }
    }

    return 0;
}
