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
const int M = 32;

int n, x, basis[M];

void insert_into_basis(int x) {
    for (int i = 0; i < M; i++) {
        if ((x & (1LL << i)) != 0) {
            if (basis[i] == 0) {
                basis[i] = x;
                return;
            }
            x ^= basis[i];
        }
    }
}

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        insert_into_basis(x);
    }

    int cnt = 1;
    for (int i = 0; i < M; i++) {
        if (basis[i])cnt *= 2;
    }

    cout << cnt << endl;


    return 0;
}
