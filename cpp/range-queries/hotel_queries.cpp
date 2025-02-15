#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define f1 first
#define s2 second
#define pb push_back
#define mp make_pair
#define fri(a) freopen(a, "r", stdin);
#define fro(a) freopen(a, "w", stdout);

const int MOD = 1e9 + 7;
const int N = 2e5 + 5;

int n, m, a, hotel_sizes[N];
pair<int, int> seg[4 * N];

void build(int v, int tl, int tr) {
    if (tl == tr) {
        seg[v] = {hotel_sizes[tl], tl};
        return;
    }

    int tm = (tl + tr) / 2;

    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);

    seg[v] = max(seg[v * 2], seg[v * 2 + 1]);
}

pair<int, int> get(int v, int tl, int tr, int val) {
    if (seg[v].f1 < val) {
        return {-1, -1};
    }

    if (tl == tr) {
        return seg[v];
    }

    int tm = (tl + tr) / 2;

    if (seg[v * 2].f1 >= val) {
        return get(v * 2, tl, tm, val);
    }

    return get(v * 2 + 1, tm + 1, tr, val);
}

void update(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        seg[v] = {val, pos};
        return;
    }

    int tm = (tl + tr) / 2;

    if (pos <= tm) {
        update(v * 2, tl, tm, pos, val);
    } else {
        update(v * 2 + 1, tm + 1, tr, pos, val);
    }

    seg[v] = max(seg[v * 2], seg[v * 2 + 1]);
}

int32_t main() {
    // fri("in.txt");
    // fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> hotel_sizes[i];
    }

    build(1, 0, n - 1);

    for (int i = 0; i < m; i++) {
        cin >> a;
        auto [hotel_size, hotel_index] = get(1, 0, n - 1, a);
        if (hotel_size != -1) {
            cout << hotel_index + 1 << " ";
            update(1, 0, n - 1, hotel_index, hotel_size - a);
        } else {
            cout << 0 << " ";
        }
    }

    return 0;
}