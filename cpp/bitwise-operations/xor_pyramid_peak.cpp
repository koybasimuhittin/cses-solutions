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

int n, arr[N], brr[N];

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    while (n > 1) {
        for (int i = 30; i >= 0; i--) {
            if (n & (1 << i)) {
                int curr = 0;
                for (int j = 1; j <= n; j++) {
                    curr ^= arr[j - 1];
                    if (j >= (1 << i)) {
                        brr[j - (1 << i)] = curr;
                        curr ^= arr[j - (1 << i)];
                    }
                }
                n -= (1 << i) - 1;
                swap(arr, brr);
                break;
            }
        }
    }

    cout << arr[0] << endl;
    return 0;
}
