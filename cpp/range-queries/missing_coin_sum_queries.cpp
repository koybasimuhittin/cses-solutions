#include <bits/stdc++.h>
using namespace std;

static const int M = 31;
static const int INF = 1e9 + 7;
static const int N = 200000 + 5;

int n, q;
int a[N];
array<int, M> seg[4 * N];
long long pref[M][N];

inline int bucket(int x) {
    return 31 - __builtin_clz((unsigned)x);
}

void build(int v, int tl, int tr) {
    seg[v].fill(INF);
    if (tl == tr) {
        seg[v][bucket(a[tl])] = a[tl];
        return;
    }
    int tm = (tl + tr) >> 1;
    build(v << 1, tl, tm);
    build(v << 1 | 1, tm + 1, tr);
    for (int j = 0; j < M; j++) {
        seg[v][j] = min(seg[v << 1][j], seg[v << 1 | 1][j]);
    }
}

inline void merge_into(array<int, M>& acc, const array<int, M>& node) {
    for (int j = 0; j < M; j++) acc[j] = min(acc[j], node[j]);
}

void query(int v, int tl, int tr, int l, int r, array<int, M>& acc) {
    if (l > tr || r < tl) return;
    if (l <= tl && tr <= r) {
        merge_into(acc, seg[v]);
        return;
    }
    int tm = (tl + tr) >> 1;
    query(v << 1, tl, tm, l, r, acc);
    query(v << 1 | 1, tm + 1, tr, l, r, acc);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        int b = bucket(a[i]);
        pref[b][i] += a[i];
        for (int j = 0; j < M; j++) pref[j][i] += pref[j][i - 1];
    }

    build(1, 1, n);

    while (q--) {
        int l, r;
        cin >> l >> r;

        array<int, M> mn;
        mn.fill(INF);
        query(1, 1, n, l, r, mn);

        long long reach = 0;
        for (int j = 0; j < M; j++) {
            if ((1LL << j) > reach + 1) break;
            if (mn[j] <= reach + 1) {
                reach += pref[j][r] - pref[j][l - 1];
            }
        }
        cout << reach + 1 << "\n";
    }
    return 0;
}
