#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n;
    vector<int> bit;
    Fenwick(int n = 0) : n(n), bit(n + 1, 0) {}
    inline void add(int i, int v) {
        for (; i <= n; i += i & -i) bit[i] += v;
    }
    inline int sum(int i) const {
        int r = 0;
        for (; i > 0; i -= i & -i) r += bit[i];
        return r;
    }
    inline int rangeSum(int l, int r) const { // inclusive
        if (l > r) return 0;
        return sum(r) - sum(l - 1);
    }
};

struct Event {
    int pos;      // index in array
    int idx;      // query id
    int sign;     // +1 for b, -1 for a-1
    int L, R;     // value range in compressed coords (inclusive)
    bool operator<(Event const& other) const { return pos < other.pos; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];

    // compress ONLY array values (faster + enough)
    vector<int> vals = x;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    int m = (int)vals.size();

    vector<int> xc(n);
    for (int i = 0; i < n; i++) {
        xc[i] = int(lower_bound(vals.begin(), vals.end(), x[i]) - vals.begin()) + 1; // 1-indexed
    }

    vector<long long> ans(q, 0);
    vector<Event> ev;
    ev.reserve(2LL * q);

    for (int i = 0; i < q; i++) {
        int a, b;
        int c, d;
        cin >> a >> b >> c >> d;
        --a; --b;

        // Map [c,d] to indices in sorted unique array values:
        int l0 = int(lower_bound(vals.begin(), vals.end(), c) - vals.begin());
        int r0 = int(upper_bound(vals.begin(), vals.end(), d) - vals.begin()) - 1;

        if (l0 <= r0) {
            int L = l0 + 1; // to 1-indexed BIT
            int R = r0 + 1;
            ev.push_back({ b, i, +1, L, R });
            if (a - 1 >= 0) ev.push_back({ a - 1, i, -1, L, R });
        }
        // else range is empty -> answer stays 0
    }

    sort(ev.begin(), ev.end());

    Fenwick fw(m);
    int e = 0;
    for (int i = 0; i < n; i++) {
        fw.add(xc[i], 1);
        while (e < (int)ev.size() && ev[e].pos == i) {
            ans[ev[e].idx] += 1LL * ev[e].sign * fw.rangeSum(ev[e].L, ev[e].R);
            e++;
        }
    }

    for (int i = 0; i < q; i++) cout << ans[i] << "\n";
    return 0;
}
