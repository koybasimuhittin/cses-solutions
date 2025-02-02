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

int n, m, a, b;
vector<pair<int, int>> v;
multiset<int> ms;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.s2 == b.s2) {
        return a.f1 < b.f1;
    }

    return a.s2 < b.s2;
}

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;

        v.pb(mp(a, b));
    }

    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < m; i++) {
        ms.insert(0);
    }

    int ans = 0;


    for (int i = 0; i < n; i++) {
        auto it = ms.lower_bound(v[i].f1);

        if (it == ms.begin()) {
            if (*it != v[i].f1) {
                continue;
            }
        }
        else {
            it--;
        }

        ans += 1;
        ms.erase(it);
        ms.insert(v[i].s2);
    }

    cout << ans << endl;



    return 0;
}
