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
const int N = 1e3 + 5;

int n, m, seg[4 * N][4 * N];
bool state[N][N];

void build_row(int v, int tl, int tr, int vc, int tlc, int trc) {
    if (tl == tr) {
        if (tlc == trc)
            seg[vc][v] = state[tlc][tl];
        else
            seg[vc][v] = seg[vc * 2][v] + seg[vc * 2 + 1][v];
    } else {
        int tm = (tl + tr) / 2;
        build_row(v * 2, tl, tm, vc, tlc, trc);
        build_row(v * 2 + 1, tm + 1, tr, vc, tlc, trc);
        seg[vc][v] = seg[vc][v * 2] + seg[vc][v * 2 + 1];
    }
}

void build_cols(int v, int tl, int tr) {
    if (tl != tr) {
        int tm = (tl + tr) / 2;
        build_cols(v * 2, tl, tm);
        build_cols(v * 2 + 1, tm + 1, tr);
    }
    build_row(1, 0, n - 1, v, tl, tr);
}

int get_row(int v, int tl, int tr, int l, int r, int vc) {
    if (l > r) return 0;
    if (l == tl && r == tr) {
        return seg[vc][v];
    }
    int tm = (tl + tr) / 2;
    return get_row(v * 2, tl, tm, l, min(r, tm), vc) +
           get_row(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, vc);
}

int get_cols(int v, int tl, int tr, int lc, int rc, int lr, int rr) {
    if (lc > rc) return 0;
    if (lc == tl && rc == tr) {
        return get_row(1, 0, n - 1, lr, rr, v);
    }
    int tm = (tl + tr) / 2;
    return get_cols(v * 2, tl, tm, lc, min(rc, tm), lr, rr) +
           get_cols(v * 2 + 1, tm + 1, tr, max(lc, tm + 1), rc, lr, rr);
}

void update_row(int v, int tl, int tr, int pos, int val, int vc, int tlc,
                int trc) {
    if (tl == tr) {
        if (tlc == trc)
            seg[vc][v] = val;
        else
            seg[vc][v] = seg[vc * 2][v] + seg[vc * 2 + 1][v];
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update_row(v * 2, tl, tm, pos, val, vc, tlc, trc);
        else
            update_row(v * 2 + 1, tm + 1, tr, pos, val, vc, tlc, trc);
        seg[vc][v] = seg[vc][v * 2] + seg[vc][v * 2 + 1];
    }
}

void update_cols(int v, int tl, int tr, int posc, int posr, int val) {
    if (tl != tr) {
        int tm = (tl + tr) / 2;
        if (posc <= tm)
            update_cols(v * 2, tl, tm, posc, posr, val);
        else
            update_cols(v * 2 + 1, tm + 1, tr, posc, posr, val);
    }
    update_row(1, 0, n - 1, posr, val, v, tl, tr);
}

int32_t main() {
    // fri("in.txt");
    // fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < n; j++) {
            state[i][j] = s[j] == '*';
        }
    }
    build_cols(1, 0, n - 1);

    for (int i = 0; i < m; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            state[x][y] = !state[x][y];
            update_cols(1, 0, n - 1, x, y, state[x][y]);
        } else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            x1--;
            y1--;
            x2--;
            y2--;
            cout << get_cols(1, 0, n - 1, x1, x2, y1, y2) << endl;
        }
    }
    return 0;
}
