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

int n, m, t, arr[N];
vector<int> v;

int32_t main() {
    fri("in.txt");
    fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;

    while (t--) {
        int x11, y11, x12, y12;
        int x21, y21, x22, y22;

        cin >> x11 >> y11 >> x12 >> y12;
        cin >> x21 >> y21 >> x22 >> y22;

        int m1 = abs(y11 - y12) * abs(x21 - x22);
        int m2 = abs(y21 - y22) * abs(x11 - x12);

        cout << m1 << " " << m2 << endl;

        if (m1 == m2) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }

    return 0;
}
