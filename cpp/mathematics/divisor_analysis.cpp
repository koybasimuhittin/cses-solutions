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

int n;
vector<pair<int, int>> v;

int fpow(int a, int b, int mod) {
    if (b == 0)return 1;
    int x = fpow(a, b / 2, mod);
    return (((x * x) % mod) * ((b & 1) ? a : 1)) % mod;
}

int inverse(int a, int mod) {
    return fpow(a, mod - 2, mod);
}

int calc() {
    int product_of_divisors = 1;
    vector<int> pref(n + 1, 1), suff(n + 1, 1);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = (pref[i] * (v[i].s2 + 1)) % (MOD - 1);
    }
    for (int i = n - 1; i >= 0; i--) {
        suff[i] = (suff[i + 1] * (v[i].s2 + 1)) % (MOD - 1);
    }

    int a, b;
    for (int i = 0; i < n; i++) {
        a = v[i].f1;
        b = v[i].s2;
        product_of_divisors *= fpow(a, ((((b * (b + 1)) / 2) % (MOD - 1)) * ((pref[i] * suff[i + 1]) % (MOD - 1))) % (MOD - 1), MOD);
        product_of_divisors %= MOD;
    }

    return product_of_divisors;
}

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    int a, b;

    int divisor_count = 1;
    int sum_of_divisors = 1;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        divisor_count *= (b + 1);
        divisor_count %= MOD;
        sum_of_divisors *= (((fpow(a, b + 1, MOD) - 1 + MOD) % MOD) * inverse(a - 1, MOD)) % MOD;
        sum_of_divisors %= MOD;
        v.pb({ a, b });
    }

    int product_of_divisors = calc();
    cout << divisor_count << " " << sum_of_divisors << " " << product_of_divisors << endl;

    return 0;
}
