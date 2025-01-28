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

int n;

int fpow(int a, int b) {
    if (b == 0) return 1;

    int x = fpow(a, b / 2) % MOD;
    return (b & 1) ? (((x * x) % MOD) * a) % MOD : (x * x) % MOD;
}

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    cout << fpow(2, n) << endl;


    return 0;
}
