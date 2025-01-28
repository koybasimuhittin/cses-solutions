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

void solve(int from, int to, int num) {
    if (num == 0) {
        return;
    }
    solve(from, 6 - (from + to), num - 1);
    cout << from << " " << to << endl;
    solve(6 - (from + to), to, num - 1);
}

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    cout << pow(2, n) - 1 << endl;
    solve(1, 3, n);


    return 0;
}
