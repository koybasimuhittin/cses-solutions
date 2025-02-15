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

int n, m, t, arr[N], seg_left[4 * N], seg_right[4 * N];

void build_left(int v, int tl, int tr) {
    if (tl == tr) {
        seg_left[v] = arr[tl] - tl;
        return;
    }

    int tm = (tl + tr) / 2;

    build_left(v * 2, tl, tm);
    build_left(v * 2 + 1, tm + 1, tr);

    seg_left[v] = min(seg_left[v * 2], seg_left[v * 2 + 1]);
}

void build_right(int v, int tl, int tr) {
    if (tl == tr) {
        seg_right[v] = arr[tl] + tl;
        return;
    }

    int tm = (tl + tr) / 2;

    build_right(v * 2, tl, tm);
    build_right(v * 2 + 1, tm + 1, tr);

    seg_right[v] = min(seg_right[v * 2], seg_right[v * 2 + 1]);
}

void update_left(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        seg_left[v] = arr[tl] - tl;
        return;
    }

    int tm = (tl + tr) / 2;

    if (pos <= tm) {
        update_left(v * 2, tl, tm, pos);
    } else {
        update_left(v * 2 + 1, tm + 1, tr, pos);
    }

    seg_left[v] = min(seg_left[v * 2], seg_left[v * 2 + 1]);
}

void update_right(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        seg_right[v] = arr[tl] + tl;
        return;
    }

    int tm = (tl + tr) / 2;

    if (pos <= tm) {
        update_right(v * 2, tl, tm, pos);
    } else {
        update_right(v * 2 + 1, tm + 1, tr, pos);
    }

    seg_right[v] = min(seg_right[v * 2], seg_right[v * 2 + 1]);
}

int get_left(int v, int tl, int tr, int l, int r) {
    if (l > r) {
        return LLONG_MAX;
    }

    if (tl == l && tr == r) {
        return seg_left[v];
    }

    int tm = (tl + tr) / 2;

    return min(get_left(v * 2, tl, tm, l, min(r, tm)),
               get_left(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

int get_right(int v, int tl, int tr, int l, int r) {
    if (l > r) {
        return LLONG_MAX;
    }

    if (tl == l && tr == r) {
        return seg_right[v];
    }

    int tm = (tl + tr) / 2;

    return min(get_right(v * 2, tl, tm, l, min(r, tm)),
               get_right(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
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

    build_left(1, 0, n - 1);
    build_right(1, 0, n - 1);

    int q;
    while (m--) {
        cin >> q;
        if (q == 2) {
            int k;
            cin >> k;
            cout << min(get_left(1, 0, n - 1, 0, k - 1) + k - 1,
                        get_right(1, 0, n - 1, k - 1, n - 1) - k + 1)
                 << endl;
        }

        else {
            int k, x;
            cin >> k >> x;
            arr[k - 1] = x;
            update_left(1, 0, n - 1, k - 1);
            update_right(1, 0, n - 1, k - 1);
        }
    }

    return 0;
}
