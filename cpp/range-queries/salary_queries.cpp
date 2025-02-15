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

int n, m, t, arr[N], seg[4 * N];
set<int> s;
unordered_map<int, int> salary_to_index;
vector<Query> queries;

void update(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        seg[v] += val;
        return;
    }

    int tm = (tl + tr) / 2;

    if (pos <= tm) {
        update(v * 2, tl, tm, pos, val);
    } else {
        update(v * 2 + 1, tm + 1, tr, pos, val);
    }

    seg[v] = seg[v * 2] + seg[v * 2 + 1];
}

int get(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (l == tl && r == tr) {
        return seg[v];
    }

    int tm = (tl + tr) / 2;
    return get(v * 2, tl, tm, l, min(r, tm)) +
           get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

int32_t main() {
    // fri("in.txt");
    // fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        s.insert(arr[i]);
    }

    char c;
    int a, b;

    for (int i = 0; i < m; i++) {
        cin >> c >> a >> b;
        queries.pb(Query(c, a, b));

        if (c == '!') {
            s.insert(b);
        }
    }

    s.insert(0);
    salary_to_index[0] = 0;

    int cnt = 1;
    for (auto e : s) {
        salary_to_index[e] = cnt;
        cnt++;
    }

    s.insert(MOD);
    salary_to_index[MOD] = N - 1;

    for (int i = 0; i < n; i++) {
        update(1, 0, N - 1, salary_to_index[arr[i]], 1);
    }

    for (int i = 0; i < m; i++) {
        if (queries[i].c == '?') {
            a = *s.lower_bound(queries[i].a);
            b = *(--s.upper_bound(queries[i].b));

            cout << get(1, 0, N - 1, salary_to_index[a], salary_to_index[b])
                 << endl;
        } else {
            update(1, 0, N - 1, salary_to_index[arr[queries[i].a - 1]], -1);
            arr[queries[i].a - 1] = queries[i].b;
            update(1, 0, N - 1, salary_to_index[arr[queries[i].a - 1]], 1);
        }
    }

    return 0;
}
