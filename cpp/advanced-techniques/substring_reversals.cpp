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

struct TreapNode {
    TreapNode* l, * r;
    int key, priority, cnt;
    char val;
    bool reversed = false;
    TreapNode(int key, char val) : key(key), val(val), priority(rand()), l(NULL), r(NULL) {}
};

typedef TreapNode* PTreapNode;

int get_cnt(PTreapNode& root) {
    if (!root) return 0;
    return root->cnt;
}

void update_cnt(PTreapNode& root) {
    if (root) root->cnt = get_cnt(root->l) + 1 + get_cnt(root->r);
}

void push(PTreapNode& node) {
    if (node && node->reversed) {
        node->reversed = false;
        swap(node->l, node->r);
        if (node->l)node->l->reversed ^= 1;
        if (node->r)node->r->reversed ^= 1;
    }
}

void merge(PTreapNode& root, PTreapNode l, PTreapNode r) {
    push(l);
    push(r);
    if (!l)root = r;
    else if (!r) root = l;
    else if (l->priority >= r->priority) {
        merge(l->r, l->r, r); root = l;
    }
    else {
        merge(r->l, l, r->l); root = r;
    }
    update_cnt(root);
}

void split(PTreapNode root, PTreapNode& l, PTreapNode& r, int key) {
    if (!root) {
        l = r = NULL;
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
    update_cnt(root);
}

void reverse(PTreapNode& root, int l, int r) {
    PTreapNode t1, t2, t3;
    split(root, t2, t3, r);
    split(t2, t1, t2, l - 1);
    t2->reversed ^= 1;
    merge(root, t1, t2);
    merge(root, root, t3);
}

void output(PTreapNode& root) {
    if (!root)return;
    push(root);
    output(root->l);
    cout << root->val;
    output(root->r);
}

int n, m;
string s;

PTreapNode root = NULL;

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> s;

    for (int i = 1; i <= n; i++) {
        PTreapNode node = new TreapNode(i, s[i - 1]);
        merge(root, root, node);
    }
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        reverse(root, a, b);
    }
    output(root);


    return 0;
}
