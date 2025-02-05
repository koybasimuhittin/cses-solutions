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

int n, m, child[N], dist[N], parent[N], cycle_start, cycle_end;
bool visited[N];

void find_cycle(int u, int p) {
    visited[u] = true;
    parent[u] = p;

    int v = child[u];

    if (visited[v]) {
        if (dist[v] == 0) {
            cycle_start = v;
            cycle_end = u;
        }
    }
    else {
        find_cycle(v, u);
    }
}

void calc_dist(int u) {
    if (dist[u] != 0) return;

    int v = child[u];

    calc_dist(v);

    dist[u] = dist[v] + 1;
}

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> child[i];
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cycle_start = -1;
            cycle_end = -1;
            find_cycle(i, i);

            if (cycle_start != -1) {
                vector<int> cycle;
                while (cycle_start != cycle_end) {
                    cycle.pb(cycle_end);
                    cycle_end = parent[cycle_end];
                }
                cycle.pb(cycle_start);

                for (auto v : cycle) {
                    dist[v] = cycle.size();
                }
            }

            calc_dist(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;


    return 0;
}
