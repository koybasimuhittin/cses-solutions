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
const int INV_TWO = 500000004;


int n, res;

int gauss(int l, int r) {
    return (((((r + l) % MOD) * ((r - l + 1 + MOD) % MOD)) % MOD) * INV_TWO) % MOD;
}

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    int prev = 1;
    int res = 0;
    while (prev * prev <= n) {
        res += ((n / prev) * prev) % MOD;
        res %= MOD;
        prev++;
    }

    for (int i = n / prev; i >= 1; i--) {
        res += (gauss(prev, n / i) * (i % MOD)) % MOD;
        res %= MOD;
        prev = n / i + 1;
    }

    cout << res << endl;


    return 0;
}
