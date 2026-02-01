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

int n, m, grundy[N];

int calc(int x) {
    if (x == 1) return 0;
    if (x == 2) return 0;
    if (grundy[x] != -1) return grundy[x];

    vector<int> v;
    for (int i = 1; i < x / 2; i++) {
        v.pb(calc(i) ^ calc(x - i));
    }
    v.resize(distance(unique(v.begin(), v.end()), v.begin()));
    sort(v.begin(), v.end());
    int mex = 0;
    for (auto m : v) {
        if (m == mex)mex++;
    }

    return grundy[x] = mex;
}

int32_t main() {

    fri("in.txt");
    fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    memset(grundy, -1, sizeof(grundy));

    calc(1000);

    for (int i = 1; i <= 1000; i++) {
        cout << i << " " << grundy[i] << endl;
    }


    return 0;
}
