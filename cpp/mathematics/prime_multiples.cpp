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
const int N = 21;

int n, m, t, arr[N];
vector<int> v;

int32_t main() {
    // fri("in.txt");
    // fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int ans = 0;

    for (int i = 0; i < m; i++) {
        cin >> arr[i];
    }

    for (int mask = 1; mask < (1 << m); mask++) {
        int temp = n;
        int cnt = 0;

        for (int j = 0; j < m; j++) {
            if (mask & (1 << j)) {
                temp /= arr[j];
                cnt++;
            }
        }
        if (cnt % 2 == 1) {
            ans += temp;
        } else {
            ans -= temp;
        }
    }

    cout << ans << endl;

    return 0;
}
