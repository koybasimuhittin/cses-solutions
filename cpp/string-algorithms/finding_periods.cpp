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
int prefix_hash[N], power[N], inverse_power[N];

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

void calc_hash(string s) {
    for (int i = 0; i < s.size(); i++) {
        prefix_hash[i + 1] = prefix_hash[i] + (s[i] - 'a' + 1) * power[i];
        prefix_hash[i + 1] %= MOD;
    }
}

int get_hash(int l, int r) {
    int hash = prefix_hash[r + 1] - prefix_hash[l];
    hash += MOD;
    hash %= MOD;

    return hash * inverse_power[l] % MOD;
}

bool is_period(int l, int r) {

    int hash1 = get_hash(l, r);

    for (int ll = 0; ll < s.size(); ll += (r - l + 1)) {
        int rr = min((int)s.size() - 1ll, ll + (r - l));

        if (r > l + rr - ll) {
            hash1 = get_hash(l, l + rr - ll);
        }

        int hash2 = get_hash(ll, rr);

        if (hash1 != hash2) {
            return false;
        }
    }

    return true;
}


int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    power[0] = 1;
    inverse_power[0] = inverse(power[0]);

    for (int i = 1; i < N; i++) {
        power[i] = power[i - 1] * P;
        power[i] %= MOD;
        inverse_power[i] = inverse(power[i]);
    }

    cin >> s;

    calc_hash(s);

    for (int i = 0; i < s.size(); i++) {
        if (is_period(0, i)) {
            cout << i + 1 << " ";
        }
    }

    return 0;
}
