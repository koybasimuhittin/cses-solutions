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

int n, arr[N], prefix_inversion[N], suffix_inversion[N], seg[4 * N];

void compress() {
    map<int, int> mp;
    int arr_copy[N];
    copy(arr, arr + n, arr_copy);
    sort(arr_copy, arr_copy + n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (mp.find(arr_copy[i]) == mp.end()) {
            mp[arr_copy[i]] = ++cnt;
        }
    }

    for (int i = 0; i < n; i++) {
        arr[i] = mp[arr[i]];
    }
}

void update(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        seg[v] += val;
        return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm)update(v * 2, tl, tm, pos, val);
    else update(v * 2 + 1, tm + 1, tr, pos, val);
    seg[v] = seg[v * 2] + seg[v * 2 + 1];
}

int get(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (l <= tl && r >= tr)return seg[v];
    int tm = (tl + tr) / 2;
    return get(v * 2, tl, tm, l, min(r, tm)) + get(v * 2 + 1, tm + 1, r, max(l, tm + 1), r);
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

    for (int i = 0; i < n; i++) {
        prefix_inversion[i + 1] = get(1, 0, n, arr[i] + 1, n);
        prefix_inversion[i + 1] += prefix_inversion[i];
        update(1, 0, n, arr[i], 1);
    }

    fill(begin(seg), end(seg), 0);
    int res = prefix_inversion[n];

    for (int i = n - 1; i > 0; i--) {
        suffix_inversion[i] = get(1, 0, n, arr[i] + 1, n);
        suffix_inversion[i] += suffix_inversion[i + 1];
        res = min(res, prefix_inversion[i] + suffix_inversion[i]);
        update(1, 0, n, arr[i], 1);
    }

    cout << res << endl;


    return 0;
}
