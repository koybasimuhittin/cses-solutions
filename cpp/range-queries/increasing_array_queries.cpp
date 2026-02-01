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

int n, m, arr[N];

typedef struct Node {
    int res = 0;
    vector<int> elements;
    vector<int> pre;
} Node;

Node seg[4 * N];

void build(int v, int tl, int tr) {
    if (tl == tr) {
        seg[v].res = 0;
        seg[v].pre.pb(0);
        seg[v].pre.pb(arr[tl]);
        seg[v].elements.pb(arr[tl]);
        return;
    }

    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);

    seg[v].res = seg[v * 2].res + seg[v * 2 + 1].res;
    seg[v].elements = seg[v * 2].elements;
    seg[v].pre = seg[v * 2].pre;

    for (auto e : seg[v * 2 + 1].elements) {
        seg[v].res += max(0LL, seg[v * 2].elements.back() - e);
        seg[v].elements.pb(max(seg[v * 2].elements.back(), e));
        seg[v].pre.pb(seg[v].pre.back() + seg[v].elements.back());
    }
}

pair<int, int> get(int v, int tl, int tr, int l, int r, int prev) {
    if (l > r)return{ 0, prev };
    if (l == tl && r == tr) {
        int idx = lower_bound(seg[v].elements.begin(), seg[v].elements.end(), prev) - seg[v].elements.begin();
        return { idx * prev - seg[v].pre[idx] + seg[v].res, max(prev, seg[v].elements.back()) };
    }
    int tm = (tl + tr) / 2;

    pair<int, int> left_get = get(v * 2, tl, tm, l, min(r, tm), prev);
    pair<int, int> right_get = get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, left_get.s2);

    return { left_get.f1 + right_get.f1, right_get.s2 };
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

    build(1, 0, n - 1);

    int a, b;
    while (m--) {
        cin >> a >> b;
        pair<int, int> res = get(1, 0, n - 1, a - 1, b - 1, 0);
        cout << res.f1 << endl;
    }

    return 0;
}
