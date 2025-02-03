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
const int N = 1e3 + 5;
const int M = 11;

int n, m, dp[N][1 << M];
unordered_map<int, int> cnt[1 << M];

void generate_next_tilings(int initial, int index, int next_tiling) {
    if (index == m) {
        cnt[initial][next_tiling] += 1;
        return;
    }

    if (initial & (1 << index)) {
        generate_next_tilings(initial, index + 1, next_tiling);
    }
    else {
        if (index + 1 < m && ((initial & (1 << (index + 1)))) == 0) {
            generate_next_tilings(initial, index + 2, next_tiling);
        }
        generate_next_tilings(initial, index + 1, next_tiling | (1 << index));
    }
}

int calc(int index, int current_tiling) {
    if (index == n) {
        if (current_tiling == 0) return 1;
        return 0;
    }

    if (dp[index][current_tiling] != -1) {
        return dp[index][current_tiling];
    }

    dp[index][current_tiling] = 0;

    for (auto& next_tiling : cnt[current_tiling]) {
        dp[index][current_tiling] += (calc(index + 1, next_tiling.first) % MOD) * next_tiling.second;
        dp[index][current_tiling] %= MOD;
    }

    return dp[index][current_tiling];

}

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    if (n < m) {
        swap(n, m);
    }

    for (int i = 0; i < (1 << m); i++) {
        generate_next_tilings(i, 0, 0);
    }

    memset(dp, -1, sizeof(dp));

    cout << calc(0, 0) << endl;


    return 0;
}
