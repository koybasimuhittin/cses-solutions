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
const int N = 20;

int n, c, m, t, fact[N];
vector<int> v;

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = fact[i - 1] * i;
    }

    cin >> t;

    while (t--) {
        cin >> c >> n;
        if (c == 1) {
            cin >> m;
            vector<bool> used(n + 1);
            for (int i = n - 1; i >= 0; i--) {
                int j = 1;
                for (j; j <= n; j++) {
                    if (used[j])continue;
                    if (m > fact[i]) {
                        m -= fact[i];
                    }
                    else break;
                }
                used[j] = true;
                cout << j << " ";
            }
            cout << endl;
        }
        else {
            vector<bool> used(n + 1);
            m = 1;
            for (int i = n - 1; i >= 0; i--) {
                int cnt = 0;
                cin >> c;
                for (int j = 1; j < c; j++) {
                    cnt += !used[j];
                }
                m += fact[i] * cnt;
                used[c] = true;
            }
            cout << m << endl;
        }


    }


    return 0;
}
