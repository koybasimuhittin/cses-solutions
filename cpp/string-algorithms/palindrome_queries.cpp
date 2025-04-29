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
int n, q, prefix_hash[N], suffix_hash[N], power[N], inverse_power[N], prefix_seg[4 * N], suffix_seg[4 * N];

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
    for (int i = 0; i < n; i++) {
        prefix_hash[i] = (s[i] - 'a' + 1) * power[i];
        prefix_hash[i] %= MOD;
    }

    for (int i = n - 1; i >= 0; i--) {
        suffix_hash[i] = (s[i] - 'a' + 1) * power[n - 1 - i];
        suffix_hash[i] %= MOD;
    }
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        prefix_seg[v] = prefix_hash[tl];
        suffix_seg[v] = suffix_hash[tl];
    }
    else {
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        prefix_seg[v] = (prefix_seg[v * 2] + prefix_seg[v * 2 + 1]) % MOD;
        suffix_seg[v] = (suffix_seg[v * 2] + suffix_seg[v * 2 + 1]) % MOD;
    }
}

int get_prefix(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (l == tl && r == tr) {
        return prefix_seg[v];
    }
    int tm = (tl + tr) / 2;
    return (get_prefix(v * 2, tl, tm, l, min(r, tm)) + get_prefix(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r)) % MOD;
}

int get_suffix(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (l == tl && r == tr) {
        return suffix_seg[v];
    }
    int tm = (tl + tr) / 2;
    return (get_suffix(v * 2, tl, tm, l, min(r, tm)) + get_suffix(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r)) % MOD;
}

void update_prefix(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        prefix_seg[v] = new_val;
    }
    else {
        int tm = (tl + tr) / 2;
        if (pos <= tm) {
            update_prefix(v * 2, tl, tm, pos, new_val);
        }
        else {
            update_prefix(v * 2 + 1, tm + 1, tr, pos, new_val);
        }
        prefix_seg[v] = (prefix_seg[v * 2] + prefix_seg[v * 2 + 1]) % MOD;
    }
}

void update_suffix(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        suffix_seg[v] = new_val;
    }
    else {
        int tm = (tl + tr) / 2;
        if (pos <= tm) {
            update_suffix(v * 2, tl, tm, pos, new_val);
        }
        else {
            update_suffix(v * 2 + 1, tm + 1, tr, pos, new_val);
        }
        suffix_seg[v] = (suffix_seg[v * 2] + suffix_seg[v * 2 + 1]) % MOD;
    }
}

int get_prefix_hash(int l, int r) {
    int hash = get_prefix(1, 0, n - 1, l, r);
    hash += MOD;
    hash %= MOD;

    return hash * inverse_power[l] % MOD;
}

int get_suffix_hash(int l, int r) {
    int hash = get_suffix(1, 0, n - 1, l, r);
    hash += MOD;
    hash %= MOD;

    return hash * inverse_power[n - 1 - r] % MOD;
}



int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int inv = inverse(P);

    inverse_power[0] = 1;
    power[0] = 1;

    for (int i = 1; i < N; i++) {
        power[i] = (power[i - 1] * P) % MOD;
        inverse_power[i] = (inverse_power[i - 1] * inv) % MOD;
    }

    cin >> n >> q;
    cin >> s;

    calc_hash();
    build(1, 0, n - 1);

    int a, b;
    char c;
    for (int i = 0; i < q; i++) {
        cin >> a;
        if (a == 1) {
            cin >> b >> c;
            b--;
            s[b] = c;
            prefix_hash[b] = (s[b] - 'a' + 1) * power[b];
            prefix_hash[b] %= MOD;
            suffix_hash[b] = (s[b] - 'a' + 1) * power[n - 1 - b];
            suffix_hash[b] %= MOD;
            update_prefix(1, 0, n - 1, b, prefix_hash[b]);
            update_suffix(1, 0, n - 1, b, suffix_hash[b]);
        }
        else {
            cin >> a >> b;
            if (get_prefix_hash(a - 1, b - 1) == get_suffix_hash(a - 1, b - 1)) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}
