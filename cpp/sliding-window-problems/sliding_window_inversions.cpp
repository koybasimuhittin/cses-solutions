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

int n, k, arr[N], bit[N];
unordered_map<int, int> m;
set<int> s;

void add(int idx, int delta) {
    for (; idx < n; idx = idx | (idx + 1)) {
        bit[idx] += delta;
    }
}

int sum(int r) {
    int ret = 0;
    for (;r >= 0; r = (r & (r + 1)) - 1) {
        ret += bit[r];
    }
    return ret;
}

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        s.insert(arr[i]);
    }
    int idx = 0;
    for (auto e : s) {
        m[e] = idx;
        idx++;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = m[arr[i]];
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (i >= k) {
            add(arr[i - k], -1);
            res -= sum(arr[i - k] - 1);
        }
        add(arr[i], 1);
        res += min(k, i + 1) - sum(arr[i]);
        if (i >= k - 1) {
            cout << res << endl;
        }
    }

    return 0;
}
