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
const int N = 41;

int n, m, arr[N];
unordered_map<int, int> cnt;

int32_t main() {
    // fri("in.txt");
    // fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans = 0;

    for (int mask = 0; mask < (1 << (n / 2)); mask++) {
        int sum = 0;
        for (int i = 0; i < n / 2; i++) {
            if (mask & (1 << i)) {
                sum += arr[i];
            }
        }
        cnt[sum]++;
    }

    for (int mask = 0; mask < (1 << (n - n / 2)); mask++) {
        int sum = 0;
        for (int i = 0; i < n - n / 2; i++) {
            if (mask & (1 << i)) {
                sum += arr[i + n / 2];
            }
        }
        if (m - sum >= 0) {
            ans += cnt[m - sum];
        }
    }

    cout << ans << endl;

    return 0;
}
