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

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;

    while (t--) {
        cin >> n >> m;

        if (n < m)swap(n, m);

        if (n > 2 * m || (n + m) % 3) {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;


    }


    return 0;
}
