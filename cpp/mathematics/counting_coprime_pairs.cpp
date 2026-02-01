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
const int N = 1e6 + 5;

int n, m, cnt[N], prime_cnt[N];

void sieve() {
    bool is_prime[N];
    memset(is_prime, true, sizeof(is_prime));

    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < N; i++) {
        if (is_prime[i]) {
            prime_cnt[i]++;
            for (int j = i + i; j < N; j += i) {
                is_prime[j] = false;
                prime_cnt[j]++;
            }
            prime_cnt[i * i] = 0;
        }
    }
}

int32_t main() {
    // fri("in.txt");
    // fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> m;
        for (int j = 1; j * j <= m; j++) {
            if (m % j == 0) {
                cnt[j]++;
                if (j * j != m) {
                    cnt[m / j]++;
                }
            }
        }
    }

    int res = 0;
    sieve();
    for (int i = 1; i < N; i++) {
        if (prime_cnt[i] == 0) continue;
        if (prime_cnt[i] % 2 == 0) {
            res -= (cnt[i] * (cnt[i] - 1)) / 2;
        } else {
            res += (cnt[i] * (cnt[i] - 1)) / 2;
        }
    }

    cout << n * (n - 1) / 2 - res << endl;

    return 0;
}
