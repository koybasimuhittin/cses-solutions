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

int n, m, t, arr[N], seg[4 * N];

void build(int v, int tl, int tr) {
    if (tl == tr) {
        seg[v] = 1;
        return;
    }

    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);

    seg[v] = seg[v * 2] + seg[v * 2 + 1];
}

int get(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        seg[v] = 0;
        return tl;
    }

    int tm = (tl + tr) / 2;

    int res;

    if (seg[v * 2] >= pos) {
        res = get(v * 2, tl, tm, pos);
    } else {
        res = get(v * 2 + 1, tm + 1, tr, pos - seg[v * 2]);
    }

    seg[v] = seg[v * 2] + seg[v * 2 + 1];
    return res;
}

int32_t main() {
    // fri("in.txt");
    // fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    build(1, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> m;
        cout << arr[get(1, 0, n - 1, m)] << " ";
    }

    return 0;
}
