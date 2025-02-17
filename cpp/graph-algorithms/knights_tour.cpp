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
const int N = 8;

int ans[N][N], row, col;

int dr[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dc[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

bool is_valid_coordinate(int row, int col) {
    return row >= 0 && col >= 0 && row < N && col < N;
}

int find_possible_moves(int row, int col) {
    if (!is_valid_coordinate(row, col) || ans[row][col]) {
        return 10;
    }
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        int nr = row + dr[i];
        int nc = col + dc[i];
        if (is_valid_coordinate(nr, nc) && ans[nr][nc] == 0) {
            cnt++;
        }
    }

    return cnt;
}

void solve(int row, int col, int cnt) {
    ans[row][col] = cnt;

    int mini, mrow, mcol;
    mini = 10;

    for (int i = 0; i < 8; i++) {
        int nr = row + dr[i];
        int nc = col + dc[i];

        if (find_possible_moves(nr, nc) <= mini) {
            mini = find_possible_moves(nr, nc);
            mrow = nr;
            mcol = nc;
        }
    }

    if (mini == 10) return;

    solve(mrow, mcol, cnt + 1);
}


int32_t main() {

    //fro("out.txt");
    //fri("in.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> col >> row;
    col--, row--;

    solve(row, col, 1);


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
