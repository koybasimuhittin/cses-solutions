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

int n, m, t, arr[N];
vector<int> v;

int twoKnights(int n) {
    if (n == 1) return 0;
    if (n == 2) return 6;
    if (n == 3) return 28;

    return (n * n) * (n * n - 1) / 2 - (8 + 24 + (4 * n - 12) * 4 + (n - 4) * 4 * 6 + (n - 4) * (n - 4) * 8) / 2;
}

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cout << twoKnights(i) << endl;
    }


    return 0;
}
