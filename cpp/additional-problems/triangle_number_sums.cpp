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

int n, m, t, arr[N];
vector<int> v;

int32_t main() {

    fri("in.txt");
    fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;

    while (t--) {
        cin >> n;

        int res = 0;
        while (n > 0) {
            int low = 0, high = n;

            while (low < high) {
                int mid = (low + high) / 2;
                int tri = mid * (mid + 1) / 2;
                if (tri <= n) low = mid;
                else high = mid - 1;
            }

            int k = low - 1;
            n -= k * (k + 1) / 2;
            res++;
        }

        cout << res << "\n";


    }


    return 0;
}
