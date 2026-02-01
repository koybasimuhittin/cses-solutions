#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define f1 first
#define s2 second
#define pb push_back
#define mp make_pair
#define fri(a) freopen(a,"r",stdin);
#define fro(a) freopen(a,"w",stdout);
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;
const int M = 32;

int n, k;
long long x, a, b, c;
int prev_idx[M], cnt[M];

void update_window(int x, int idx) {
    while (x) {
        int i = __builtin_ctz(x);
        cnt[i] += max(0, idx - prev_idx[i] - k);
        prev_idx[i] = idx;
        x &= x - 1;
    }
}


int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    cin >> x >> a >> b >> c;
    update_window(x, 1);
    x %= c;
    a %= c;
    b %= c;
    for (int i = 2; i <= n; i++) {
        x = ((1LL * a * x + b) % c);
        update_window(x, i);
    }
    for (int i = 0; i < M; i++) {
        cnt[i] += max(0, n + 1 - prev_idx[i] - k);
    }

    int res = 0;
    for (int i = 0; i < M; i++) {
        if ((n - k + 1 - cnt[i]) & 1) {
            res |= (1 << i);
        }
    }
    cout << res << endl;

    return 0;
}
