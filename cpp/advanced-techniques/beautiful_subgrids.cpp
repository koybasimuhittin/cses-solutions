#include <bits/stdc++.h>

#pragma GCC target("popcnt")

using namespace std;

#define endl '\n'
#define f1 first
#define s2 second
#define pb push_back
#define mp make_pair
#define fri(a) freopen(a, "r", stdin);
#define fro(a) freopen(a, "w", stdout);
const int MOD = 1e9 + 7;
const int N = 3e3 + 5;

int n, m, t, arr[N];
vector<bitset<N>> v;

int32_t main() {
    // fri("in.txt");
    // fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    string s;

    long long ans = 0;

    for (int i = 0; i < n; i++) {
        cin >> s;
        bitset<N> bs(s);

        v.pb(bs);

        for (int j = i - 1; j >= 0; j--) {
            int cnt = (bs & v[j]).count();

            ans += cnt * (cnt - 1) / 2;
        }
    }

    cout << ans << endl;

    return 0;
}
