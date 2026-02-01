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

int n, m, t, arr[N], seg[4 * N];
vector<int> v;

void update(int v, int tl, int tr, int pos, int val) {
    if (tl == tr)seg[v] += val;
    else {
        int tm = (tl + tr) / 2;
        if (pos <= tm) update(v * 2, tl, tm, pos, val);
        else update(v * 2 + 1, tm + 1, tr, pos, val);
        seg[v] = seg[v * 2] + seg[v * 2 + 1];
    }
}

int get(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (l == tl && r == tr)return seg[v];
    int tm = (tl + tr) / 2;
    return get(v * 2, tl, tm, l, min(r, tm)) + get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

void compress() {
    vector<int> v;
    for (int i = 0; i < n; i++) {
        v.pb(arr[i]);
    }
    auto ip = unique(v.begin(), v.end());
    v.resize(distance(v.begin(), ip));
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        arr[i] = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
    }
}

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    compress();

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, get(1, 0, n - 1, arr[i] + 1, n - 1));
        update(1, 0, n - 1, arr[i], 1);
    }

    cout << ans << endl;

    return 0;
}
