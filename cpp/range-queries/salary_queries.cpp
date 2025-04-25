#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define f1 first
#define s2 second
#define pb push_back
#define mp make_pair
#define fri(a) freopen(a, "r", stdin);
#define fro(a) freopen(a, "w", stdout);
const int MOD = 1e9 + 7;
const int N = 4e5 + 5;

typedef struct Query {
    char c;
    int a, b;

    Query(char _c, int _a, int _b) {
        c = _c;
        a = _a;
        b = _b;
    }
} Query;

int n, m, t, arr[N];
int seg[4 * N];
vector<Query> queries;
vector<int> vals;
int base;

void update(int pos, int val) {
    pos += base;
    seg[pos] += val;
    for (pos /= 2; pos; pos /= 2)
        seg[pos] = seg[2 * pos] + seg[2 * pos + 1];
}

int get(int l, int r) {
    int res = 0;
    l += base;
    r += base;
    while (l <= r) {
        if (l & 1) res += seg[l++];
        if (!(r & 1)) res += seg[r--];
        l /= 2;
        r /= 2;
    }
    return res;
}

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        vals.pb(arr[i]);
    }

    char c;
    int a, b;

    for (int i = 0; i < m; i++) {
        cin >> c >> a >> b;
        queries.pb(Query(c, a, b));
        if (c == '!') vals.pb(b);
    }

    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    base = 1;
    while (base < (int)vals.size()) base <<= 1;

    for (int i = 0; i < 2 * base; i++) seg[i] = 0;

    for (int i = 0; i < n; i++) {
        int idx = lower_bound(vals.begin(), vals.end(), arr[i]) - vals.begin();
        update(idx, 1);
    }

    for (int i = 0; i < m; i++) {
        c = queries[i].c;
        a = queries[i].a;
        b = queries[i].b;

        if (c == '?') {
            int l = lower_bound(vals.begin(), vals.end(), a) - vals.begin();
            int r = upper_bound(vals.begin(), vals.end(), b) - vals.begin() - 1;
            if (l > r) cout << 0 << endl;
            else cout << get(l, r) << endl;
        }
        else {
            int old = lower_bound(vals.begin(), vals.end(), arr[a - 1]) - vals.begin();
            update(old, -1);
            arr[a - 1] = b;
            int now = lower_bound(vals.begin(), vals.end(), b) - vals.begin();
            update(now, 1);
        }
    }

    return 0;
}
