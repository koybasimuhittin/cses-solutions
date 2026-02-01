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

int n, arr[N], cnt[N];
vector<int> primes;
vector<bool> is_prime(N, true);

void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.pb(i);
            for (int j = i * i; j <= n; j += i)is_prime[j] = false;
        }
    }
}

int dfs(int node) {
    int nxt = arr[node];
    arr[node] = -1;
    if (nxt == -1) return 0;
    return dfs(nxt) + 1;
}

int fpow(int a, int b) {
    if (b == 0) return 1;
    int x = fpow(a, b / 2);
    return ((x * x) % MOD) * ((b & 1) ? a : 1) % MOD;
}


int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    sieve();

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++) {
        if (arr[i] != -1) {
            int l = dfs(i);
            for (int j = 0; j < primes.size() && l > 1; j++) {
                if (is_prime[l]) {
                    cnt[l] = max(cnt[l], 1ll);
                    l = 1;
                }
                int c = 0;
                while (l > 1 && (l % primes[j] == 0)) {
                    l /= primes[j];
                    c++;
                }
                cnt[primes[j]] = max(cnt[primes[j]], c);
            }

        }
    }

    int lcm = 1;
    for (int i = 2; i <= n; i++) {
        lcm *= fpow(i, cnt[i]);
        lcm %= MOD;
    }

    cout << lcm << endl;

    return 0;
}
