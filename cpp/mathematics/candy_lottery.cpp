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

double n, m;

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    double res = 0;
    for (int i = 1; i <= m; i++) {
        res += (pow((double)i, n) - pow((double)(i - 1), n)) * i / pow(m, n);
    }

    cout << fixed << setprecision(6) << res << endl;


    return 0;
}
