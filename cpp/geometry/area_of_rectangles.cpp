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

typedef struct Event {
    bool type;
    int x1, x2, y;
} Event;

int n, seg[8 * N], lazy[8 * N];
vector<Event> events;

void calc(int v, int tl, int tr) {
    if (lazy[v] > 0) {
        seg[v] = tr - tl + 1;
    }
    else {
        if (tl == tr) seg[v] = 0;
        else seg[v] = seg[v * 2] + seg[v * 2 + 1];
    }
}

void update(int v, int tl, int tr, int l, int r, int val) {
    if (l > r) return;
    if (l == tl && r == tr) {
        lazy[v] += val;
        calc(v, tl, tr);
        return;
    }
    int tm = (tl + tr) / 2;
    update(v * 2, tl, tm, l, min(r, tm), val);
    update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
    calc(v, tl, tr);
}


int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    int x1, x2, y1, y2;
    int prev = INT_MAX;
    for (int i = 0; i < n; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        events.pb({ 1, x1 + N, x2 + N, y1 });
        events.pb({ 0, x1 + N, x2 + N, y2 });
        prev = min(prev, y1);
    }

    sort(events.begin(), events.end(), [&](const Event& e1, const Event& e2) {
        return e1.y < e2.y;
        });

    int res = 0;
    for (auto& e : events) {
        if (e.y != prev) {
            res += (e.y - prev) * (seg[1]);
        }
        if (e.type) {
            update(1, 0, 2 * N - 1, e.x1, e.x2 - 1, 1);
        }
        else {
            update(1, 0, 2 * N - 1, e.x1, e.x2 - 1, -1);
        }
        prev = e.y;
    }

    cout << res << endl;


    return 0;
}
