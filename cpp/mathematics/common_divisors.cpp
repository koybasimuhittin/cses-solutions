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
const int N = 1e6 + 5;

int n, a, cnt[N];

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a;
        cnt[a]++;
    }

    for (int i = N - 1; i >= 1; i--) {
        int sum = 0;
        for (int j = i; j < N; j += i) {
            sum += cnt[j];
        }

        if (sum > 1) {
            cout << i << endl;
            break;
        }

    }

    return 0;
}
