#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define f1 first
#define s2 second
#define pb push_back
#define mp make_pair
#define int long long
#define fri(a) freopen(a,"r",stdin);
#define fro(a) freopen(a,"w",stdout);
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;

int n, m, t, arr[N], inv[N], seg[4 * N], pos[4 * N];
map<int, int> idx_to_val;

void update(int v, int tl, int tr, int pos, int val, int* seg) {
    if (tl == tr)seg[v] += val;
    else {
        int tm = (tl + tr) / 2;
        if (pos <= tm) update(v * 2, tl, tm, pos, val, seg);
        else update(v * 2 + 1, tm + 1, tr, pos, val, seg);
        seg[v] = seg[v * 2] + seg[v * 2 + 1];
    }
}

int get(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (l == tl && r == tr)return seg[v];
    int tm = (tl + tr) / 2;
    return get(v * 2, tl, tm, l, min(r, tm)) + get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

int calc_pos(int v, int tl, int tr, int l, int r) {
    if (l > r) return -1;
    if (l == tl && r == tr && pos[v] == (tr - tl + 1)) return -1;
    if (tl == tr) return tl;

    int tm = (tl + tr) / 2;

    int res = -1;
    if (l <= tm) {
        res = calc_pos(v * 2, tl, tm, l, min(r, tm));
    }
    if (res == -1 && r > tm) {
        res = calc_pos(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }
    return res;
}


void compress() {
    map<int, int> m;
    set<int> s;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        s.insert(arr[i]);
    }
    for (auto& e : s) {
        idx_to_val[cnt] = e;
        m[e] = cnt++;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = m[arr[i]];
    }

}

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    compress();

    int ans = 0;

    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++) {
        inv[i] = min(m, get(1, 0, n - 1, arr[i] + 1, n - 1));
        update(1, 0, n - 1, arr[i], 1, seg);
        v.pb({ arr[i], i });
    }

    sort(v.begin(), v.end());

    for (auto& [a, idx] : v) {
        int new_idx = calc_pos(1, 0, n - 1, max(0ll, idx - inv[idx]), n - 1);
        arr[new_idx] = a;
        update(1, 0, n - 1, new_idx, 1, pos);
    }

    for (int i = 0; i < n; i++) {
        cout << idx_to_val[arr[i]] << " ";
    }

    return 0;
}
