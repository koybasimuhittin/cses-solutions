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

bool isValidCoordinate(int row, int col) {
    return row >= 0 && row < N && col >= 0 && col < N;
}

vector<string> gridWithNewQueen(int row, int col, vector<string> grid) {
    int drow[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
    int dcol[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
    grid[row][col] = '*';

    for (int i = 0; i < 8; i++) {
        for (int j = 1; j < N; j++) {
            int nrow = drow[i] * j + row;
            int ncol = dcol[i] * j + col;
            if (isValidCoordinate(nrow, ncol)) {
                grid[nrow][ncol] = '*';
            }
        }
    }

    return grid;
}

int solve(int row, vector<string> grid) {
    if (row == N) {
        return 1;
    }

    int ans = 0;
    for (int col = 0; col < N; col++) {
        if (grid[row][col] == '.') {
            ans += solve(row + 1, gridWithNewQueen(row, col, grid));
        }
    }

    return ans;

}

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> grid(N);

    for (int i = 0; i < N; i++) {
        cin >> grid[i];
    }


    cout << solve(0, grid) << endl;




    return 0;
}
