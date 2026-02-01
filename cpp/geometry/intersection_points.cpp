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

typedef struct Event {
    bool type, start_or_end;
    int x1, x2, y1, y2;

} Event;

int n;
vector<Event> events;

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
    inline int sum(int l, int r) const {
        if (l > r) return 0;
        return sum(r) - sum(l - 1);
    }
};

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    int x1, y1, x2, y2;
    int minx = INT_MAX;
    int maxx = INT_MIN;

    for (int i = 0; i < n; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2) {
            events.pb({ 0, 1, x1, x2, y1, INT_MAX });
            events.pb({ 0, 0, x1, x2, y2, INT_MAX });
        }
        else {
            events.pb({ 1, 0, x1, x2, y1, y2 });
        }
        minx = min(minx, min(x1, x2));
        maxx = max(maxx, max(x1, x2));
    }

    sort(events.begin(), events.end(), [&](Event& e1, Event& e2) {
        return e1.y1 < e2.y1;
        });

    int ans = 0;
    Fenwick bit(maxx + abs(min(0ll, minx)) + 1);
    for (auto& e : events) {
        if (e.type) {
            int x1 = e.x1 + abs(min(0ll, minx)) + 1;
            int x2 = e.x2 + abs(min(0ll, minx)) + 1;
            ans += bit.sum(x1, x2);
        }
        else {
            if (e.start_or_end) {
                int x = e.x1 + abs(min(0ll, minx)) + 1;
                bit.add(x, 1);
            }
            else {
                int x = e.x1 + abs(min(0ll, minx)) + 1;
                bit.add(x, -1);
            }
        }
    }

    cout << ans << endl;


    return 0;
}
