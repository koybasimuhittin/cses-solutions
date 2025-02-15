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
const int SQRT = 450;

typedef struct Query {
    int index, l, r, sqrt;

    bool operator<(const Query& other) const {
        if (other.sqrt == sqrt) {
            return l < other.l;
        }

        return sqrt < other.sqrt;
    }
} Query;

int n, m, t, arr[N], ans[N], cnt[N], res;
Query queries[N];
unordered_map<int, int> inverse;

int32_t main() {
    // fri("in.txt");
    // fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        inverse[arr[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = inverse[arr[i]];
    }

    int l, r;
    for (int i = 0; i < m; i++) {
        cin >> l >> r;
        l--;
        r--;
        queries[i] = {i, l, r, r / SQRT};
    }

    sort(queries, queries + m);

    for (int i = queries[0].l; i <= queries[0].r; i++) {
        if (cnt[arr[i]] == 0) {
            res++;
        }
        cnt[arr[i]]++;
    }
    ans[queries[0].index] = res;

    l = queries[0].l;
    r = queries[0].r;

    for (int i = 1; i < m; i++) {
        while (l < queries[i].l) {
            cnt[arr[l]]--;
            if (cnt[arr[l]] == 0) {
                res--;
            }
            l++;
        }

        while (l > queries[i].l) {
            l--;
            if (cnt[arr[l]] == 0) {
                res++;
            }
            cnt[arr[l]]++;
        }

        while (r < queries[i].r) {
            r++;
            if (cnt[arr[r]] == 0) {
                res++;
            }
            cnt[arr[r]]++;
        }

        while (r > queries[i].r) {
            cnt[arr[r]]--;
            if (cnt[arr[r]] == 0) {
                res--;
            }
            r--;
        }

        ans[queries[i].index] = res;
    }

    for (int i = 0; i < m; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
