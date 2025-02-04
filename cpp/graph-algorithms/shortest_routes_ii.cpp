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
const int INF = 5e11 + 5;

int n, m, q, dist[N][N];
vector<int> v;

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> q;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            dist[i][j] = INF;
        }
    }

    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        dist[a][b] = min(c, dist[a][b]);
        dist[b][a] = min(c, dist[b][a]);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }

    for (int i = 0; i < q; i++) {
        cin >> a >> b;

        if (dist[a][b] >= INF) {
            cout << -1 << endl;
        }
        else {
            cout << dist[a][b] << endl;
        }
    }


    return 0;
}
