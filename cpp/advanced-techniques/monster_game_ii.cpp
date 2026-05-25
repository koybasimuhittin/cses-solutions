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
const int N = 1e6 + 5;
const int INF = 1e15;

class Line {
public:
    Line() {
        a = 0;
        b = INF;
    }
    Line(int _a, int _b) {
        a = _a;
        b = _b;
    }

    int at(int x) const {
        return a * x + b;
    }

    bool compare_at(const Line& other, int x) const {
        return at(x) < other.at(x);
    }
private:
    int a, b;
};

int n, m, s[N], f[N], dp[N];
Line lct[4 * N];

void add_line(int v, int tl, int tr, Line line) {
    int tm = (tl + tr) / 2;
    bool left = line.compare_at(lct[v], tl);
    bool mid = line.compare_at(lct[v], tm);
    if (mid) {
        swap(lct[v], line);
    }
    if (tr - tl <= 1) return;
    else if (left != mid) {
        add_line(v * 2, tl, tm, line);
    }
    else add_line(v * 2 + 1, tm, tr, line);
}

int get_min(int v, int tl, int tr, int x) {
    int tm = (tl + tr) / 2;
    if (tr - tl <= 1) return lct[v].at(x);
    if (x < tm) return min(lct[v].at(x), get_min(v * 2, tl, tm, x));
    return min(lct[v].at(x), get_min(v * 2 + 1, tm, tr, x));
}

int32_t main() {

    // fri("in.txt");
    // fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> f[i];
    }

    dp[n - 1] = 0;
    add_line(1, 0, N - 1, Line(s[n - 1], dp[n - 1]));
    for (int i = n - 2; i >= 0; i--) {
        dp[i] = get_min(1, 0, N - 1, f[i]);
        add_line(1, 0, N - 1, Line(s[i], dp[i]));
    }

    cout << get_min(1, 0, N, m) << endl;


    return 0;
}
