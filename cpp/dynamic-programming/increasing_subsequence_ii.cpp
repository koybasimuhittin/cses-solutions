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

int n, arr[N], dp[N], bit[N];
map<int, int> m;
set<int> s;

void add(int idx, int delta) {
    for (; idx < n; idx = idx | (idx + 1)) {
        bit[idx] += delta;
        bit[idx] %= MOD;
    }
}

int sum(int r) {
    int ret = 0;
    for (;r >= 0; r = (r & (r + 1)) - 1) {
        ret += bit[r];
        ret %= MOD;
    }
    return ret;
}

void compress() {
    int idx = 0;
    for (auto e : s) {
        m[e] = idx;
        idx++;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = m[arr[i]];
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
        s.insert(arr[i]);
    }

    compress();

    int res = 0;

    for (int i = 0; i < n; i++) {
        res = sum(arr[i] - 1);
        add(arr[i], res + 1);
    }

    cout << sum(n - 1) << endl;

    return 0;
}
