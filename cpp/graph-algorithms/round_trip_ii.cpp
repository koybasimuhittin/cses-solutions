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
const int N = 1e5 + 5;

int n, m, parent[N];
vector<int> graph[N];
bool is_in_stack[N];
int ending = -1;

void dfs(int node) {
    is_in_stack[node] = true;

    for (auto neighbour : graph[node]) {
        if (ending != -1) return;
        if (is_in_stack[neighbour]) {
            ending = node;
            parent[neighbour] = neighbour;
            return;
        }
        if (parent[neighbour] == 0) {
            parent[neighbour] = node;
            dfs(neighbour);
        }
    }

    is_in_stack[node] = false;
}

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].pb(b);
    }

    for (int i = 1; i <= n && ending == -1; i++) {
        if (parent[i] == 0) {
            parent[i] = i;
            dfs(i);
        }
    }

    if (ending != -1) {
        vector<int> ans;
        int temp = ending;

        while (parent[temp] != temp) {
            ans.pb(temp);
            temp = parent[temp];
        }

        ans.pb(temp);
        ans.pb(ending);

        cout << ans.size() << endl;

        reverse(ans.begin(), ans.end());
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << endl;
    }

    else {
        cout << "IMPOSSIBLE" << endl;
    }



    return 0;
}
