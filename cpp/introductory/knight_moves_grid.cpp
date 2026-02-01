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

int n, grid[N][N];

int dr[] = { -2, -2, -1, 1, 2, 2, 1, -1 };
int dc[] = { -1, 1, 2, 2, 1, -1, -2, -2 };

bool is_valid_coordinate(int r, int c) {
    return r >= 0 && c >= 0 && r < n && c < n;
}

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    memset(grid, -1, sizeof(grid));
    queue<pair<int, int>> q;
    q.push({ 0, 0 });
    grid[0][0] = 0;

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (is_valid_coordinate(nr, nc) && grid[nr][nc] == -1) {
                grid[nr][nc] = grid[r][c] + 1;
                q.push({ nr, nc });
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}
