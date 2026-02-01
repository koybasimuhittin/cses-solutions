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

int n, m, outgoing[N];
vector<int> adj[N];
set<int> s;


int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[b].pb(a);
        outgoing[a]++;
    }

    for (int i = 1; i <= n; i++) {
        if (outgoing[i] == 0)s.insert(i);
    }
    vector<int> res;

    for (int i = 0; i < n; i++) {
        int node = *s.rbegin();
        res.pb(node);
        s.erase(prev(s.end()));
        for (auto child : adj[node]) {
            outgoing[child]--;
            if (outgoing[child] == 0) {
                s.insert(child);
            }
        }
    }
    reverse(res.begin(), res.end());
    for (auto node : res) {
        cout << node << " ";
    }
    return 0;
}
