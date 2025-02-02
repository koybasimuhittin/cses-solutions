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

typedef struct Range {
    int l, r, index;

    Range(int l, int r, int index) {
        this->l = l;
        this->r = r;
        this->index = index;
    }
} Range;

int n, l, r, ans[N][2], seg[4 * N];
vector<Range> inputs;
set<int> rights;
map<int, int> right_to_index;

bool comp(const Range& a, const Range& b) {
    if (a.l == b.l) {
        return a.r >= b.r;
    }

    return a.l < b.l;
}

void update(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        seg[v] += 1;
        return;
    }

    int tm = (tl + tr) / 2;

    if (pos <= tm) {
        update(v * 2, tl, tm, pos);
    }
    else {
        update(v * 2 + 1, tm + 1, tr, pos);
    }

    seg[v] = seg[v * 2] + seg[v * 2 + 1];
}

int get(int v, int tl, int tr, int l, int r) {
    if (l > r)return 0;
    if (tl == l && tr == r) {
        return seg[v];
    }

    int tm = (tl + tr) / 2;

    return get(v * 2, tl, tm, l, min(r, tm)) + get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        inputs.pb(Range(l, r, i));
        rights.insert(r);
    }

    int curr = 1;
    for (auto& r : rights) {
        right_to_index[r] = curr;
        curr += 1;
    }

    sort(inputs.begin(), inputs.end(), comp);

    for (int i = 0; i < n; i++) {
        ans[inputs[i].index][1] = get(1, 0, n, right_to_index[inputs[i].r], n);
        update(1, 0, n, right_to_index[inputs[i].r]);
    }

    for (int i = 0; i < 4 * N; i++) seg[i] = 0;

    for (int i = n - 1; i >= 0; i--) {
        ans[inputs[i].index][0] = get(1, 0, n, 0, right_to_index[inputs[i].r]);
        update(1, 0, n, right_to_index[inputs[i].r]);
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i][0] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << ans[i][1] << " ";
    }
    cout << endl;


    return 0;
}
