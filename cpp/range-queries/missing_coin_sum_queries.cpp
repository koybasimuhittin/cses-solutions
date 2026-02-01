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

int n, m, arr[N];
pair<int, pair<vector<int>, vector<int>>> seg[4 * N];

pair<int, pair<vector<int>, vector<int>>> merge(
    pair<int, pair<vector<int>, vector<int>>>& a,
    pair<int, pair<vector<int>, vector<int>>>& b) {
    pair<int, pair<vector<int>, vector<int>>> res;
    res.f1 = a.f1 + b.f1;
    int i = 0, j = 0;
    bool flag = true;
    while (flag) {
        flag = false;
        int idx = upper_bound(a.s2.f1.begin(), a.s2.f1.end(), res.f1 + 1) -
                  a.s2.f1.begin();
        if (idx <= a.s2.f1.size() && idx > i) {
            res.f1 += a.s2.s2[idx] - a.s2.s2[i];
            i = idx;
            flag = true;
        }
        idx = upper_bound(b.s2.f1.begin(), b.s2.f1.end(), res.f1 + 1) -
              b.s2.f1.begin();
        if (idx <= b.s2.f1.size() && idx > j) {
            res.f1 += b.s2.s2[idx] - b.s2.s2[j];
            j = idx;
            flag = true;
        }
    }
    res.s2.s2.pb(0);
    int sum = 0;
    while (i < a.s2.f1.size() && j < b.s2.f1.size()) {
        if (a.s2.f1[i] < b.s2.f1[j]) {
            sum += a.s2.f1[i];
            res.s2.f1.pb(a.s2.f1[i]);
            res.s2.s2.pb(sum);
            i++;
        } else {
            sum += b.s2.f1[j];
            res.s2.f1.pb(b.s2.f1[j]);
            res.s2.s2.pb(sum);
            j++;
        }
    }
    while (i < a.s2.f1.size()) {
        sum += a.s2.f1[i];
        res.s2.f1.pb(a.s2.f1[i]);
        res.s2.s2.pb(sum);
        i++;
    }
    while (j < b.s2.f1.size()) {
        sum += b.s2.f1[j];
        res.s2.f1.pb(b.s2.f1[j]);
        res.s2.s2.pb(sum);
        j++;
    }
    return res;
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        if (arr[tl] == 1) {
            seg[v].f1 = 1;
            seg[v].s2 = {{}, {0}};
        } else {
            seg[v].f1 = 0;
            seg[v].s2 = {{arr[tl]}, {0, arr[tl]}};
        }
    } else {
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        seg[v] = merge(seg[v * 2], seg[v * 2 + 1]);
    }
}

pair<int, pair<vector<int>, vector<int>>> get(int v, int tl, int tr, int l,
                                              int r) {
    if (l > r) return {0, {{}, {0}}};
    if (l == tl && r == tr) {
        return seg[v];
    }
    int tm = (tl + tr) / 2;
    pair<int, pair<vector<int>, vector<int>>> l_get =
        get(v * 2, tl, tm, l, min(r, tm));
    pair<int, pair<vector<int>, vector<int>>> r_get =
        get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    return merge(l_get, r_get);
}

int32_t main() {
    fri("test_input-3.txt");
    fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    build(1, 0, n - 1);

    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        cout << get(1, 0, n - 1, l, r).f1 + 1 << endl;
        fflush(stdout);
    }

    return 0;
}
