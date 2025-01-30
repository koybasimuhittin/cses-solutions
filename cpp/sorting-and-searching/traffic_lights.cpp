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

int n, m, arr[N];
set<int> lights;
multiset<int> distances;

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    lights.insert(0);
    lights.insert(n);
    distances.insert(n);

    for (int i = 0; i < m; i++) {
        cin >> arr[i];
        int low = *(--lights.upper_bound(arr[i]));
        int high = *(lights.upper_bound(arr[i]));
        lights.insert(arr[i]);

        distances.erase(distances.find(high - low));
        distances.insert(high - arr[i]);
        distances.insert(arr[i] - low);

        cout << *(--distances.end()) << " ";
    }

    cout << endl;


    return 0;
}
