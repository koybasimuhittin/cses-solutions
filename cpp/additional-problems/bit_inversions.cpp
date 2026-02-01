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

int n, q, l_arr[N], r_arr[N], seg[4 * N];
bool marked[4 * N];
string s;

void build(int v, int tl, int tr) {
    if (tl == tr) {
        seg[v] = arr[tl];
        return;
    }
    int tm = (tl + tr) >> 1;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);

    seg[v] = max(seg[v * 2], seg[v * 2 + 1]);
}

void push(int v) {
    if (marked[v]) {
        seg[v * 2] = seg[v * 2 + 1] = seg[v];
        marked[v * 2] = marked[v * 2 + 1] = true;
        marked[v] = false;
    }
}

void update(int v, int tl, int tr, int l, int r, int val) {
    if (l > r) return;
    if (l == tl && r == tr) {
        seg[v] = val;
        marked[v] = true;
        return;
    }
    push(v);
    int tm = (tl + tr) >> 1;
    update(v * 2, tl, tm, l, min(r, tm), val);
    update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
    seg[v] = max(seg[v * 2], seg[v * 2 + 1]);
}

int get(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (l == tl && r == tr) {
        return seg[v];
    }
    push(v);
    int tm = (tl + tr) >> 1;
    return max(get(v * 2, tl, tm, l, min(r, tm)),
        get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}


int32_t main() {

    fri("in.txt");
    fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    cin >> q;

    n = s.size();

    int cnt = 1;
    int l = 0;
    for (int i = 1;i < n; i++) {
        if (s[i] != s[i - 1]) {
            for (int j = l; j < i; j++) {
                arr[j] = cnt;
            }
            l = i;
            cnt = 0;
        }
        cnt++;
    }
    for (int j = l; j < n; j++) {
        arr[j] = cnt;
    }

    build(1, 0, n - 1);
    while (q--) {
        cin >> l;
        l--;
        if (n == 1) {
            cout << 1 << " ";
            continue;
        }

        if (l == 0) {
            if (s[l + 1] != s[l]) {

            }
        }
    }


    return 0;
}
