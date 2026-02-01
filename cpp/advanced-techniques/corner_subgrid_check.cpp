#include <bits/stdc++.h>
#pragma GCC optimize("O3", "Ofast")
#pragma GCC target("avx,avx2,fma", "popcnt")

using namespace std;

#define endl '\n'
#define f1 first
#define s2 second
#define pb push_back
#define mp make_pair
#define fri(a) freopen(a,"r",stdin);
#define fro(a) freopen(a,"w",stdout);
const int MOD = 1e9 + 7;
const int N = 3e3;

bitset<N> v[26][N];
unordered_set<bitset<N>> seen[26];
int n, m, grid[N][N];


int32_t main() {

    fri("in.txt");
    fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < n; j++) {
            grid[i][j] = s[j] - 'A';
        }
    }
    int idx, idx_low;
    for (int c = 0; c < m; c++) {
        bool flag = false;
        idx = 0;
        bitset<N> bs;
        for (int i = 0; i < n && !flag; i++) {
            bs = 0;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == c) {
                    bs.set(j, true);
                }
            }
            if (bs.count() < 2 || seen[c].count(bs) != 0)continue;
            for (int j = idx - 1; j >= 0 && !flag; j--) {
                if ((bs & (v[c][j])).count() >= 2) {
                    flag = true;
                }
            }
            v[c][idx] = bs;
            seen[c].insert(bs);
            idx++;
        }

        if (flag) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
