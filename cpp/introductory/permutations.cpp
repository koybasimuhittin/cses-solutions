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
vector<int> v;

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    if (n <= 3 && n >= 2) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    for (int i = 2; i <= n; i += 2) {
        cout << i << " ";
    }

    for (int i = 1; i <= n; i += 2) {
        cout << i << " ";
    }
    cout << endl;


    return 0;
}
