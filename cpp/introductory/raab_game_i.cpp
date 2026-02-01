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

int t, n, a, b, arr[N], brr[N];

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;

    while (t--) {
        cin >> n >> a >> b;

        if (a >= n || b >= n || n < a + b) {
            cout << "NO" << endl;
            continue;
        }

        int draw = n - a - b;
        if ((n - draw == a && a != 0) || (n - draw == b && b != 0)) {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;

        for (int i = 1; i <= n; i++) {
            arr[i] = brr[i] = i;
        }

        for (int i = draw + 1, cnt = 0; cnt < a; i++, cnt++) {
            brr[i] = n - cnt;
        }

        for (int i = n - b + 1, cnt = draw + 1; cnt <= b + draw + 1; cnt++, i++) {
            brr[i] = cnt;
        }

        for (int i = 1; i <= n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        for (int i = 1; i <= n; i++) {
            cout << brr[i] << " ";
        }
        cout << endl;

    }


    return 0;
}
