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

int n, subtree_size[N];
vector<int> adj[N];

void calc_subtree_size(int node, int parent) {
    for (auto child : adj[node]) {
        if (child == parent) continue;
        calc_subtree_size(child, node);
        subtree_size[node] += subtree_size[child];
    }

    subtree_size[node]++;
}

int find_centroid(int node, int parent) {
    for (auto child : adj[node]) {
        if (child == parent)continue;
        if (subtree_size[child] > n / 2) {
            return find_centroid(child, node);
        }
    }

    return node;
}

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    int a, b;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    calc_subtree_size(1, 0);

    cout << find_centroid(1, 0) << endl;


    return 0;
}
