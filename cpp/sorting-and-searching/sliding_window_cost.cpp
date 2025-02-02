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

int n, m, t, arr[N], seg[4 * N], sum_seg[4 * N];
vector<int> v;
map<int, int> num_to_index;
unordered_set<int> s;

void update(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        seg[v] += val;
        return;
    }

    int tm = (tl + tr) / 2;

    if (pos <= tm) {
        update(v * 2, tl, tm, pos, val);
    }
    else {
        update(v * 2 + 1, tm + 1, tr, pos, val);
    }

    seg[v] = seg[v * 2] + seg[v * 2 + 1];
}

int get(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (tl == l && tr == r) return seg[v];

    int tm = (tl + tr) / 2;

    return get(v * 2, tl, tm, l, min(r, tm)) + get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

void update_sum(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        sum_seg[v] += val;
        return;
    }

    int tm = (tl + tr) / 2;

    if (pos <= tm) {
        update_sum(v * 2, tl, tm, pos, val);
    }
    else {
        update_sum(v * 2 + 1, tm + 1, tr, pos, val);
    }

    sum_seg[v] = sum_seg[v * 2] + sum_seg[v * 2 + 1];
}

int get_sum(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (tl == l && tr == r) return sum_seg[v];

    int tm = (tl + tr) / 2;

    return get_sum(v * 2, tl, tm, l, min(r, tm)) + get_sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

int find_median(int v, int tl, int tr, int searching) {
    if (tl == tr) {
        return tl;
    }

    int tm = (tl + tr) / 2;
    if (seg[v * 2] >= searching) {
        return find_median(v * 2, tl, tm, searching);
    }
    return find_median(v * 2 + 1, tm + 1, tr, searching - seg[v * 2]);
}

int calc_cost(int median) {
    int cnt_less_than_median = get(1, 0, v.size(), 0, median - 1);
    int cnt_more_than_median = get(1, 0, v.size(), median + 1, v.size());

    int sum_less_than_median = get_sum(1, 0, v.size(), 0, median - 1);
    int sum_more_than_median = get_sum(1, 0, v.size(), median + 1, v.size());

    return cnt_less_than_median * v[median] - sum_less_than_median + sum_more_than_median - cnt_more_than_median * v[median];
}

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (s.find(arr[i]) == s.end()) {
            v.pb(arr[i]);
            s.insert(arr[i]);
        }
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        num_to_index[v[i]] = i;
    }

    for (int i = 0; i < m; i++) {
        update(1, 0, v.size(), num_to_index[arr[i]], 1);
        update_sum(1, 0, v.size(), num_to_index[arr[i]], arr[i]);
    }

    cout << calc_cost(find_median(1, 0, v.size(), (m + 1) / 2)) << " ";

    for (int i = m; i < n; i++) {
        update(1, 0, v.size(), num_to_index[arr[i]], 1);
        update(1, 0, v.size(), num_to_index[arr[i - m]], -1);
        update_sum(1, 0, v.size(), num_to_index[arr[i]], arr[i]);
        update_sum(1, 0, v.size(), num_to_index[arr[i - m]], -arr[i - m]);
        cout << calc_cost(find_median(1, 0, v.size(), (m + 1) / 2)) << " ";
    }

    cout << endl;




    return 0;
}
