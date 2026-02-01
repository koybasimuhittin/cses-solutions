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

int n, m, arr[N], seg[4 * N];
pair<int, int> lazy[4 * N];

int gauss(int l, int r, int val, int coefficient = 1) {
    int cnt = r - l + 1;
    r = val + (r - l) * coefficient;
    l = val;

    return (cnt * (r + l)) / 2;
}

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
    seg[v * 2] += gauss(tl, tm, lazy[v].s2, lazy[v].f1);
    lazy[v * 2].f1 += lazy[v].f1;
    lazy[v * 2].s2 += lazy[v].s2;

    seg[v * 2 + 1] +=
        gauss(tm + 1, tr, lazy[v].s2 + lazy[v].f1 * (tm - tl + 1), lazy[v].f1);
    lazy[v * 2 + 1].f1 += lazy[v].f1;
    lazy[v * 2 + 1].s2 += lazy[v].s2 + lazy[v].f1 * (tm - tl + 1);
    lazy[v] = {0, 0};
}

void update(int v, int tl, int tr, int l, int r, int val) {
    if (l > r) return;
    if (l == tl && r == tr) {
        seg[v] += gauss(l, r, val);
        lazy[v].f1++;
        lazy[v].s2 += val;
    } else {
        int tm = (tl + tr) / 2;
        push(v, tl, tr);
        if (l <= tm) update(v * 2, tl, tm, l, min(r, tm), val);
        if (r > tm)
            update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r,
                   val + max(0LL, tm - max(l, tl) + 1));
        seg[v] = seg[v * 2] + seg[v * 2 + 1];
    }
}

int get(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (l == tl && r == tr) {
        return seg[v];
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    return get(v * 2, tl, tm, l, min(r, tm)) +
           get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
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
    int type, l, r;
    for (int i = 0; i < m; i++) {
        cin >> type >> l >> r;
        l--;
        r--;
        if (type == 1) {
            update(1, 0, n - 1, l, r, 1);
        } else {
            cout << get(1, 0, n - 1, l, r) << endl;
        }
    }

    return 0;
}
