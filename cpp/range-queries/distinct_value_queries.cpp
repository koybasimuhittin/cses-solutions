#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define f1 first
#define s2 second
#define pb push_back
#define mp make_pair
#define fri(a) freopen(a, "r", stdin);
#define fro(a) freopen(a, "w", stdout);
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;
int SQRT = 450;

struct Query {
    int index, l, r, block;
    bool operator<(const Query& other) const {
        if (block != other.block) return block < other.block;
        return (block & 1) ? (r > other.r) : (r < other.r);
    }
};

int n, m, t, arr[N], ans[N], cnt[N];
Query queries[N];

int main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> n >> m;
    SQRT = max(1, int(n / sqrt(m)));

    for (int i = 0;i < n;i++) cin >> arr[i];

    vector<int> vals(arr, arr + n);
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    for (int i = 0;i < n;i++) {
        arr[i] = lower_bound(vals.begin(), vals.end(), arr[i]) - vals.begin();
    }

    int l, r;
    for (int i = 0;i < m;i++) {
        cin >> l >> r; l--; r--;
        queries[i] = { i, l, r, l / SQRT };
    }

    sort(queries, queries + m);
    int curL = 0, curR = -1, curAns = 0;

    for (int i = 0;i < m;i++) {
        Query& q = queries[i];
        while (curL > q.l) {
            curL--;
            if (cnt[arr[curL]]++ == 0) curAns++;
        }
        while (curR < q.r) {
            curR++;
            if (cnt[arr[curR]]++ == 0) curAns++;
        }
        while (curL < q.l) {
            if (--cnt[arr[curL]] == 0) curAns--;
            curL++;
        }
        while (curR > q.r) {
            if (--cnt[arr[curR]] == 0) curAns--;
            curR--;
        }
        ans[q.index] = curAns;
    }

    for (int i = 0;i < m;i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
