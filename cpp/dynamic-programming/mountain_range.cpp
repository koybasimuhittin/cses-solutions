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

int n, arr[N];
pair<int, int> seg[4 * N];

void build(int v, int tl, int tr) {
    if (tl == tr) {
        seg[v] = {arr[tl], tl};
    } else {
        int tm = (tl + tr) / 2;

        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);

        seg[v] = max(seg[v * 2], seg[v * 2 + 1]);
    }
}

pair<int, int> get(int v, int tl, int tr, int l, int r) {
    if (l > r) {
        return {0, -1};
    }

    if (l == tl && r == tr) {
        return seg[v];
    }

    int tm = (tl + tr) / 2;

    return max(get(v * 2, tl, tm, l, min(r, tm)),
               get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

int solve(int l, int r, int prev_h) {
    if (l > r) return 0;

    auto [h, pos] = get(1, 0, n - 1, l, r);

    if (h == prev_h) return 0;

    int L = solve(l, pos - 1, h);
    int R = solve(pos + 1, r, h);
    return 1 + max(L, R);
}

int32_t main() {
    // fri("in.txt");
    // fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    build(1, 0, n - 1);

    cout << solve(0, n - 1, 0) << endl;

    return 0;
}
