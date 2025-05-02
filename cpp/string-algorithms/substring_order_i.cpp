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
#define mod(a, m) (a >= m ? a - m : a)
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;
const int P = 31;

int n, q, power[N], inverse_power[N], prefix_hash[N], suffix_array[N], c[N], cc[N], lcp[N];
string s;

int fast_pow(int a, int b) {
    int res = 1;
    int pow = 1;
    while (b > 0) {
        if (b & 1)res *= a;
        a *= a;
        res %= MOD;
        a %= MOD;
        b >>= 1;
    }
    return res;
}

int inverse(int a) {
    return fast_pow(a, MOD - 2);
}

void build_hash() {
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == '$') {
            prefix_hash[i] = prefix_hash[i - 1] + power[i - 1];
            prefix_hash[i] %= MOD;
        }
        else {

            prefix_hash[i] = prefix_hash[i - 1] + (s[i - 1] - 'a' + 2) * power[i - 1];
            prefix_hash[i] %= MOD;
        }
    }
}

int get_hash(int l, int r) {
    return (((prefix_hash[r] - prefix_hash[l - 1] + MOD) % MOD) * inverse_power[l - 1]) % MOD;
}

void counting_sort(int offset, int class_count) {
    vector<int> freq[class_count + 5];

    for (int i = 0; i < n; i++) {
        freq[c[mod(suffix_array[i] + offset, n)]].pb(suffix_array[i]);
    }

    int idx = 0;
    for (int i = 0; i <= class_count; i++) {
        for (auto e : freq[i]) {
            suffix_array[idx++] = e;
        }
    }
}

int repair_class(int offset) {
    cc[suffix_array[0]] = 0;
    for (int i = 1; i < n; i++) {
        if (c[suffix_array[i]] != c[suffix_array[i - 1]] || c[mod(suffix_array[i] + offset, n)] != c[mod(suffix_array[i - 1] + offset, n)]) {
            cc[suffix_array[i]] = cc[suffix_array[i - 1]] + 1;
        }
        else {
            cc[suffix_array[i]] = cc[suffix_array[i - 1]];
        }
    }

    for (int i = 0; i < n; i++) {
        c[i] = cc[i];
    }

    return c[suffix_array[n - 1]] + 1;
}

void build_suffix_array() {
    for (int i = 0; i < n; i++) {
        if (s[i] == '$')c[i] = 0;
        else {
            c[i] = s[i] - 'a' + 1;
        }
        suffix_array[i] = i;
    }

    int class_count = 30;

    for (int k = 2; k < 2 * n; k *= 2) {
        counting_sort(k / 2, class_count);
        counting_sort(0, class_count);

        class_count = repair_class(k / 2);
    }
}

int calc_lcp(int i, int j) {
    // maximum possible match length
    int maxLen = n - max(i, j);
    int lo = 0, hi = maxLen;
    while (lo < hi) {
        // bias mid upward so loop terminates correctly
        int mid = (lo + hi + 1) >> 1;
        // compare substrings s[i..i+mid-1] and s[j..j+mid-1]
        if (get_hash(i + 1, i + mid) == get_hash(j + 1, j + mid)) {
            lo = mid;      // we can match at least mid characters
        }
        else {
            hi = mid - 1;  // too many—cut down
        }
    }
    return lo;
}
void build_lcp() {
    lcp[0] = 0;

    for (int i = 1; i < n; i++) {
        lcp[i] = calc_lcp(suffix_array[i], suffix_array[i - 1]);
    }
}



int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s >> q;
    s = s + "$";
    n = s.size();

    power[0] = 1;
    inverse_power[0] = 1;
    int inverse_p = inverse(P);
    for (int i = 1; i < N; i++) {
        power[i] = P * power[i - 1];
        inverse_power[i] = inverse_p * inverse_power[i - 1];

        power[i] %= MOD;
        inverse_power[i] %= MOD;
    }

    build_hash();
    build_suffix_array();
    build_lcp();

    for (int i = 1; i < n; i++) {
        int substring_cnt = n - suffix_array[i] - 1 - lcp[i];
        if (q - substring_cnt <= 0) {
            for (int j = 0; j < lcp[i] + q; j++) {
                cout << s[suffix_array[i] + j];
            }
            cout << endl;
            break;
        }
        q -= substring_cnt;
    }



    return 0;
}
