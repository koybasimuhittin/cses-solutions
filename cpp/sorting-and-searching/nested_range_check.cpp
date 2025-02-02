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

typedef struct Range {
    int l, r, index;

    Range(int l, int r, int index) {
        this->l = l;
        this->r = r;
        this->index = index;
    }
} Range;

int n, l, r;
vector<Range> inputs;
bool ans[N][2];

bool comp(const Range& a, const Range& b) {
    if (a.l == b.l) {
        return a.r >= b.r;
    }

    return a.l < b.l;

}

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        inputs.pb(Range(l, r, i));
    }

    sort(inputs.begin(), inputs.end(), comp);

    multiset<int> ms;

    for (int i = 0; i < n; i++) {

        auto it = ms.lower_bound(inputs[i].r);
        if (it == ms.end()) {
            ms.insert(inputs[i].r);
            continue;
        }

        ans[inputs[i].index][1] = true;
        ms.insert(inputs[i].r);
    }

    ms.clear();

    ms.insert(inputs[n - 1].r);

    for (int i = n - 2; i >= 0; i--) {
        auto  it = ms.lower_bound(inputs[i].r);

        if (it == ms.begin() && *it > inputs[i].r) {
            ms.insert(inputs[i].r);
            continue;
        }

        ans[inputs[i].index][0] = true;
        ms.insert(inputs[i].r);
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i][0] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << ans[i][1] << " ";
    }
    cout << endl;


    return 0;
}
