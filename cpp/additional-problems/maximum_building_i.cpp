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
const int N = 1e3 + 5;

int n, m, cnt[N], p[N], sz[N];
vector<int> positons[N];

int find(int a) {
    return (p[a] == a ? a : find(p[a]));
}

int merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (sz[a] < sz[b]) {
        swap(a, b);
    }
    sz[a] += sz[b];
    p[b] = a;

    return sz[a];
}

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == '*')positons[i].pb(j);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int r = i; r < n; r++) {
            for (auto& c : positons[r]) {
                cnt[c]++;
            }
        }

        int mx = 0;

        for (int c = 0; c < m; c++) {
            p[c] = c;
            sz[c] = 1;
            if (cnt[c] == 0) mx = 1;
        }

        for (int c = 1; c < m; c++) {
            if (cnt[c] == 0 && cnt[c - 1] == 0) {
                mx = max(mx, merge(c, c - 1));
            }
        }

        for (int r = n - 1; r >= i; r--) {
            ans = max(ans, mx * (r - i + 1));
            for (auto& c : positons[r]) {
                cnt[c]--;
                if (cnt[c] == 0 && c - 1 >= 0 && cnt[c - 1] == 0) {
                    mx = max(mx, merge(c, c - 1));
                }
                if (cnt[c] == 0 && c + 1 < m && cnt[c + 1] == 0) {
                    mx = max(mx, merge(c, c + 1));
                }
            }
        }
    }

    cout << ans << endl;



    return 0;
}
