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

int n, q, arr[N], seg[4 * N];
map<int, set<int>> idxs;

void update(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        seg[v] = val;
        return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm) {
        update(v * 2, tl, tm, pos, val);
    }
    else {
        update(v * 2 + 1, tm + 1, tr, pos, val);
    }
    seg[v] = min(seg[v * 2], seg[v * 2 + 1]);
}

int get(int v, int tl, int tr, int l, int r) {
    if (l > r) return INT_MAX;
    if (l == tl && r == tr) {
        return seg[v];
    }
    int tm = (tl + tr) / 2;
    return min(get(v * 2, tl, tm, l, min(r, tm)), get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        idxs[arr[i]].insert(n);
    }

    for (int i = n - 1; i >= 0; i--) {
        int nxt_idx = *idxs[arr[i]].begin();
        idxs[arr[i]].insert(i);

        update(1, 0, n - 1, i, nxt_idx);
    }

    int t, a, b;
    for (int i = 0; i < q; i++) {
        cin >> t >> a >> b;
        a--;
        if (t == 1) {
            idxs[b].insert(n);
            auto it = idxs[arr[a]].find(a);
            if (it != idxs[arr[a]].begin()) {
                auto it_prev = prev(it);
                auto it_next = next(it);

                update(1, 0, n - 1, (*it_prev), (*it_next));
            }
            idxs[arr[a]].erase(it);
            arr[a] = b;
            idxs[b].insert(a);
            it = idxs[b].find(a);
            if (it != idxs[arr[a]].begin()) {
                auto it_prev = prev(it);
                auto it_next = next(it);

                update(1, 0, n - 1, (*it_prev), (*it_next));
            }
            update(1, 0, n - 1, a, *next(it));

        }
        else {
            b--;
            cout << ((get(1, 0, n - 1, a, b) <= b) ? "NO" : "YES") << endl;
        }
    }

    return 0;
}
