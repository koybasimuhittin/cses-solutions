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

int n, m, arr[N], seg[4 * N], lazy1[4 * N], lazy2[4 * N];

void build(int v, int tl, int tr) {
    if (tl == tr) {
        seg[v] = arr[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        seg[v] = seg[v * 2] + seg[v * 2 + 1];
    }
}

void push(int v, int tl, int tr) {
    int tm = (tl + tr) / 2;
    if (lazy2[v] != 0) {
        seg[v * 2] = (tm - tl + 1) * lazy2[v];
        seg[v * 2 + 1] = (tr - tm) * lazy2[v];
        lazy2[v * 2] = lazy2[v];
        lazy2[v * 2 + 1] = lazy2[v];
        lazy2[v] = 0;
        lazy1[v * 2] = 0;
        lazy1[v * 2 + 1] = 0;
    }
    seg[v * 2] += (tm - tl + 1) * lazy1[v];
    seg[v * 2 + 1] += (tr - tm) * lazy1[v];
    lazy1[v * 2] += lazy1[v];
    lazy1[v * 2 + 1] += lazy1[v];
    lazy1[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int val, int type) {
    if (l > r) return;
    if (l == tl && r == tr) {
        if (type == 1) {
            seg[v] += (tr - tl + 1) * val;
            lazy1[v] += val;
        } else if (type == 2) {
            seg[v] = (tr - tl + 1) * val;
            lazy1[v] = 0;
            lazy2[v] = val;
        }
    } else {
        int tm = (tl + tr) / 2;
        push(v, tl, tr);
        update(v * 2, tl, tm, l, min(r, tm), val, type);
        update(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r, val, type);
        seg[v] = seg[v * 2] + seg[v * 2 + 1];
    }
}

int get(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (l == tl && r == tr) {
        return seg[v];
    }
    int tm = (tl + tr) / 2;
    push(v, tl, tr);
    return get(v * 2, tl, tm, l, min(r, tm)) +
           get(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r);
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
        int type;
        cin >> type;
        if (type == 1) {
            int l, r, val;
            cin >> l >> r >> val;
            l--, r--;
            update(1, 0, n - 1, l, r, val, 1);
        } else if (type == 2) {
            int l, r, val;
            cin >> l >> r >> val;
            l--, r--;
            update(1, 0, n - 1, l, r, val, 2);
        } else if (type == 3) {
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << get(1, 0, n - 1, l, r) << endl;
        }
    }
    return 0;
}
