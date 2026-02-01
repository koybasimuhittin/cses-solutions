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

typedef struct Node {
    int prefix, suffix, ans, sum;
} Node;

int n, m, arr[N];
Node seg[4 * N];

Node combine(const Node& a, const Node& b) {
    Node res;

    res.sum = a.sum + b.sum;
    res.prefix = max(a.prefix, a.sum + b.prefix);
    res.suffix = max(b.suffix, b.sum + a.suffix);
    res.ans = max(max(a.ans, b.ans), a.suffix + b.prefix);
    return res;
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        seg[v] = { arr[tl], arr[tl], arr[tl], arr[tl] };
        return;
    }

    int tm = (tl + tr) >> 1;

    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    seg[v] = combine(seg[v * 2], seg[v * 2 + 1]);
}

Node get(int v, int tl, int tr, int l, int r) {
    if (l > r) return { 0, 0, 0 };
    if (l == tl && r == tr) {
        return seg[v];
    }
    int tm = (tl + tr) >> 1;
    return combine(get(v * 2, tl, tm, l, min(r, tm)), get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
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
        if (a == b) {
            cout << max(0LL, arr[a - 1]) << endl;
            continue;
        }
        cout << get(1, 0, n - 1, a - 1, b - 1).ans << endl;
    }

    return 0;
}
