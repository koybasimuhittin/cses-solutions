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

int n, sum;
vector<int> v;

int solve(int index, int curr) {
    if (index == n) {
        return abs(sum - curr - curr);
    }

    return min(solve(index + 1, curr + v[index]), solve(index + 1, curr));
}

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }

    cout << solve(0, 0) << endl;



    return 0;
}
