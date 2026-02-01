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
const int N = 1e5 + 5;


vector<int> seg[4 * N];
int n, q, arr[N];

void build(int v, int tl, int tr) {
    if (tl == tr) {
        seg[v].pb(arr[tl]);
        return;
    }
    int tm = (tl + tr) / 2;

    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);

    seg[v] = seg[v * 2];
    for (auto e : seg[v * 2 + 1]) {
        if (e > seg[v * 2].back()) {
            seg[v].pb(e);
        }
    }
}

pair<int, int> get(int v, int tl, int tr, int l, int r, int prev) {
    if (l > r)return { 0, prev };
    if (l == tl && r == tr) {
        int cnt = seg[v].end() - upper_bound(seg[v].begin(), seg[v].end(), prev);
        return { cnt, max(prev, seg[v].back()) };
    }

    int tm = (tl + tr) / 2;

    pair<int, int> get_left = get(v * 2, tl, tm, l, min(r, tm), prev);
    pair<int, int> get_right = get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, get_left.s2);

    return { get_left.f1 + get_right.f1, get_right.s2 };
}


int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    build(1, 0, n - 1);

    int a, b;
    for (int i = 0; i < q;i++) {
        cin >> a >> b;
        a--;
        b--;
        cout << get(1, 0, n - 1, a, b, 0).f1 << endl;
    }

    return 0;
}
