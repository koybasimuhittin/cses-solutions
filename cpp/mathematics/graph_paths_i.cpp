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

int n, m, k;

vector<vector<int>> mat_mul(vector<vector<int>>& a, vector<vector<int>>& b) {
    vector<vector<int>> c(a.size(), vector<int>(b[0].size(), 0));

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b[0].size(); j++) {
            for (int k = 0; k < a[0].size(); k++) {
                c[i][j] += (a[i][k] * b[k][j]) % MOD;
                c[i][j] %= MOD;
            }
        }
    }

    return c;
}

vector<vector<int>> fast_pow(vector<vector<int>>& a, int b) {
    vector<vector<int>> res(a.size(), vector<int>(a[0].size(), 0));

    for (int i = 0; i < a.size(); i++) {
        res[i][i] = 1;
    }

    if (b == 0) return res;

    res = fast_pow(a, b / 2);
    vector<vector<int>> temp = mat_mul(res, res);
    if (b & 1) {
        return mat_mul(temp, a);
    }
    return temp;
}

int32_t main() {
    // fri("in.txt");
    // fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;

    vector<vector<int>> f(n, vector<int>(n, 0));

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--;
        b--;
        f[a][b]++;
    }

    cout << fast_pow(f, k)[0][n - 1] << endl;

    return 0;
}
