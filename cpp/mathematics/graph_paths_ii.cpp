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
const int N = 2e5 + 5;

static const int INF = 4000000000000000000LL;

int n, m, k;

vector<vector<int>> mat_mul(vector<vector<int>>& a, vector<vector<int>>& b) {
    int sz = a.size();
    vector<vector<int>> c(sz, vector<int>(sz, INF));
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            for (int t = 0; t < sz; t++) {
                c[i][j] = min(c[i][j], a[i][t] + b[t][j]);
            }
        }
    }
    return c;
}

vector<vector<int>> fast_pow(vector<vector<int>>& a, int e) {
    int sz = a.size();
    vector<vector<int>> I(sz, vector<int>(sz, INF));
    for (int i = 0; i < sz; i++) {
        I[i][i] = 0;
    }
    if (e == 0) return I;
    if (e == 1) return a;
    auto half = fast_pow(a, e / 2);
    auto sq = mat_mul(half, half);
    if (e & 1) return mat_mul(sq, a);
    return sq;
}

int32_t main() {
    // fri("in.txt");
    // fro("out.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    vector<vector<int>> f(n, vector<int>(n, INF));

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        f[a][b] = min(f[a][b], c);
    }

    auto D = fast_pow(f, k);
    int ans = D[0][n - 1];
    if (ans >= INF / 2)
        cout << -1 << endl;
    else
        cout << ans << endl;

    return 0;
}
