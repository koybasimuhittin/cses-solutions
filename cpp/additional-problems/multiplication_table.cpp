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

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    int low = 0;
    int high = n * n + 1;

    while (low < high) {
        int mid = (low + high) / 2;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            cnt += min(mid / i, n);
        }
        if (cnt >= n * n / 2 + 1) {
            high = mid;
        }
        else {
            low = mid + 1;
        }
    }

    cout << low << endl;


    return 0;
}