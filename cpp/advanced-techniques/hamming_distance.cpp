#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define f1 first
#define s2 second
#define pb push_back
#define mp make_pair
#define fri(a) freopen(a, "r", stdin);
#define fro(a) freopen(a, "w", stdout);
const int MOD = 1e9 + 7;
const int N = 2e4 + 5;

int n, m, t, arr[N];

int bit_string_to_int(string s) {
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
        res *= 2;
        if (s[i] == '1') {
            res++;
        }
    }

    return res;
}

int32_t main() {
    // fri("in.txt");
    // fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int ans = 1e9;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        arr[i] = bit_string_to_int(s);
        for (int j = i - 1; j >= 0; j--) {
            ans = min(ans, __builtin_popcount(arr[i] ^ arr[j]));
        }
    }

    cout << ans << endl;
    return 0;
}
