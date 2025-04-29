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
const int N = 1e6 + 5;
const int P = 31;

string s;
int prefix_hash[N], suffix_hash[N], power[N], inverse_power[N];

int fast_pow(int a, int b) {
    if (b == 0) return 1;

    int x = fast_pow(a, b / 2);

    if (b & 1) {
        return ((x * x) % MOD) * a % MOD;
    }
    return x * x % MOD;
}

int inverse(int a) {
    return fast_pow(a, MOD - 2);
}

void calc_hash() {
    for (int i = 0; i < s.size(); i++) {
        prefix_hash[i + 1] = prefix_hash[i] + (s[i] - 'a' + 1) * power[i];
        prefix_hash[i + 1] %= MOD;
    }

    for (int i = s.size() - 1; i >= 0; i--) {
        suffix_hash[i] = suffix_hash[i + 1] + (s[i] - 'a' + 1) * power[s.size() - 1 - i];
        suffix_hash[i] %= MOD;
    }
}

int get_prefix_hash(int l, int r) {
    int hash = prefix_hash[r + 1] - prefix_hash[l];
    hash += MOD;
    hash %= MOD;

    return hash * inverse_power[l] % MOD;
}

int get_suffix_hash(int l, int r) {
    int hash = suffix_hash[l] - suffix_hash[r + 1];
    hash += MOD;
    hash %= MOD;

    return hash * inverse_power[s.size() - 1 - r] % MOD;
}

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;

    int inv = inverse(P);

    inverse_power[0] = 1;
    power[0] = 1;

    for (int i = 1; i < N; i++) {
        power[i] = (power[i - 1] * P) % MOD;
        inverse_power[i] = (inverse_power[i - 1] * inv) % MOD;
    }

    calc_hash();

    int ans = 0;
    int l_idx, r_idx;

    for (int i = 0; i < s.size(); i++) {
        int low = 0;
        int high = min(i, (int)s.size() - i - 1);

        if (ans < 1) {
            ans = 1;
            l_idx = i;
            r_idx = i;
        }


        while (low < high) {
            int mid = (low + high + 1) / 2;

            int l = i - mid;
            int r = i + mid;

            if (get_prefix_hash(l, i - 1) == get_suffix_hash(i + 1, r)) {
                if (ans < 2 * mid + 1) {
                    ans = 2 * mid + 1;
                    l_idx = l;
                    r_idx = r;
                }
                low = mid;
            }
            else {
                high = mid - 1;
            }
        }
    }

    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == s[i + 1]) {
            int low = 0;
            int high = min(i, (int)s.size() - i - 2);

            if (ans < 2) {
                ans = 2;
                l_idx = i;
                r_idx = i + 1;
            }

            while (low < high) {
                int mid = (low + high + 1) / 2;

                int l = i - mid;
                int r = i + mid + 1;

                if (get_prefix_hash(l, i - 1) == get_suffix_hash(i + 2, r)) {
                    if (ans < 2 * mid + 2) {
                        ans = 2 * mid + 2;
                        l_idx = l;
                        r_idx = r;
                    }
                    low = mid;
                }
                else {
                    high = mid - 1;
                }
            }
        }
    }

    for (int i = l_idx; i <= r_idx; i++) {
        cout << s[i];
    }
    cout << endl;





    return 0;
}
