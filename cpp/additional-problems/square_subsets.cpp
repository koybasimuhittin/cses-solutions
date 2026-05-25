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
const int M = 700;

int n, x, basis_rank;
vector<int> primes;
bitset<M> basis[M];

int fpow(int a, int b) {
    if (b <= 0)return 1;
    int x = fpow(a, b / 2) % MOD;
    return (((x * x) % MOD) * ((b & 1) ? a : 1)) % MOD;
}

bitset<M> reduce(bitset<M> x) {
    for (int i = M - 1; i >= 0; i--) {
        if (x.test(i)) {
            x ^= basis[i];
        }
    }

    return x;
}

void insert_into_basis(bitset<M> x) {
    x = reduce(x);
    for (int i = M - 1; i >= 0; i--) {
        if (x.test(i)) {
            basis[i] = x;
            basis_rank++;
            return;
        }
    }
}

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 2; i < N && primes.size() < M; i++) {
        bool is_prime = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0)is_prime = false;
        }
        if (is_prime)primes.pb(i);
    }

    cin >> n;
    int removed_cnt = 0, res = 0;

    for (int i = 0; i < n; i++) {
        cin >> x;

        bitset<M> bitset_x;
        for (int j = 0; j < M; j++) {
            int cnt = 0;
            while (x % primes[j] == 0) {
                x /= primes[j];
                cnt++;
            }
            if (cnt % 2)bitset_x.set(j);
        }
        //cout << bitwise_x << endl;
        if (x != 1) {
            removed_cnt++;
            continue;
        }
        bitset<M> reduced = reduce(bitset_x);
        if (reduced == 0) {
            res += fpow(2, (i - removed_cnt - basis_rank));
            res %= MOD;
        }
        insert_into_basis(reduced);
    }

    cout << (res + 1) % MOD << endl;

    return 0;
}
