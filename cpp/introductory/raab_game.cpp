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

int n, a, b, t;

int32_t main() {
    // fri("in.txt");
    // fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;

    while (t--) {
        cin >> n >> a >> b;

        int draw = n - a - b;
        if (draw < 0 || draw > n) {
            cout << "NO" << endl;
            continue;
        }

        bool found = false;
        for (int i = 0; i <= n - draw; i++) {
            int w1 = 0;
            int w2 = 0;

            for (int j = 0; j < n - draw; j++) {
                int curr = (j + i) % (n - draw);
                if (curr > j)
                    w2++;
                else if (curr < j)
                    w1++;
            }
            if (w1 == a && w2 == b) {
                found = true;
                cout << "YES" << endl;
                for (int k = 1; k <= n; k++) {
                    cout << k << " ";
                }
                cout << endl;
                for (int k = 1; k <= draw; k++) {
                    cout << k << " ";
                }
                for (int k = 1; k <= n - draw; k++) {
                    int pos = (k + i - 1) % (n - draw) + 1;
                    cout << pos + draw << " ";
                }
                cout << endl;
            }
        }
        if (!found) {
            cout << "NO" << endl;
        }
    }

    return 0;
}
