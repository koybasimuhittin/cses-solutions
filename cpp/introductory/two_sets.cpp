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
vector<int> v1, v2;

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> n;

    if (((n * (n + 1)) & 3)) {
        cout << "NO" << endl;
    }
    else {
        int curr = (n * (n + 1)) / 4;
        for (int i = n; i > 0; i--) {
            if (curr >= i) {
                curr -= i;
                v1.pb(i);
            }
            else {
                v2.pb(i);
            }
        }

        cout << "YES" << endl;
        cout << v1.size() << endl;
        for (auto& e : v1) cout << e << " ";
        cout << endl << v2.size() << endl;
        for (auto& e : v2) cout << e << " ";
        cout << endl;

    }





    return 0;
}
