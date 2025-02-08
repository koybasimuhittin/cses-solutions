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

int n, m, arr[N], fenwick[N];

void update(int idx, int delta) {
    for (; idx < n; idx |= (idx + 1)) {
        fenwick[idx] += delta;
    }
}

int get(int pos) {
    int sum = 0;
    for (; pos >= 0; pos = (pos & (pos + 1)) - 1) {
        sum += fenwick[pos];
    }

    return sum;
}

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        update(i, arr[i]);
    }

    int q, l, r;

    while (m--) {
        cin >> q >> l >> r;
        l--;
        if (q == 1) {
            update(l, r - arr[l]);
            arr[l] = r;
        }
        else {
            cout << get(r - 1) - get(l - 1) << endl;
        }
    }


    return 0;
}
