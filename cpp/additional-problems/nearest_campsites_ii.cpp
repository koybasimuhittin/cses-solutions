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
const int N = 1e6 + 5;
const int INF = 1e15;

typedef struct Campsite {
    int x, y, idx;
    bool type;
} Campsite;

int n, m, res[N], seg_top[4 * N], seg_bottom[4 * N], mx = 0, my = 0;
vector <Campsite> v;

void update(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        seg_bottom[v] = my - tl + val;
        seg_top[v] = tl + val;
        return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm)update(v * 2, tl, tm, pos, val);
    else update(v * 2 + 1, tm + 1, tr, pos, val);
    seg_bottom[v] = min(seg_bottom[v * 2], seg_bottom[v * 2 + 1]);
    seg_top[v] = min(seg_top[v * 2], seg_top[v * 2 + 1]);
}

int get_bottom(int v, int tl, int tr, int l, int r) {
    if (l > r) return INF;
    if (l <= tl && r >= tr) {
        return seg_bottom[v];
    }
    int tm = (tl + tr) / 2;
    return min(get_bottom(v * 2, tl, tm, l, min(r, tm)), get_bottom(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

int get_top(int v, int tl, int tr, int l, int r) {
    if (l > r) return INF;
    if (l <= tl && r >= tr) {
        return seg_top[v];
    }
    int tm = (tl + tr) / 2;
    return min(get_top(v * 2, tl, tm, l, min(r, tm)), get_top(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    int x, y;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        mx = max(x, mx);
        my = max(y, my);
        v.pb({ x, y, i, false });
    }
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        mx = max(x, mx);
        my = max(y, my);
        v.pb({ x, y, i, true });
        res[i] = INF;
    }

    fill(begin(seg_bottom), end(seg_bottom), INF);
    fill(begin(seg_top), end(seg_top), INF);
    sort(v.begin(), v.end(), [&](const Campsite& a, const Campsite& b) {
        if (a.x == b.x) {
            return a.type < b.type;
        }
        return a.x < b.x;
        });

    for (int i = 0; i < n + m; i++) {
        if (v[i].type) {
            int mini = min(get_bottom(1, 1, my, 1, v[i].y) - (my - v[i].y), get_top(1, 1, my, v[i].y, my) - v[i].y) - mx + v[i].x;
            res[v[i].idx] = min(res[v[i].idx], mini);
        }
        else {
            update(1, 1, my, v[i].y, mx - v[i].x);
        }
    }

    fill(begin(seg_bottom), end(seg_bottom), INF);
    fill(begin(seg_top), end(seg_top), INF);
    sort(v.begin(), v.end(), [&](const Campsite& a, const Campsite& b) {
        if (a.x == b.x) {
            return a.type < b.type;
        }
        return a.x > b.x;
        });

    for (int i = 0; i < n + m; i++) {
        if (v[i].type) {
            int mini = min(get_bottom(1, 1, my, 1, v[i].y) - (my - v[i].y), get_top(1, 1, my, v[i].y, my) - v[i].y) - v[i].x;
            res[v[i].idx] = min(res[v[i].idx], mini);
        }
        else {
            update(1, 1, my, v[i].y, v[i].x);
        }
    }

    for (int i = 0; i < m; i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
