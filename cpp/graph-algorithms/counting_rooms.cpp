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
const int N = 1e3 + 5;

int n, m;
bool visited[N][N];

int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

bool is_valid_coordinate(int row, int col) {
    return row >= 0 && row < n && col >= 0 && col < m;
}

void dfs(int row, int col) {
    visited[row][col] = true;

    for (int i = 0; i < 4; i++) {
        if (!visited[row + dr[i]][col + dc[i]] && is_valid_coordinate(row + dr[i], col + dc[i])) {
            dfs(row + dr[i], col + dc[i]);
        }
    }
}

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            visited[i][j] = (s[j] == '#');
        }
    }

    int ans = 0;

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            if (!visited[row][col]) {
                ans += 1;
                dfs(row, col);
            }
        }
    }

    cout << ans << endl;


    return 0;
}
