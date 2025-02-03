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

int n, m, dist[N][N];
vector<pair<int, int>> monsters;
pair<int, int> start;
pair<int, int> a, b, parent[N][N];
pair<int, int> ending = { -1LL, -1LL };

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

void calc_distances() {
    queue<pair<int, int>> q;
    for (auto monster : monsters) {
        q.push(monster);
    }

    while (!q.empty()) {
        pair<int, int> node = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            if (is_valid_coordinate(node.f1 + dr[i], node.s2 + dc[i]) && dist[node.f1 + dr[i]][node.s2 + dc[i]] == INT_MAX) {
                dist[node.f1 + dr[i]][node.s2 + dc[i]] = dist[node.f1][node.s2] + 1;
                q.push({ node.f1 + dr[i], node.s2 + dc[i] });
            }
        }
    }
}

vector<char> solve() {
    vector<char> path;
    queue<pair<int, int>> q;
    q.push(start);
    dist[start.f1][start.s2] = 0;
    parent[start.f1][start.s2] = start;

    while (!q.empty()) {
        pair<int, int> node = q.front();
        q.pop();

        if (node.f1 == 0 || node.f1 == n - 1 || node.s2 == 0 || node.s2 == m - 1) {
            ending = node;
            break;
        }

        for (int i = 0; i < 4; i++) {
            if (is_valid_coordinate(node.f1 + dr[i], node.s2 + dc[i]) && dist[node.f1 + dr[i]][node.s2 + dc[i]] > dist[node.f1][node.s2] + 1) {
                dist[node.f1 + dr[i]][node.s2 + dc[i]] = dist[node.f1][node.s2] + 1;
                parent[node.f1 + dr[i]][node.s2 + dc[i]] = node;
                q.push({ node.f1 + dr[i], node.s2 + dc[i] });
            }
        }
    }

    if (ending != mp(-1LL, -1LL)) {
        while (ending != parent[ending.f1][ending.s2]) {
            path.pb(direction(parent[ending.f1][ending.s2], ending));
            ending = parent[ending.f1][ending.s2];
        }
    }

    reverse(path.begin(), path.end());

    return path;
}

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dist[i][j] = INT_MAX;
        }
    }

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < m; j++) {
            if (s[j] == 'M') {
                dist[i][j] = 0;
                monsters.pb({ i, j });
            }

            else if (s[j] == '#') {
                dist[i][j] = -1;
            }
            else if (s[j] == 'A') {
                start = { i, j };
            }
        }
    }

    calc_distances();

    vector<char> path = solve();

    if (ending != mp(-1LL, -1LL)) {
        cout << "YES" << endl << path.size() << endl;

        for (auto e : path) {
            cout << e;
        }
        cout << endl;
    }
    else {
        cout << "NO" << endl;
    }


    return 0;
}
