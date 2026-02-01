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
const int N = 1e7 + 5;

int n, k, x, a, b, c, arr[N], s, xor_xor;

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    cin >> x >> a >> b >> c;

    s = x;
    arr[0] = x;
    for (int i = 1; i < k; i++) {
        arr[i] = arr[i - 1] * a + b;
        arr[i] %= c;
        s ^= arr[i];
    }

    xor_xor ^= s;

    for (int i = k; i < n; i++) {
        s ^= arr[i % k];
        arr[i % k] = arr[(i - 1 + k) % k] * a + b;
        arr[i % k] %= c;

        s ^= arr[i % k];
        xor_xor ^= s;
    }

    cout << xor_xor << endl;

    return 0;
}
