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

int n, arr[N], cnt[N];
set<int> s;

int32_t main() {

    //cfri("in.txt");
    //cfro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n - 2; i++) {
        cin >> arr[i];
        cnt[arr[i]]++;
    }

    for (int i = 1; i <= n; i++) {
        if (cnt[i] == 0) s.insert(i);
    }
    cnt[arr[n - 3]]++;

    for (int i = 0; i < n - 2; i++) {
        cout << *s.begin() << " " << arr[i] << endl;
        s.erase(s.begin());
        cnt[arr[i]]--;
        if (cnt[arr[i]] == 0) {
            s.insert(arr[i]);
        }
    }
    cout << *s.begin() << " " << arr[n - 3] << endl;

    return 0;
}
