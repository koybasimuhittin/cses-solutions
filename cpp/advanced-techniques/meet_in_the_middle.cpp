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

int32_t main() {

    // fri("in.txt");
    // fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];

    int n1 = n / 2, n2 = n - n1;
    vector<int> top_sums;
    top_sums.reserve(1 << n1);
    for (int mask = 0; mask < (1 << n1); mask++) {
        int sum = 0, x = mask;
        while (x) {
            int b = __builtin_ctzll(x);
            sum += arr[b];
            x &= x - 1;
        }
        top_sums.pb(sum);
    }

    vector<int> bottom_sums;
    bottom_sums.reserve(1 << n2);
    for (int mask = 0; mask < (1 << n2); mask++) {
        int sum = 0, x = mask;
        while (x) {
            int b = __builtin_ctzll(x);
            sum += arr[n1 + b];
            x &= x - 1;
        }
        bottom_sums.pb(sum);
    }

    sort(top_sums.begin(), top_sums.end());
    sort(bottom_sums.begin(), bottom_sums.end());

    int ans = 0;
    int i = 0, j = (int)bottom_sums.size() - 1;
    while (i < (int)top_sums.size() && j >= 0) {
        long long s = (long long)top_sums[i] + bottom_sums[j];
        if (s < m) {
            i++;
        }
        else if (s > m) {
            j--;
        }
        else {
            long long a = top_sums[i], b = bottom_sums[j];
            long long c1 = 0, c2 = 0;
            while (i < (int)top_sums.size() && top_sums[i] == a) {
                c1++; i++;
            }
            while (j >= 0 && bottom_sums[j] == b) {
                c2++; j--;
            }
            ans += c1 * c2;
        }
    }

    cout << ans << endl;
    return 0;
}
