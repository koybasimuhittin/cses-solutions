#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define f1 first
#define s2 second
#define pb push_back
#define mp make_pair
#define fri(a) freopen(a,"r",stdin);
#define fro(a) freopen(a,"w",stdout);
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;

int n, m, arr[N];
map<int, vector<pair<int, int>>> nums;

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            nums[arr[i] + arr[j]].pb(mp(i, j));
        }
    }

    for (auto& num : nums) {
        if (nums.find(m - num.f1) != nums.end()) {
            for (auto& x : num.s2) {
                for (auto& y : nums[m - num.f1]) {
                    if (x.f1 != y.f1 && x.f1 != y.s2 && x.s2 != y.f1 && x.s2 != y.s2) {
                        cout << x.f1 + 1 << " " << x.s2 + 1 << " " << y.f1 + 1 << " " << y.s2 + 1 << endl;
                        return 0;
                    }
                }
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;


    return 0;
}
