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
const int N = 3e3 + 5;
const int M = 1e5;
const int INF = 1e15;

class Line {
public:
    Line(const int _a, const int _b) : a(_a), b(_b) {}
    Line() {
        a = 0;
        b = INF;
    }
    int get_at(const int x) {
        return a * x + b;
    }
    bool compare_at(Line line, const int x) {
        return get_at(x) <= line.get_at(x);
    }
private:
    int a, b;
};

class LiChaoTree {
public:
    struct Node {
        Line line;
        Node* left = nullptr;
        Node* right = nullptr;
        Node(Line _line) : line(_line) {};
    };

    LiChaoTree(int _l, int _r) {
        l = _l;
        r = _r;
        root = nullptr;
    }

    void clear(Node* node) {
        if (!node) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }

    ~LiChaoTree() { clear(root); }

    void reset() { clear(root); root = nullptr; }

    void add_line(Line line) {
        add_line(root, l, r, line);
    }
    int query(int x) {
        return query(root, l, r, x);
    }

private:
    Node* root;
    int l, r;

    static inline void ensure(Node*& node) {
        if (!node) node = new Node(Line());
    }

    void add_line(Node*& node, int tl, int tr, Line line) {
        ensure(node);
        int tm = (tl + tr) / 2;
        bool left = line.compare_at(node->line, tl);
        bool mid = line.compare_at(node->line, tm);

        if (mid)swap(line, node->line);
        if (tr - tl <= 1) return;
        if (left != mid)add_line(node->left, tl, tm, line);
        else add_line(node->right, tm, tr, line);
    }

    int query(Node*& node, int tl, int tr, int x) {
        if (!node) return INF;
        if (tr - tl <= 1) {
            return node->line.get_at(x);
        }
        int tm = (tl + tr) / 2;
        if (x < tm)return min(node->line.get_at(x), query(node->left, tl, tm, x));
        else return min(node->line.get_at(x), query(node->right, tm, tr, x));
    }

};

int n, k, t, arr[N], pref[N];

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        pref[i] = pref[i - 1] + arr[i];
    }

    LiChaoTree lct(0, pref[n]);

    vector<int> dp_prev(n + 1, INF), dp_cur(n + 1, INF);
    dp_prev[0] = 0;

    for (int j = 1; j <= k; j++) {

        fill(dp_cur.begin(), dp_cur.end(), INF);

        LiChaoTree lct(0, pref[n]);
        lct.add_line(Line(-2 * pref[0], dp_prev[0] + pref[0] * pref[0]));

        for (int i = 1; i <= n; i++) {
            dp_cur[i] = pref[i] * pref[i] + lct.query(pref[i]);
            if (dp_prev[i] < INF / 2) {
                lct.add_line(Line(-2 * pref[i], dp_prev[i] + pref[i] * pref[i]));
            }
        }
        dp_prev.swap(dp_cur);
    }
    cout << dp_prev[n] << endl;
    return 0;
}
