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

struct Node {
    Node* l, * r;
    int key, priority, val, sum, cnt;
    bool reversed = false;
    Node(int key, int val) : key(key), priority(rand()), val(val), sum(val), l(NULL), r(NULL) {};
};

typedef Node* PNode;

int get_cnt(PNode& node) {
    if (!node)return 0;
    return node->cnt;
}

int get_sum(PNode& node) {
    if (!node) return 0;
    return node->sum;
}

void update(PNode& node) {
    if (node) {
        node->cnt = get_cnt(node->l) + 1 + get_cnt(node->r);
        node->sum = get_sum(node->l) + node->val + get_sum(node->r);
    }
}

void push(PNode& node) {
    if (node && node->reversed) {
        node->reversed = false;
        swap(node->l, node->r);
        if (node->l) node->l->reversed ^= 1;
        if (node->r) node->r->reversed ^= 1;
    }
}

void merge(PNode& root, PNode l, PNode r) {
    push(l);
    push(r);
    if (!l) root = r;
    else if (!r) root = l;
    else if (l->priority > r->priority) {
        merge(l->r, l->r, r);
        root = l;
    }
    else {
        merge(r->l, l, r->l);
        root = r;
    }
    update(root);
}

void split(PNode root, PNode& l, PNode& r, int key) {
    if (!root) {
        l = NULL;
        r = NULL;
        return;
    }
    push(root);
    int left_cnt = get_cnt(root->l);
    if (key > left_cnt) {
        split(root->r, root->r, r, key - left_cnt - 1);
        l = root;
    }
    else {
        split(root->l, l, root->l, key);
        r = root;
    }
    update(root);
}

void reverse(PNode& root, int l, int r) {
    PNode t1, t2, t3;
    split(root, t2, t3, r);
    split(t2, t1, t2, l - 1);
    t2->reversed ^= 1;
    merge(root, t1, t2);
    merge(root, root, t3);
}

int get_sum(PNode& root, int l, int r) {
    int sum = 0;
    PNode t1, t2, t3;
    split(root, t2, t3, r);
    split(t2, t1, t2, l - 1);
    sum = get_sum(t2);
    merge(root, t1, t2);
    merge(root, root, t3);

    return sum;
}

int n, m;
PNode root = NULL;

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int t, a, b;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        PNode node = new Node(i, a);
        merge(root, root, node);
    }

    for (int i = 0; i < m; i++) {
        cin >> t >> a >> b;
        if (t == 2) {
            cout << get_sum(root, a, b) << endl;
        }
        else {
            reverse(root, a, b);
        }
    }


    return 0;
}
