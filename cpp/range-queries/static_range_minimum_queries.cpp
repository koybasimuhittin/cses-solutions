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

int n, m, sparse_table[N][20];

int find_min(int l, int r) {
    int j = log2(r - l + 1);
    return min(sparse_table[l][j], sparse_table[r - (1 << j) + 1][j]);

}

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> sparse_table[i][0];
    }

    for (int i = 1; i < 20; i++) {
        for (int j = 1; (1 << (i - 1)) + j <= n; j++) {
            sparse_table[j][i] = min(sparse_table[j][i - 1], sparse_table[j + (1 << (i - 1))][i - 1]);
        }
    }

    int l, r;
    while (m--) {
        cin >> l >> r;
        cout << find_min(l, r) << endl;
    }


    return 0;
}
