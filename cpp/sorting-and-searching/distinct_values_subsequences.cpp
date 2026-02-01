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

int n, ans, arr[N];
unordered_map<int, int> cnt;

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        cnt[arr[i]]++;
    }

    int ans = 1;

    for (int i = 0; i < n; i++) {
        ans *= (cnt[arr[i]] + 1);
        ans %= MOD;

        cnt[arr[i]] = 0;
    }

    cout << ans - 1 << endl;


    return 0;
}
