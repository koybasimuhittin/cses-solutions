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

typedef struct TreapNode {
    int key, priority, cnt;
    TreapNode* l, * r;
    char value;
    TreapNode(int key, char value) : key(key), priority(rand()), value(value), l(NULL), r(NULL) {}
} TreapNode;

int get_cnt(TreapNode* node) {
    if (!node) return 0;
    return node->cnt;
}

void update_cnt(TreapNode* node) {
    node->cnt = get_cnt(node->l) + 1 + get_cnt(node->r);
}

void merge(TreapNode*& root, TreapNode* l, TreapNode* r) {
    if (!l) root = r;
    else if (!r) root = l;
    else if (l->priority >= r->priority) {
        merge(l->r, l->r, r), root = l;
    }
    else {
        merge(r->l, l, r->l), root = r;
    }
    update_cnt(root);
}

void split(TreapNode* root, TreapNode*& l, TreapNode*& r, int key) {
    if (!root) return void(l = r = 0);
    int left_size = get_cnt(root->l);
    if (key > left_size) {
        split(root->r, root->r, r, key - left_size - 1);
        l = root;
    }
    else {
        split(root->l, l, root->l, key);
        r = root;
    }
    update_cnt(root);
}

void print_treap(TreapNode*& root) {
    if (!root) return;
    print_treap(root->l);
    cout << root->value;
    print_treap(root->r);
}

void cut_and_paste(TreapNode*& root, int l, int r) {
    TreapNode* t1, * t2, * t3;
    split(root, t2, t3, r);
    split(t2, t1, t2, l - 1);
    merge(root, t1, t3);
    merge(root, root, t2);
}


int n, m;
string s;
TreapNode* root = NULL;

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    cin >> s;


    for (int i = 1; i <= n; i++) {
        TreapNode* node = new TreapNode(i, s[i - 1]);
        merge(root, root, node);
    }

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        TreapNode* t1, * t2, * t;
        cut_and_paste(root, a, b);
    }
    print_treap(root);


    return 0;
}
