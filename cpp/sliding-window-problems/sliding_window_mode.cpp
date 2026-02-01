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

int n, k, arr[N];
map<int, int> cnt;

bool cmp(const pair<int, int>& x, const pair<int, int>& y) {
    if (x.f1 == y.f1) {
        return x.s2 < y.s2;
    }
    return x.f1 > y.f1;
}

set<pair<int, int>, bool (*)(const pair<int, int>&, const pair<int, int>&)> s(cmp);

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> n >> k;

    int res = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        s.erase({ cnt[arr[i]], arr[i] });
        cnt[arr[i]]++;
        s.insert({ cnt[arr[i]], arr[i] });
        if (i > k) {
            s.erase({ cnt[arr[i - k]], arr[i - k] });
            cnt[arr[i - k]]--;
            s.insert({ cnt[arr[i - k]], arr[i - k] });
        }
        if (i >= k)cout << (*s.begin()).s2 << " ";
    }


    return 0;
}
