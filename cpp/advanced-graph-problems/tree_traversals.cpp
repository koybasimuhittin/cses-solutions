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

int n, preorder[N], inv_preorder[N], inorder[N], inv_inorder[N], arr[N], seg[4 * N];;
vector<int> adj[N];

void build(int v, int tl, int tr) {
    if (tl == tr) {
        seg[v] = arr[tl];
        return;
    }
    int tm = (tl + tr) >> 1;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    seg[v] = min(seg[v * 2], seg[v * 2 + 1]);
}

int get(int v, int tl, int tr, int l, int r) {
    if (l > r)return INT_MAX;
    if (tl == l && tr == r) {
        return seg[v];
    }
    int tm = (tl + tr) >> 1;

    return min(get(v * 2, tl, tm, l, min(r, tm)), get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

int solve(int l, int r) {
    if (l > r) return -1;
    if (l == r) return inorder[l];

    int pre_idx = get(1, 0, n - 1, l, r);
    int node = preorder[pre_idx];
    int in_idx = inv_inorder[node];

    int left_node = solve(l, in_idx - 1);
    int right_node = solve(in_idx + 1, r);

    if (left_node != -1) {
        adj[node].pb(left_node);
    }
    if (right_node != -1) {
        adj[node].pb(right_node);
    }

    return node;
}

void traverse_postorder(int node) {
    for (auto child : adj[node]) {
        traverse_postorder(child);
    }
    cout << node + 1 << " ";
}

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> preorder[i];
        preorder[i]--;
        inv_preorder[preorder[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
        inorder[i]--;
        inv_inorder[inorder[i]] = i;
        arr[i] = inv_preorder[inorder[i]];
    }


    build(1, 0, n - 1);
    int root = solve(0, n - 1);
    traverse_postorder(root);

    return 0;
}
