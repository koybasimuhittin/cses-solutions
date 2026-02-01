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
const int N = 105;

int n;
bool mex[2][N][2 * N];

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k <= 2 * n; k++) {
                if (mex[0][i][k] == false && mex[1][j][k] == false) {
                    cout << k << " ";
                    mex[0][i][k] = mex[1][j][k] = true;
                    break;
                }
            }
        }
        cout << endl;
    }


    return 0;
}
