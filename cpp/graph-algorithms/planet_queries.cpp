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
const int M = 32;

int n, m, q, dp[N][M];

int get_nth_planet(int planet, int n) {
    for (int i = 0; i < M; i++) {
        if (n & (1 << i)) {
            planet = dp[planet][i];
        }
    }

    return planet;
}

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> dp[i][0];
    }

    for (int i = 1; i < M; i++) {
        for (int j = 1; j <= n; j++) {
            dp[j][i] = dp[dp[j][i - 1]][i - 1];
        }
    }

    int a, b;
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        cout << get_nth_planet(a, b) << endl;
    }


    return 0;
}
