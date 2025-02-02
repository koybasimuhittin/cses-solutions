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

int n, m, arr[N], ans;

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int l = 0;
    int curr = 0;

    for (int r = 0; r < n; r++) {
        curr += arr[r];

        while (l <= r && curr > m) {
            curr -= arr[l];
            l += 1;
        }

        if (curr == m) ans += 1;
    }

    cout << ans << endl;


    return 0;
}
