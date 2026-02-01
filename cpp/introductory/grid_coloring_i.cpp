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
const int N = 5e2 + 5;

int n, m, grid[N][N];

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            grid[i][j] = s[j] - 'A';
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((i + j) % 2 == 0) {
                if (grid[i][j] == 0) {
                    grid[i][j] = 2;
                }
                else {
                    grid[i][j] = 0;
                }
            }
            else {
                if (grid[i][j] == 1) {
                    grid[i][j] = 3;
                }
                else {
                    grid[i][j] = 1;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << (char)(grid[i][j] + 'A');
        }
        cout << endl;
    }




    return 0;
}
