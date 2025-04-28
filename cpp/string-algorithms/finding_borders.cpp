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
int prefix_hash[N], power[N];

int fast_pow(int a, int b) {
    if (b == 0) return 1;
    int x = fast_pow(a, b / 2);

    if (b & 1) return ((x * x) % MOD) * a % MOD;
    return (x * x) % MOD;
}

int inverse(int a) {
    return fast_pow(a, MOD - 2);
}

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    power[0] = 1;

    for (int i = 1; i < N; i++) {
        power[i] = power[i - 1] * P;
        power[i] %= MOD;
    }

    cin >> s;

    int ans = 0;

    for (int i = 0; i < s.size(); i++) {
        prefix_hash[i + 1] = prefix_hash[i] + (s[i] - 'a' + 1) * power[i];
        prefix_hash[i + 1] %= MOD;
    }

    for (int i = 0; i < s.size() - 1; i++) {
        int prefix = prefix_hash[i + 1];
        int suffix = (prefix_hash[s.size()] - prefix_hash[s.size() - i - 1] + MOD) % MOD;

        suffix *= inverse(power[s.size() - i - 1]);
        suffix %= MOD;

        if (prefix == suffix) {
            cout << i + 1 << " ";
        }
    }

    return 0;
}
