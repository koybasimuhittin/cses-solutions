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
const int N = 16;

int n, degree[1 << N], adj[1 << N][2];

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    memset(adj, -1, sizeof(adj));

    for (int i = 0; i < (1 << (n - 1)); i++) {
        int nxt0 = i << 1;
        nxt0 = nxt0 % (1 << (n - 1));
        int nxt1 = nxt0 + 1;

        adj[i][0] = nxt0;
        adj[i][1] = nxt1;
        degree[i] = 2;
    }

    stack<pair<int, int>> st;
    st.push({ 0, -1 });

    while (!st.empty()) {
        auto [node, edge] = st.top();

        if (degree[node] == 0) {
            if (edge != -1) {
                cout << edge;
            }
            else {
                for (int i = 0; i < n - 1; i++) {
                    cout << 0;
                }
            }
            st.pop();
            continue;
        }

        st.push({ adj[node][2 - degree[node]], 2 - degree[node] });
        degree[node]--;
    }

    return 0;
}
