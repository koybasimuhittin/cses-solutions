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
const int N = 1e3 + 5;

int n, m, pref[N][N];

int32_t main() {
    // fri("in.txt");
    // fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= n; j++) {
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
            if (s[j - 1] == '*') {
                pref[i][j] += 1;
            }
        }
    }

    int y1, x1, y2, x2;
    while (m--) {
        cin >> y1 >> x1 >> y2 >> x2;

        cout << pref[y2][x2] - pref[y2][x1 - 1] - pref[y1 - 1][x2] +
                    pref[y1 - 1][x1 - 1]
             << endl;
    }

    return 0;
}
