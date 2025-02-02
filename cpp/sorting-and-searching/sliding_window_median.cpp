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

int find_median(int low, int high) {
    while (low < high) {
        int mid = (low + high) / 2;
        int sum = get(1, 0, v.size(), 0, mid);

        if (sum >= (m + 1) / 2) {
            high = mid;
        }
        else {
            low = mid + 1;
        }
    }

    return low;
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
    }

    cout << v[find_median(0, v.size())] << " ";

    for (int i = m; i < n; i++) {
        update(1, 0, v.size(), num_to_index[arr[i]], 1);
        update(1, 0, v.size(), num_to_index[arr[i - m]], -1);
        cout << v[find_median(0, v.size())] << " ";
    }

    cout << endl;




    return 0;
}
