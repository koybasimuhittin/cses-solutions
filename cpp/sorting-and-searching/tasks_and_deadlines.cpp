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

int n, a, b, ans;
vector<int> v;

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        ans += b - a;
        v.pb(a);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        ans -= i * v[n - i - 1];
    }

    cout << ans << endl;


    return 0;
}
