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

int n, k, seg[4 * N];

void build(int v, int tl, int tr) {
    if (tl == tr) {
        seg[v] = 1;
        return;
    }

    int tm = (tl + tr) / 2;

    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);

    seg[v] = seg[2 * v] + seg[2 * v + 1];
}

void update(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        seg[v] = 0;
        return;
    }

    int tm = (tl + tr) / 2;
    if (pos <= tm) {
        update(2 * v, tl, tm, pos);
    }
    else {
        update(2 * v + 1, tm + 1, tr, pos);
    }

    seg[v] = seg[2 * v] + seg[2 * v + 1];
}

int get(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (l == tl && r == tr) {
        return seg[v];
    }

    int tm = (tl + tr) / 2;

    return get(v * 2, tl, tm, l, min(tm, r)) + get(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r);
}

int b_search(int v, int tl, int tr, int s) {
    if (tl == tr) return tl;

    if (s <= seg[2 * v]) {
        return b_search(2 * v, tl, (tl + tr) / 2, s);
    }
    return b_search(2 * v + 1, (tl + tr) / 2 + 1, tr, s - seg[2 * v]);
}

int32_t main() {

    fri("in.txt");
    fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    build(1, 1, n);

    vector<int> will_removed;
    int last_removed = 0;

    int current_index = 0;
    int current_el = 0;
    for (int i = 0; i < n; i++) {
        int rem = get(1, 1, n, current_el + 1, n);
        if (rem < k + 1) {
            current_index = (k + 1) - rem;
            for (int j = last_removed; j < will_removed.size(); j++) {
                update(1, 1, n, will_removed[j]);
            }
            last_removed = will_removed.size();
        }
        else {
            current_index += (k + 1);
        }

        int tot = get(1, 1, n, 1, n);

        if (tot == 1) {
            cout << b_search(1, 1, n, 1) << endl;
            return 0;
        }

        current_index = current_index % (tot + 1);

        current_el = b_search(1, 1, n, current_index);
        will_removed.pb(current_el);
        cout << current_el << " ";
    }

    cout << endl;

    return 0;
}
