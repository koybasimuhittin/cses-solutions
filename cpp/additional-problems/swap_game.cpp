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
const int N = 3;
const int dr[] = { 0, 1 };
const int dc[] = { 1, 0 };

unordered_map<string, bool> visited;

bool is_valid_coordinate(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < N;
}


int calc_dist(string start) {
    string target = "123456789";

    queue<pair<string, int>> q;
    q.push({ start, 0 });
    visited[start] = true;

    while (!q.empty()) {
        auto [node, dist] = q.front();
        q.pop();

        if (node == target) {
            return dist;
        }
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                for (int i = 0; i < 2; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if (!is_valid_coordinate(nr, nc))continue;
                    string temp = node;
                    int idx_s = N * r + c;
                    int idx_t = N * nr + nc;
                    temp[idx_t] = node[idx_s];
                    temp[idx_s] = node[idx_t];
                    if (visited[temp]) continue;
                    q.push({ temp, dist + 1 });
                    visited[temp] = true;
                }
            }
        }
    }

    return -1;

}

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s = "";
    int a;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a;
            s += (char)(a + '0');
        }
    }

    cout << calc_dist(s);

    return 0;
}
