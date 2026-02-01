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

int n, prefix_hash[N], suffix_hash[N], power[N], inverse_power[N], dp[N];
string s;

int mod(int m) {
    return ((m % MOD) + MOD) % MOD;
}

int fpow(int a, int b) {
    if (b == 0)return 1;
    int x = fpow(a, b / 2);
    return mod(mod(x * x) * ((b & 1) ? a : 1));
}

int inverse(int a) {
    return fpow(a, MOD - 2);
}

void init() {
    int p = 31;
    int inv = inverse(p);
    power[0] = 1;
    inverse_power[0] = 1;

    for (int i = 1; i < N; i++) {
        power[i] = p * power[i - 1];
        power[i] = mod(power[i]);

        inverse_power[i] = inv * inverse_power[i - 1];
        inverse_power[i] = mod(inverse_power[i]);
    }

}

void calc_hashes() {
    for (int i = 0; i < n; i++) {
        prefix_hash[i + 1] = prefix_hash[i] + (s[i] - 'a' + 1) * power[i];
        prefix_hash[i + 1] = mod(prefix_hash[i + 1]);
    }

    for (int i = n - 1; i >= 0; i--) {
        suffix_hash[i] = suffix_hash[i + 1] + (s[i] - 'a' + 1) * power[n - i - 1];
        suffix_hash[i] = mod(suffix_hash[i]);
    }
}

int get_prefix_hash(int l, int r) {
    return mod((prefix_hash[r + 1] - prefix_hash[l]) * inverse_power[l]);
}
int get_suffix_hash(int l, int r) {
    return mod((suffix_hash[l] - suffix_hash[r + 1]) * inverse_power[n - r - 1]);
}

void calc_dp() {
    for (int i = 0; i < n; i++) {
        int low = 0;
        int high = min(i, n - i - 1);

        dp[i] = max(dp[i], 1LL);

        while (low < high) {
            int mid = (low + high + 1) / 2;

            if (get_prefix_hash(i - mid, i - 1) == get_suffix_hash(i + 1, i + mid)) {
                dp[i + mid] = max(dp[i + mid], 2 * mid + 1);
                low = mid;
            }
            else {
                high = mid - 1;
            }
        }

    }
    for (int i = 0; i < n - 1; i++) {
        if (s[i] != s[i + 1])continue;
        int low = 0;
        int high = min(i, n - i - 2);

        dp[i + 1] = max(dp[i + 1], 2LL);

        while (low < high) {
            int mid = (low + high + 1) / 2;

            if (get_prefix_hash(i - mid, i) == get_suffix_hash(i + 1, i + mid + 1)) {
                dp[i + mid + 1] = max(dp[i + mid + 1], 2 * mid + 2);
                low = mid;
            }
            else {
                high = mid - 1;
            }
        }
    }

    for (int i = n - 2; i >= 0; i--) {
        dp[i] = max(dp[i], dp[i + 1] - 2);
    }
}

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;

    n = s.size();

    init();
    calc_hashes();
    calc_dp();

    for (int i = 0; i < n; i++) {
        cout << dp[i] << " ";
    }

    return 0;
}
