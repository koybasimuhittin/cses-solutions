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
map<int, vector<int>> nums;

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        nums[arr[i]].pb(i);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums.find(m - arr[i] - arr[j]) != nums.end()) {
                for (auto& e : nums[m - arr[i] - arr[j]]) {
                    if (e != i && e != j) {
                        cout << i + 1 << " " << j + 1 << " " << e + 1 << endl;
                        return 0;
                    }
                }
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;


    return 0;
}
