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

int n, k, arr[N];
map<int, int> cnt;

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    int res = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        if (cnt[arr[i]] == 0) res++;
        cnt[arr[i]]++;
        if (i > k) {
            cnt[arr[i - k]]--;
            if (cnt[arr[i - k]] == 0)res--;
        }
        if (i >= k)cout << res << " ";
    }


    return 0;
}
