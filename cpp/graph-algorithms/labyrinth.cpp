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

int n, m, dist[N][N];
bool visited[N][N];
pair<int, int> a, b, parent[N][N];

int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
char d[4] = { 'U', 'D', 'L', 'R' };

char direction(pair<int, int> from, pair<int, int> to) {
    for (int i = 0; i < 4; i++) {
        if (from.f1 + dr[i] == to.f1 && from.s2 + dc[i] == to.s2) {
            return d[i];
        }
    }
}

bool is_valid_coordinate(int row, int col) {
    return row >= 0 && row < n && col >= 0 && col < m;
}

void bfs(int* cnt, vector<char>& path) {
    queue<pair<int, int>> q;
    q.push(a);

    dist[a.f1][a.s2] = 0;
    visited[a.f1][a.s2] = true;
    parent[a.f1][a.s2] = a;
    parent[b.f1][b.s2] = b;

    while (!q.empty()) {
        pair<int, int> node = q.front();
        q.pop();

        if (node == b) {
            break;
        }

        for (int i = 0; i < 4; i++) {
            if (is_valid_coordinate(node.f1 + dr[i], node.s2 + dc[i]) && !visited[node.f1 + dr[i]][node.s2 + dc[i]]) {
                q.push({ node.f1 + dr[i], node.s2 + dc[i] });
                visited[node.f1 + dr[i]][node.s2 + dc[i]] = true;
                dist[node.f1 + dr[i]][node.s2 + dc[i]] = dist[node.f1][node.s2] + 1;
                parent[node.f1 + dr[i]][node.s2 + dc[i]] = node;
            }
        }
    }

    *cnt = dist[b.f1][b.s2];

    while (b != parent[b.f1][b.s2]) {
        path.pb(direction(parent[b.f1][b.s2], b));
        b = parent[b.f1][b.s2];
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

            if (s[j] == 'A') {
                a = { i, j };
            }

            else if (s[j] == 'B') {
                b = { i, j };
            }
        }
    }

    int cnt;
    vector<char> path;

    bfs(&cnt, path);

    if (cnt == 0) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl << cnt << endl;
        reverse(path.begin(), path.end());

        for (auto dir : path) {
            cout << dir;
        }

        cout << endl;
    }


    return 0;
}
