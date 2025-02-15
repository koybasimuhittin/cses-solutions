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

typedef struct Node {
    int prefix, suffix, sum, ans;

    Node(int _prefix, int _suffix, int _sum, int _ans) {
        prefix = _prefix;
        suffix = _suffix;
        sum = _sum;
        ans = _ans;
    }
} Node;

int n, m, t, arr[N];
vector<Node> seg(4 * N, Node(0, 0, 0, 0));

void build(int v, int tl, int tr) {
    if (tl == tr) {
        seg[v].ans = max(arr[tl], 0ll);
        seg[v].sum = arr[tl];
        seg[v].prefix = max(arr[tl], 0ll);
        seg[v].suffix = max(arr[tl], 0ll);
        return;
    }

    int tm = (tl + tr) / 2;

    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);

    seg[v].ans = max(max(seg[v * 2].ans, seg[v * 2 + 1].ans),
                     seg[v * 2].suffix + seg[v * 2 + 1].prefix);
    seg[v].sum = seg[v * 2].sum + seg[v * 2 + 1].sum;
    seg[v].prefix =
        max(seg[v * 2].sum + seg[v * 2 + 1].prefix, seg[v * 2].prefix);
    seg[v].suffix =
        max(seg[v * 2 + 1].sum + seg[v * 2].suffix, seg[v * 2 + 1].suffix);
}

void update(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        seg[v].ans = max(arr[tl], 0ll);
        seg[v].sum = arr[tl];
        seg[v].prefix = max(arr[tl], 0ll);
        seg[v].suffix = max(arr[tl], 0ll);
        return;
    }

    int tm = (tl + tr) / 2;

    if (pos <= tm) {
        update(v * 2, tl, tm, pos);
    } else {
        update(v * 2 + 1, tm + 1, tr, pos);
    }

    seg[v].ans = max(max(seg[v * 2].ans, seg[v * 2 + 1].ans),
                     seg[v * 2].suffix + seg[v * 2 + 1].prefix);
    seg[v].sum = seg[v * 2].sum + seg[v * 2 + 1].sum;
    seg[v].prefix =
        max(seg[v * 2].sum + seg[v * 2 + 1].prefix, seg[v * 2].prefix);
    seg[v].suffix =
        max(seg[v * 2 + 1].sum + seg[v * 2].suffix, seg[v * 2 + 1].suffix);
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

    build(1, 0, n - 1);

    int a, b;
    while (m--) {
        cin >> a >> b;
        arr[a - 1] = b;
        update(1, 0, n - 1, a - 1);
        cout << seg[1].ans << endl;
    }

    return 0;
}
