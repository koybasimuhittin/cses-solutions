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

int t, n;

void sieve(vector<int>& primes) {
    vector<bool> is_prime(N, true);

    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i < N; i++) {
        if (!is_prime[i])continue;
        primes.pb(i);
        for (int j = i * i; j < N; j += i) {
            is_prime[j] = false;
        }
    }
}

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> primes;
    sieve(primes);

    cin >> t;

    while (t--) {
        cin >> n;

        bool flag = true;
        int res = n + 1;
        while (flag) {
            for (auto& divisor : primes) {
                if (res % divisor == 0) {
                    if (res == divisor) {
                        flag = true;
                        break;
                    }
                    flag = false;
                    break;
                }
            }
            if (flag) {
                break;
            }
            res++;
            flag = true;
        }

        cout << res << endl;
    }

    return 0;
}
